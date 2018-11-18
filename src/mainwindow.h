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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include <QCompleter>

#include <flexion.h>
#include <lemCore.h>

class MainWindow : public QMainWindow
{

    Q_OBJECT

    public:
        MainWindow();
        ~MainWindow();

    private:
        QAction *actionQuant;
        QAction *actionCopier;
        QAction *actionDiff;
        QAction *actionQuitter;

        QWidget *centralWidget;
        QVBoxLayout *verticalLayout;
        QTabWidget *tabWidget;
        QWidget *tabLexique;
        QVBoxLayout *verticalLayout_Lex;
        QSplitter *splitter;
        QFrame *frame;
        QVBoxLayout *verticalLayout_G;
        QHBoxLayout *horizontalLayout;
        QLabel *labelLemme;
        QLineEdit *lineEditLemme;
        QSpacerItem *verticalSpacer_2;
        QFrame *frame1;
        QVBoxLayout *verticalLayout_D;
        QFormLayout *formLayout_L;
        QLabel *labelGrq;
        QHBoxLayout *horizontalLayout_grq;
        QLineEdit *lineEditGrq;
        QCheckBox *checkBoxVb;
        QLabel *labelModele;
        //QLineEdit* lineEditModeles;
        QComboBox* comboBoxModele;
        QLabel *labelPerfectum;
        QLineEdit *lineEditPerfectum;
        QLabel *labelSupin;
        QLineEdit *lineSupin;
        QLabel* labelTr;
        QLineEdit *lineEditTr;
        QLabel *labelMorpho;
        QLineEdit *lineMorpho;
        QTextEdit *textEditFlexion;
        QHBoxLayout *horizontalLayout_3;
        QPushButton *boutonEnr;
        QPushButton *boutonSuppr;
        QWidget *tabModeles;
        QVBoxLayout *verticalLayout_8;
        QVBoxLayout *verticalLayout_7;
        QHBoxLayout *horizontalLayout_2;
        QVBoxLayout *verticalLayout_6;
        QComboBox *comboModele;
        QListView *listView;
        QVBoxLayout *verticalLayout_5;
        QPushButton *pushButton;
        QPushButton *pushButton_2;
        QSpacerItem *verticalSpacer;
        QLineEdit *lineEdit;
        QListView *listView_2;
        QTextEdit *textEditFlexion_2;
        QWidget *varGraph;
        QComboBox *comboBox_2;
        QWidget *tabVarGraph;
        QComboBox *comboBox_3;
        QMenuBar *menuBar;
        QMenu *menuFichier;
        QToolBar *mainToolBar;
        QStatusBar *statusBar;

        QStringList       aaa;
        QCompleter*       completeur;
        QCompleter*       completeurM;
        Flexion*          flexion;
        LemCore*          lemcore;
        QList<QLineEdit*> lignes;
        QStringList       litems;
        Lemme*            lemme = 0;
        QStringList       lmodeles;
        QStringListModel  modele;
        Lemme*            nLemme = 0;

        QString     ligneFr();
        QStringList listeLemmesLa;
        QStringList listeLemmesFr;
        void    connecte();
        void    peuple();

    private slots:
        void    edLem(QString l);
        void    enr();
        QString ligneLa(QString modl="");
        void    lignesVisibles(bool v);
        void    rotQ();
};

#endif
