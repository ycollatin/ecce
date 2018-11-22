/*          preanalyse.cpp           */
/*

  recherche des paramètres graphiques à appliquer 
avant de lemmatiser un texte.

Format de sortie :
cha  : graphie classique
chb  : graphie non classique
chb+ : cette graphie est toujours utilisée, la graphie classique disparaît.


cha>chb
ou
cha>chb+

*/

#include <QFileDialog>
#include <QTextStream>

#include <mainwindow.h>

void MainWindow::preAn()
{
    QString nf = QFileDialog::getOpenFileName(0, "Fichier à analyser", "./");
    if (nf.isEmpty()) return;
    QFile f(nf);
    if (!f.open(QFile::ReadOnly))
        return;
    listeGr.clear();
    // chargement des 100000 premiers caractères
    QString txt;
    QTextStream flux(&f);
    while (!flux.atEnd())
        txt.append(flux.readLine());
    int len = txt.length();

    // U > V
    if (!txt.contains('U') && txt.contains('V'))
        listeGr.append("U>V");
    // I > J
    if (!txt.contains('I') && txt.contains('J'))
        listeGr.append("I>J");
    // ae > e
    int ae = txt.count("ae");
    if (ae == 0) listeGr.append("ae>e");
    else
    {
        double aed = ae / (len + 0.0);
        if (aed < 0.003) listeGr.append("ae;e");
    }

    // h H
    int nh = txt.count(QRegExp("\\b[Hh]"));
    if (nh == 0) listeGr.append("h>");
    else
    {
        double nhd = nh / (len+0.0);
        if (nhd < 0.003) listeGr.append("h;");
    }

    // ph f
    int nph = txt.count("ae");
    if (nph == 0) listeGr.append("ph>f");
    else
    {
        double phd = nph / (len+0.0);
        if (phd < 0.003) listeGr.append("ph;f");
    }

    // ci
    int nci = txt.count(QRegExp("ti[aeu]"));
    if (nci == 0) listeGr.append("ti>ci");
    else
    {
        double cid = nci / (len+0.0);
        if (cid < 0.003) listeGr.append("ti;ci");
            
    }

    // mn/mpn
    int nmpn = txt.count("mpn");
    if (nmpn == 0) listeGr.append("mn>mpn");
    else
    {
        double mpnd = nmpn / (len+0.0);
        if (mpnd == 0) listeGr.append("mn;mpn");
    }

    // michi
    int nmichi = txt.count(QRegExp("\\bmichi\\b"));
    int nmihi = txt.count(QRegExp("\\bmihi\\b"));
    if (nmichi > 0 && nmihi > 0) listeGr.append("mihi;michi");
    else if (nmihi == 0) listeGr.append("mihi>michi");

    qDebug()<<listeGr;
}

