/*            mainwindow.h
 *
 *  This file is part of EDITCOL.
 *
 *  EDITCOL is free software; you can redistribute it and/or modify
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
 *  along with EDITCOL; if not, write to the Free Software
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
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
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
        QAction *actionQuant;
        QAction *actionQuitter;
        QAction *actionDiff;
        QAction *actionCopier;

        QWidget *centralWidget;
        QVBoxLayout *verticalLayout_9;
        QTabWidget *tabWidget;
        QWidget *tabLexique;
        QVBoxLayout *verticalLayout_Lex;
        QSplitter *splitter;
        QFrame *frame;
        QVBoxLayout *verticalLayout_3;
        QHBoxLayout *horizontalLayout;
        QLabel *labelLemme;
        QLineEdit *lineEditLemme;
        QPushButton *bHomon;
        QPushButton *bSuppr;
        QSpacerItem *verticalSpacer_2;
        QFrame *frame1;
        QVBoxLayout *verticalLayout_2;
        QFormLayout *formLayout;
        QLabel *labelGrq;
        QHBoxLayout *horizontalLayout_grq;
        QLineEdit *lineEditGrq;
        QCheckBox *checkBoxVb;
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
        QTextEdit *textEditFlexion;

        // onglet variantes graphiques
        QWidget *tabVarGraph;
        QVBoxLayout *verticalLayout_5;
        QSplitter *splitterVarGraph;
        QWidget *layoutWidget;
        QVBoxLayout *verticalLayoutConf;
        QLabel *label_3;
        QHBoxLayout *horizontalLayoutBtnPre;
        QPushButton *btnPre;
        QSpacerItem *horizontalSpacerPre;
        QFormLayout *formLayoutCochesVar;
        QLabel *labelVariante;
        QCheckBox *checkBoxAe;
        QCheckBox *checkBox_ae;
        QCheckBox *checkBox_H;
        QCheckBox *checkBox_h;
        QCheckBox *checkBox_Mihi;
        QCheckBox *checkBox_mihi;
        QCheckBox *checkBox_IJ;
        QCheckBox *checkBox_ij;
        QCheckBox *checkBox_UV;
        QCheckBox *checkBox_uv;
        QCheckBox *checkBox_TICI;
        QCheckBox *checkBox_tici;
        QCheckBox *checkBox_MPN;
        QCheckBox *checkBox_mpn;
        QCheckBox *checkBox_PH;
        QCheckBox *checkBox_ph;
        QLabel *label_tju;
        QSplitter *splitter_2;
        QPlainTextEdit *plainTextEditVariantes;
        QWidget *layoutWidget1;
        QVBoxLayout *verticalLayout_4;
        QLabel *label_AutresVar;
        QPushButton *btnEnrVar;
        QPlainTextEdit *plainTextEdit_AutresVar;

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
        QPushButton *pushButtonReinit;
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
        QListWidget *listWidgetMorphos;
        QWidget *widget1;
        QVBoxLayout *verticalLayoutIrrCentre;
        QSpacerItem *spacerIrrHaut;
        QPushButton *bAjIrr;
        QPushButton *bsupprIrr;
        QSpacerItem *spacerIrrBas;
        QListWidget *listWidgetIrr;

        // menu et barrre d'état
        QMenuBar *menuBar;
        QMenu *menuFichier;
        QToolBar *mainToolBar;
        QStatusBar *statusBar;

        void retranslateUi();

        QStringList       aaa;
        QCompleter*       completeur;
        QCompleter*       completeurM;
        void              connecte();
        QString           docVarGraph;

        Flexion*          flexion;
        QString GabaritLa = "%1|%2|%3|%4|%5|%6";
        LemCore*          lemcore;
        QString           ligneFr();
        QList<QLineEdit*> lignes;
        QStringList       lis();
        QStringList       listeGr;
        QStringList       listeLemmesLa;
        QStringList       listeLemmesFr;
        QStringList       litems;
        Lemme*            lemme = 0;
        QStringList       lmodeles;
        void              majLinMorph();
        QStringListModel* modele;
        QStringListModel* modeleIrr;
        QStringListModel* modeleM; // morphos
        Lemme*            nLemme = 0;
        void              peuple();
        void              peupleAjLemmes();
        void              peupleAjTr();
        void              peupleAjIrr();
        void              peupleAjVg();
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
        QString           dirLa;
        QString           dirFr;
        QString           dirIrr;
        QString           dirVg;
        QStringList       itemsIrr;
        QMap<int,QString> lMorphos;
        QStringList       selMorph;
        // variantes graphiques
        QStringList       lvarGraph;

    private slots:
        void        ajIrr();
        void        ajMorph();
        QString     cle(QString ligne);
        void        coche();
        void        editIrr(const QModelIndex &m);
        void        edLem(QString l);
        void        enr();
        void        enrFr(QString l);
        //void        enrIrr(QString l);
        void        enrLa(QString l);
        void        enrVar();
        int         indexOfInsert(QString s, QStringList l);
        void        insereLigne(QString l, QString f);
        QString     ligneLa(QString modl="");
        void        lignesVisibles(bool v);
        QStringList lisLignes(QString nf, bool ignoreComm=false);
        void        preAn();
        void        rotQ();
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
};

#endif
