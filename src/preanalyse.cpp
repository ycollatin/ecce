/*          preanalyse.cpp           */
/*

  Recherche des paramètres graphiques à appliquer 
avant de lemmatiser un texte.

Format de sortie :
cha  : graphie classique
chb  : graphie non classique


cha;chb : La transformation est appliquée sur les radicaux et désinences
          avant leur ajout aux listes.
cha>chb : La transformation est appliquée à la forme en cas d'échec pour
          tenter d'obtenir une graphie classique.

TODO
Ajouter qu[aou] > c : antiquo > antico
Ajouter y[:>]i
*/

#include <QFileDialog>
#include <QTextStream>

#include <mainwindow.h>

void MainWindow::preAn()
{
    if (fichier.isEmpty()) ouvrir();
    if (fichier.isEmpty()) return;
    QFile f(fichier);
    if (!f.open(QFile::ReadOnly)) return;

    listeGr.clear();
    QString txt;
    QTextStream flux(&f);
    while (!flux.atEnd())  // ajouter une limite ?
        txt.append(flux.readLine());
    f.close();

    int len = txt.length();
    // U > V
    checkBox_UV->setChecked(!txt.contains('U') && txt.contains('V'));
    // I > J
    checkBox_IJ->setChecked(!txt.contains('I') && txt.contains('J'));
    // ae > e
    int ae = txt.count(QRegExp("ee\\b"));
    checkBoxAe->setChecked(ae > 0);
    // h H
    int nh = txt.count(QRegExp("\\b[Hh]"));
    double nhd = nh / (len+0.0);
    checkBox_H->setChecked(nhd < 0.003);
    // ph f
    int nph = txt.count("ph");
    double phd = nph / (len+0.0);
    checkBox_PH->setChecked(phd < 0.003);
    // ci
    int nci = txt.count(QRegExp("(accio|[arpu]cione)"));
    checkBox_TICI->setChecked(nci > 0);
    // mn/mpn
    int nmpn = txt.count(QRegExp("[aey]mpn"));
    checkBox_MPN->setChecked(nmpn > 0);
    // michi
    int nmichi = txt.count(QRegExp("\\bmichi\\b"));
    checkBox_Mihi->setChecked(nmichi > 0);

    coche();
}

void MainWindow::coche()
{
    QString tv;
    plainTextEditVariantes->clear();
    if (checkBoxAe->isChecked())    tv.append("ae;e\n");
    if (checkBox_H->isChecked())    tv.append("h;\n");
    if (checkBox_Mihi->isChecked()) tv.append("mihi;michi\n");
    if (checkBox_IJ->isChecked())   tv.append("I;J\n");
    if (checkBox_UV->isChecked())   tv.append("U;V\n");
    if (checkBox_TICI->isChecked()) tv.append("([aeiourl])ci([aeiourl])>\\1ti\\2\n");
    if (checkBox_MPN->isChecked())  tv.append("mn;mpn\n");
    if (checkBox_PH->isChecked())   tv.append("ph;f\n");
    plainTextEditVariantes->setPlainText(tv);
}

void MainWindow::enrVar()
{
    QString nf = ajDir+"vargraph.la";
    QFile f(nf);
    f.remove();
    f.open(QFile::WriteOnly);
    QTextStream flux(&f);
    flux << docVarGraph;
    flux << plainTextEditVariantes->toPlainText();
    f.close();
    qApp->setOverrideCursor(QCursor(Qt::WaitCursor));
    lemcore->lisVarGraph();
    lemcore->lisModeles();
    lemcore->reinitRads();
    qApp->restoreOverrideCursor();
}

// fonction provisoire très fragile. À surveiller
void MainWindow::initCoches(QStringList lv)
{
    QString prim;
    for (int i=0;i<lv.count();++i)
        prim.append(lv.at(i).at(0));
    checkBoxAe->setChecked(prim.contains('a'));
    checkBox_H->setChecked(prim.contains('h'));
    checkBox_Mihi->setChecked(prim.contains("mi"));
    checkBox_IJ->setChecked(prim.contains('I'));
    checkBox_UV->setChecked(prim.contains('U'));
    checkBox_TICI->setChecked(prim.contains('('));
    checkBox_MPN->setChecked(prim.contains("mp"));
    checkBox_PH->setChecked(prim.contains('p'));
}
