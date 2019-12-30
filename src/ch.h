/*       ch.h     */

#ifndef CH_H
#define CH_H

#include <QRegExp>
#include <QString>
#include <QStringList>

namespace Ch
{
    QStringList   ajoute(QString mot, QStringList liste);
    void          allonge(QString *f);
    QString       atone(const QString a, bool bdc = false);
    QString       communes(QString g);
    void          deQuant(QString *c);
	bool		  chaineMaj(QString s);
    QString       chemin(QString f, char t);
    QString const consonnes = "bcdfgjklmnpqrstvxz";
    void          genStrNum(const QString s, QString *ch, int *n);
    QString       deramise(QString r);
    QString       deAccent(QString c);
    QChar         der(QString s);
    void          elide(QString *mp);
    const         QRegExp reAlphas("(\\w+)");
    const         QRegExp reEspace("\\s+");
    const         QRegExp reLettres("\\w");
    const         QRegExp rePonct("([\\.?!;:])");
    // const QRegExp rePonct("([\\.?!;:]|$$)");
    bool          sort_i(const QString &a, const QString &b);
    bool          inv_sort_i(const QString &a, const QString &b);
    QString       versPC(QString k);
    QString       versPedeCerto(QString k);
    QString       const voyelles = "āăēĕīĭōŏūŭȳўĀĂĒĔĪĬŌŎŪŬȲЎ";

    //QChar const separSyll = 0x02CC;
    //QChar const separSyll = 0x00AD;
    QChar const   separSyll = 0x00B7;
    QString       transforme(QString k);
    QString       accentue(QString l);
    QString       ajoutSuff(QString fq, QString suffixe, QString l_etym, int accent);
}
#endif
