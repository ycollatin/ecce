/*            mainwindow.h
 *
 *  This file is part of ECCE.
 *
 *  ECCE is free software; you can redistribute it and/or modify
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
 *  along with ECCE; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * © Yves Ouvrard, 2009 - 2019
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QCompleter>

#include <flexion.h>
#include <lemcore.h>

class MainWindow : public QMainWindow
{

    Q_OBJECT

    public:
        MainWindow();
        ~MainWindow();

    private:
        QAction *actionArr;
        QAction *actionArrArr;
        QAction *actionAv;
        QAction *actionAvAv;
        QAction *actionDebut;
        QAction *actionDiff;
        QAction *actionEchecPrec;
        QAction *actionEchecSuiv;
        QAction *actionOuvrir;
        QAction *actionQuant;
        QAction *actionQuitter;
        //QAction *actionCopier;

        QWidget *centralWidget;
        QVBoxLayout *verticalLayout;
        QHBoxLayout *layoutInfo;
        QLabel *labelInfo;
        //QLabel *labelPos;
        QTabWidget *tabWidget;
        // onglet lexique
        QWidget *tabLexique;
        QVBoxLayout *verticalLayout_Lex;
        QSplitter *splitter;
        QFrame *frame;
        QVBoxLayout *verticalLayout_3;
        QTextEdit* editContexte;
        QHBoxLayout *horizontalLayout;
        QLabel *labelLemme;
        QLineEdit *lineEditLemme;
        QLabel *labelVG;
        QHBoxLayout* layoutScroll;
        QLabel*      labelScroll;
        QSlider*     slider;
        QHBoxLayout *horizontalLayoutBtns;
        QPushButton *bSuppr;
        QToolButton *bEchecPrec;
        QToolButton *bEchecSuiv;
        QToolButton *bArr;
        QToolButton *bArrArr;
        QToolButton *bAv;
        QToolButton *bAvAv;
        QToolButton *bDebut;
        //QSpacerItem *verticalSpacer_2;
        QListWidget *listWidgetLemmes;
        QFrame *frame1;
        QVBoxLayout *verticalLayout_2;
        QFormLayout *formLayout;
        QLabel *labelGrq;
        QHBoxLayout *horizontalLayout_grq;
        QLineEdit *lineEditGrq;
        QLabel *labelModele;
        QComboBox *comboBoxModele;
        QLabel *labelPerfectum;
        QLineEdit *lineEditPerfectum;
        QLabel *labelSupin;
        QLineEdit *lineSupin;
        QLabel *labelMorpho;
        QLineEdit *lineMorpho;
        QLabel *labelTr;
        QLineEdit *lineEditTr;
        QHBoxLayout *horizontalLayout_3;
        QPushButton *boutonEnr;
        QPushButton *boutonSuppr;
        QPushButton* boutonLemSuiv;
        QTextEdit *textEditFlexion;
        // onglet variantes graphiques
        QWidget *tabVarGraph;
        QVBoxLayout *verticalLayout_5;
        QVBoxLayout *verticalLayout_4;
        QSplitter *splitterVarGraph;
        QWidget *layoutWidget;
        QVBoxLayout *verticalLayoutConf;
        QLabel *label_3;

        // test de lemmatisation
        QHBoxLayout *horizontalLayoutTest;
        QLabel *labelTest;
        QLineEdit *lineEditTest;
        QLabel *labelLemTest;

        QHBoxLayout *horizontalLayoutBtnPre;
        QPushButton *btnPre;
        QSpacerItem *horizontalSpacerPre;
        QFormLayout *formLayoutCochesVar;
        QLabel *labelVariante;
        QCheckBox *checkBoxAe;
        QCheckBox *checkBox_H;
        QCheckBox *checkBox_Mihi;
        QCheckBox *checkBox_IJ;
        QCheckBox *checkBox_UV;
        QCheckBox *checkBox_TICI;
        QCheckBox *checkBox_MPN;
        QCheckBox *checkBox_PH;
        QSplitter *splitter_2;
        QPlainTextEdit *plainTextEditVariantes;
        QWidget *layoutWidget1;
        QPushButton *btnEnrVar;
        // onglet irréguliers
        QWidget *tabIrr;
        QVBoxLayout *verticalLayout_I;
        QSplitter *splitterIrr;
        QWidget *widget;
        QVBoxLayout *verticalLayout_Irr;
        QFormLayout *formLayout_2;
        QLabel *labelLemmeIrr;
        QLineEdit *linLemmeIrr;
        QLabel *labelFormeIrr;
        QLabel *labelMorphoIrr;
        QHBoxLayout *horizontalLayout_2;
        //QPushButton *pushButtonReinit;
        QLineEdit *linIrreg;
        QLineEdit *lineEditNumMorpho;
        QLabel *labelNumMorpho;
        QToolButton *btnPers;
        QToolButton *btnCas;
        QToolButton *btnGenre;
        QToolButton *btnNb;
        QToolButton *btnTps;
        QToolButton *btnMod;
        QToolButton *btnVx;
        QToolButton *btnAj;
        QToolButton *btnVide;
        QListWidget *listWidgetMorphos;
        QVBoxLayout *verticalLayoutIrrCentre;
        QSpacerItem *spacerIrrHaut;
        QPushButton *bAjIrr;
        QPushButton *bsupprIrr;
        QSpacerItem *spacerIrrBas;
        QListWidget *listWidgetIrr;
        // onglet modules lexicaux
        QWidget     *tabM;
        QVBoxLayout *verticalLayoutM;
        QSplitter   *splitterM;
        QWidget     *widgetM;
        QVBoxLayout *verticalLayoutLM;
        QLabel      *labelM;
        QListWidget *listWidgetM;
        QWidget     *widgetLM;
        QVBoxLayout *verticalLayoutD;
        QHBoxLayout *horizontalLayoutM;
        QPushButton *pushButtonCreeM;
        QLineEdit   *lineEditM;
        QPushButton *pushButtonActM;
        QPushButton *pushButtonDesactM;
        QPushButton *pushButtonSupprM;
        QPushButton *pushButtonPaquet;
        QPushButton *pushButtonInstM;
        QLabel      *labelInfoM;
        QSpacerItem *verticalSpacerM;
        // menu et barrre d'état
        QMenuBar *menuBar;
        QMenu *menuFichier;
        QToolBar *mainToolBar;
        QStatusBar *statusBar;

        void retranslateUi();

        // variables texte
        QStringList       aaa;
        QCompleter*       completeurM;
        void              connecte();
        QString           contexte(qint64 p, QString f="");
        QString docVarGraph =
        "!          vargraph.la\n"
        "!\n"
        "!  Dans ce fichier sont enregistrées les variantes\n"
        "! graphiques du corpus traité. Chaque ligne est\n"
        "! composée de deux chaînes séparées\n"
        "! - soit par le caractère ';' :\n"
        "!   à gauche, la graphie classique, à droite la graphie\n"
        "!   alternative, même si elle n'est pas toujours utilisée.\n" 
        "!   Les désinences et les radicaux sont calculés en\n" 
        "!   fonction de ces transformations, et les formes du\n"
        "!   texte sont elles aussi transformées.\n"
        "! - soit par le caractère '>' : à gauche une expression\n"
        "!   rationnelle qui permet de retrouver la graphie\n"
        "!   classique, à droite du '>'. On recourt à cette transfor-\n"
        "!   mation dans les cas où la chaîne à changer peut se\n"
        "!   trouver à cheval entre radical et désinence.\n"
        "!\n";
        QString           fichier;
        Flexion*          flexion;
        QTextStream       flux;
        QString           forme;
        QString           gabaritLa = "%1|%2|%3|%4|%5|%6";
        int               iLemSuiv;
        LemCore*          lemcore;
        QString           ligneFr();
        QList<QLineEdit*> lignes;
        QStringList       lis();
        QStringList       listeGr;
        QStringList       litems;
        Lemme*            lemme = 0;
        QStringList       lmodeles;
        void              majInfo(bool barre=true);
        void              majLinMorph();
        MapLem            ml;
        QStringListModel* modele;
        QStringListModel* modeleIrr;
        QStringListModel* modeleM; // morphos
        Lemme*            nLemme = 0;
        void              peuple();
        void              reinit();
        qint64            tailleF;

        // irréguliers
        QStringList       lCas;
        int               iCas;
        QStringList       lGenre;
        int               iGenre;
        QStringList       lMod;
        int               iMod;
        QStringList       lNb;
        int               iNb;
        QStringList       lPers;
        int               iPers;
        QStringList       lTps;
        int               iTps;
        QStringList       lVx;
        int               iVx;

        // chemins
        QString           resDir;
        QString           ajDir;
        QString           module;
        QString           modDir;
        QFile             fCorpus;
        QStringList       itemsIrr;
        QMap<int,QString> lMorphos;
        QStringList       selMorph;
        // variantes graphiques
        QStringList       lvarGraph;
        qint64            posFC;
        QList<qint64>     echecs;  // liste des positions d'échec
        // navigation
        void        porro(int pas);
        void        retro(int pas);

    private slots:
        void        activerM();
        void        ajIrr();
        void        ajMorph();
        void        arr();
        void        arrArr();
        //void        arrArr();
        void        av();
        void        avAv();
        QString     cle(QString ligne);
        void        closeEvent(QCloseEvent* event);
        void        coche();
        void        creerM();
        void        debut();
        void        echec();
        void        echecPrec();
        void        editIrr(const QModelIndex &m);
        void        editModule(QString k, QString l, QString f);
        void        edLem(QString l="");
        void        edLem(const QModelIndex &m);
        void        enr();
        void        enrVar();
        void        initCoches(QStringList lv);
        //void        insereLigne(QString l, QString f);
        void        instM();
        void        lemSuiv();
        QString     ligneLa(QString modl="");
        void        lignesVisibles(QString chModele);
        QStringList lisLignes(QString nf, bool ignoreComm=false);
        void        ouvrir(QString nf="", qint64 p=0);
        void        paquet();
        void        preAn();
        //void        reserve();
        void        rotQ();
        void        sbar();
        void        selLem(QString l);
        void        siCas();
        void        siGenre();
        void        siMod();
        void        siNb();
        void        siPers();
        void        siTps();
        void        siVx();
        void        suppr(QString l, QString f);
        void        supprLa();
        void        supprIrr();
        void        supprM();
        void        teste(QString f);
        void        videMorph();
};

#endif
