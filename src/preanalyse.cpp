/*          preanalyse.cpp           */
/*

  recherche des paramètres graphiques à appliquer 
avant de lemmatiser un texte.

Format de sortie :
cha  : graphie classique
chb  : graphie non classique


cha;chb : les deux graphies sont utilisées
ou
cha>chb : la graphie classique cha disparaît au profit de chb.

Ajouter qu[aou] > c : antiquo > antico

*/

#include <QFileDialog>
#include <QTextStream>

#include <mainwindow.h>

void MainWindow::preAn()
{
    QString nf = QFileDialog::getOpenFileName(0, "Fichier à analyser", "./");
    if (nf.isEmpty()) return;
    QFile f(nf);
    if (!f.open(QFile::ReadOnly)) return;

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
    int nph = txt.count("ph");
    int nbf = txt.count("f");
    if (nph == 0 && nbf > 0) listeGr.append("ph>f");
    else
    {
        double phd = nph / (len+0.0);
        if (phd < 0.003) listeGr.append("ph;f");
    }

    // ci
    int nti = txt.count(QRegExp("ti[aeu]"));
    int nci = txt.count(QRegExp("ci[aeu]"));
    if (nti == 0 && nci > 0) 
        listeGr.append("ti>ci");
    else if (nti > 0 && nci > 0)
        listeGr.append("ti;ci");

    // mn/mpn
    int nmpn = txt.count(QRegExp("[aey]mpn"));
    int nmn = txt.count(QRegExp("[aey]mn"));
    if (nmn == 0 && nmpn > 0) listeGr.append("mn>mpn");
    else if (nmpn > 0) listeGr.append("mn;mpn");

    // michi
    int nmichi = txt.count(QRegExp("\\bmichi\\b"));
    int nmihi = txt.count(QRegExp("\\bmihi\\b"));
    if (nmichi > 0)
    {
        if (nmihi > 0) listeGr.append("mihi;michi");
        else if (nmihi == 0) listeGr.append("mihi>michi");
    }

    // vider les cases à cocher
    checkBoxAe->setChecked(false);
    checkBox_ae->setChecked(false);
    checkBox_H->setChecked(false);
    checkBox_h->setChecked(false);
    checkBox_Mihi->setChecked(false);
    checkBox_mihi->setChecked(false);
    checkBox_IJ->setChecked(false);
    checkBox_ij->setChecked(false);
    checkBox_UV->setChecked(false);
    checkBox_uv->setChecked(false);
    checkBox_TICI->setChecked(false);
    checkBox_tici->setChecked(false);
    checkBox_MPN->setChecked(false);
    checkBox_mpn->setChecked(false);
    checkBox_PH->setChecked(false);
    checkBox_ph->setChecked(false);
    // cocher
    for (int i=0;i<listeGr.count();++i)
    {
        QString lin = listeGr.at(i);
        if (lin.startsWith("ae"))
        {
            checkBoxAe->setChecked(true);
            if (lin.contains(">"))
                checkBox_ae->setChecked(true);
        }
        else if (lin.startsWith("h"))
        {
            checkBox_H->setChecked(true);
            if (lin.contains(">"))
                checkBox_h->setChecked(true);
        }
        else if (lin.startsWith("mihi"))
        {
            checkBox_Mihi->setChecked(true);
            if (lin.contains(">"))
                checkBox_mihi->setChecked(true);
        }
        else if (lin.startsWith("I"))
        {
            checkBox_IJ->setChecked(true);
            if (lin.contains(">"))
                checkBox_ij->setChecked(true);
        }
        else if (lin.startsWith("U"))
        {
            checkBox_UV->setChecked(true);
            if (lin.contains(">"))
                checkBox_uv->setChecked(true);
        }
        else if (lin.startsWith("ti"))
        {
            checkBox_TICI->setChecked(true);
            if (lin.contains(">"))
                checkBox_tici->setChecked(true);
        }
        else if (lin.startsWith("mn"))
        {
            checkBox_MPN->setChecked(true);
            if (lin.contains(">"))
                checkBox_mpn->setChecked(true);
        }
        else if (lin.startsWith("ph"))
        {
            checkBox_PH->setChecked(true);
            if (lin.contains(">"))
                checkBox_ph->setChecked(true);
        }
        else if (lin.startsWith("mihi"))
        {
            checkBox_Mihi->setChecked(true);
            if (lin.contains(">"))
                checkBox_mihi->setChecked(true);
        }
    }
    coche();
}

void MainWindow::coche()
{
    QString tv;
    plainTextEditVariantes->clear();
    if (checkBoxAe->isChecked())
    {
        tv.append("ae");
        if (checkBox_ae->isChecked())
            tv.append(">");
        else tv.append(";");
        tv.append("e\n");
    }
    if (checkBox_H->isChecked())
    {
        tv.append("h");
        if (checkBox_h->isChecked())
            tv.append(">\n");
        else tv.append(";\n");
    }
    if (checkBox_Mihi->isChecked())
    {
        tv.append("mihi");
        if (checkBox_mihi->isChecked())
            tv.append(">");
        else tv.append(";");
        tv.append("michi\n");
    }
    if (checkBox_IJ->isChecked())
    {
        tv.append("I");
        if (checkBox_ij->isChecked())
            tv.append(">");
        else tv.append(";");
        tv.append("J\n");
    }
    if (checkBox_UV->isChecked())
    {
        tv.append("U");
        if (checkBox_uv->isChecked())
            tv.append(">");
        else tv.append(";");
        tv.append("V\n");
    }
    if (checkBox_TICI->isChecked())
    {
        tv.append("ti");
        if (checkBox_tici->isChecked())
            tv.append(">");
        else tv.append(";");
        tv.append("ci\n");
    }
    if (checkBox_MPN->isChecked())
    {
        tv.append("mn");
        if (checkBox_mpn->isChecked())
            tv.append(">");
        else tv.append(";");
        tv.append("mpn\n");
    }
    if (checkBox_PH->isChecked())
    {
        tv.append("ph");
        if (checkBox_ph->isChecked())
            tv.append(">");
        else tv.append(";");
        tv.append("f\n");
    }
    plainTextEditVariantes->setPlainText(tv);
    enrVar();
    /*
    QFile f("data/vargraph.la");
    f.remove();
    f.open(QFile::WriteOnly);
    QTextStream flux(&f);
    flux << tv;
    f.close();
    */
}

void MainWindow::enrVar()
{
    QFile f("data/vargraph.la");
    f.remove();
    f.open(QFile::WriteOnly);
    QTextStream flux(&f);
    flux << docVarGraph;
    flux << plainTextEditVariantes->toPlainText();
    flux << plainTextEdit_AutresVar->toPlainText();
    f.close();
}
