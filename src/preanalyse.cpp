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
#include <preanalyse.h>

QStringList preAn()
{
    QStringList liste;
    QString nf = QFileDialog::getOpenFileName(0, "Fichier à analyser", "./");
    if (nf.isEmpty()) return liste;
    QFile f(nf);
    if (!f.open(QFile::ReadOnly))
        return liste;
    // chargement des 100000 premiers caractères
    QString txt;
    QTextStream flux(&f);
    while (!flux.atEnd() && txt.length() < 10000)
        txt.append(flux.readLine());
    int len = txt.length();
    // U > V
    if (!txt.contains('U') && txt.contains('V'))
        liste.append("U>V");
    // I > J
    if (!txt.contains('I') && txt.contains('J'))
        liste.append("I>J");
    // ae > e
    int ae = txt.count("ae");
    double aed = ae / len / 1.00;
    if (aed == 0) liste.append("ae>e+");
    else if (aed < 0.3) liste.append("ae>e");
    // h H
    if (!txt.contains(QRegExp("\\b[Hh]")))
        liste.append("h>-");
    // ph f
    if (!txt.contains("ph") && txt.contains("f"))
        liste.append("ph>f");
    // ci
    if (!txt.contains(QRegExp("ti[aeu]"))
        && txt.contains(QRegExp("ci[aeu]")))
        liste.append("ti>ci");
    // mn/mpn
    if (txt.contains("mpn"))
        liste.append("mn>mpn");
    // michi
    if (txt.contains(QRegExp("\\bmichi\\b")))
        liste.append("mihi>michi");
    return liste;
}

/*


#  mn/mpn
if re.search("mpn", texte):
    print "-mpn- (dampnum)"
else:
    print "pas de mn > mpn"

#  michi
if re.search(r"\bmichi\b", texte):
    print ("mihi > michi")
else:
    print ("mihi classique")
*/
