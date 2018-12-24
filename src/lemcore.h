/*      lemcore.h
 *
 *  This file is part of COLLATINUS.
 *
 *  COLLATINUS is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  COLLATINVS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with COLLATINUS; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * © Yves Ouvrard, 2009 - 2016
 */

#ifndef LEMCORE_H
#define LEMCORE_H

#include <QMap>
#include <QString>
#include <QStringList>
#include <QtCore/QCoreApplication>
#include <QDir>
#include <QFile>
#include <QRegExp>
#include <QTextStream>
#include <iostream>

#include "ch.h"
#include "irregs.h"
#include "lemme.h"
#include "modele.h"
#include "reglevg.h"

class Irreg;
class Lemme;
class Radical;
class Desinence;

typedef struct
{
    QString grq;
    int morpho;
    QString sufq;
} SLem;

typedef QMap<Lemme*, QList<SLem> > MapLem;

typedef QPair<QRegExp, QString> Reglep;

class LemCore : public QObject
{
    Q_OBJECT

   private:
    // fonction d'initialisation
    void ajAssims();
    void ajAbrev();
    QStringList abr;
    // Pour avoir une liste d'abréviation éditable...
    void ajContractions();
    int  aRomano(QString f);
    void lisIrreguliers();
    void lisFichierLexique(QString filepath);
    void lisLexique();
    void lisExtension();
    void lisModeles();
    void lisMorphos(QString lang);
    void lisTraductions(bool base, bool extension);
    void lisTraductions(QString chemin);
    void lisVarGraph();
    QStringList _listeLemmesLa;
    // variables et utils
    QMap<QString, QString> assims;
    QMap<QString, QString> assimsq;
    QMap<QString, QString> _contractions;
    QMultiMap<QString, Desinence *> _desinences;
    QString decontracte(QString d);
    QMultiMap<QString, Irreg *> _irregs;
    QMap<QString, QString> _cibles;
    QMap<QString, Lemme *> _lemmes;
    QMap<QString, Modele *> _modeles;
    QMap<QString,QStringList> _morphos;
    QMap<QString,QStringList> _cas;
    QMap<QString,QStringList> _genres;
    QMap<QString,QStringList> _nombres;
    QMap<QString,QStringList> _temps;
    QMap<QString,QStringList> _modes;
    QMap<QString,QStringList> _voix;
    QMap<QString,QStringList> _motsClefs;
    QList<RegleVG*>           _reglesVG;
    QString                   transfVG(QString s);
    // Les morphos doivent pouvoir être données en anglais !
    QMultiMap<QString, Radical *> _radicaux;
    QMap<QString, QString> _variables;

    bool _extension; // = false;
    QString _cible;  // langue courante, 2 caractères ou plus

    QMap<QString, int> _tagOcc; // Nombre d'occurrences du tag.
    QMap<QString, int> _tagTot; // Nombre total en fonction du premier caractère du tag.
    QMap<QString, int> _trigram; // Nombre d'occurrences des séquences de 3 tags.
    void lisTags(bool tout = false);

    QString _resDir;          // Le chemin du répertoire de ressources
    QString _ajDir;           // chemin du répertoire des ajouts personnels
    QString          _dirLa;  // chemins des fichiers ajouts personnels
    QString          _dirFr;  //            "
    QString          _dirIrr; //            "
    QString          _dirVg;  //            "
    bool _extLoaded; // = true après chargement de l'extension
    // Lorsque j'ai chargé l'extension, je dois pouvoir ignorer les analyses qui en viennent.
    bool _nbrLoaded; // Si les nombres ont été chargés, je dois les effacer avant de les charger à nouveau.

   public:
    LemCore(QObject *parent = 0, QString resDir="");
    void                   ajDesinence(Desinence *d);
    QString                ajDir();  // accesseurs chemins
    QString                dirLa();  //     " ...
    QString                dirFr();
    QString                dirIrr();
    QString                dirVg();
    void                   ajLemme(Lemme* l);
    void                   ajModele(Modele *m);
    void                   ajRadicaux(Lemme *l);
    QString                assim(QString a);
    QString                assimq(QString a);
    QMap<QString, QString> cibles();
    QStringList            cles();
    static QString         deramise(QString r);
    QString                desassim(QString a);
    QString                desassimq(QString a);
    bool                   estAbr(QString m);
    // Pour remplacer Ch::abrev.contains(m) avec la liste des abréviations chargées.
    static bool            estRomain(QString f);
    bool                   inv(Lemme *l, const MapLem ml);
    MapLem                 lemmatise(QString f);  // lemmatise une forme
    // lemmatiseM lemmatise une forme en contexte
    MapLem                 lemmatiseM(QString f, bool debPhr = true, int etape  =0);
    Lemme*                 lemme(QString l);
    Lemme*                 lemmeDisque(QString l);
    // lemmes(ml) renvoie la liste des graphies des lemmes
    QStringList            lemmes(MapLem ml);
    // Lit les lignes d'un fichier. Est devenu public.
    QStringList            lignesFichier(QString nf);
    // Lire un fichier de césures étymologiques (non-phonétiques)
    void                   lireHyphen (QString fichierHyphen);
    QStringList            listeLemmesLa();
    QStringList            lModeles();
    Modele*                modele(QString m);
    QString                morpho(int i);
    void                   remplaceLemme(Lemme* l, Lemme* nl);
    QString                resDir();
    QMap<QString, QString> suffixes;
    //QString                trDisque(QString c);
    QString                variable(QString v);

    // Pour l'internationalisation
    QString                cas(int i);
    QString                genre(int i);
    QString                motsClefs(int i);
    QString                modes(int i);
    QString                nombre(int i);
    void                   remplaceLemme(Lemme* l);
    void                   rmRadicaux(Lemme* l);
    QString                temps(int i);
    QString                voix(int i);

    void                   setCible(QString c);
    QString                cible();
    bool                   optExtension();

    int                    fraction(QString listTags);
    QString                tag(Lemme *l, int m);
    int                    tagOcc(QString t);
    int                    trigram(QString seq);

   public slots:
    void                   setExtension(bool e);
    void                   setModuleLex(QString m);
};

#endif // LEMCORE_H
