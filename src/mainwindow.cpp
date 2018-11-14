/*   mainwindow.cpp
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
 * © Yves Ouvrard, 2009 - 2016
 */

#include "mainwindow.h"

MainWindow::MainWindow()
{
    actionQuant = new QAction(this);
    actionCharger = new QAction(this);
    actionQuitter = new QAction(this);
    centralWidget = new QWidget(this);
    verticalLayout = new QVBoxLayout(centralWidget);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    tabWidget = new QTabWidget(centralWidget);
    tabLexique = new QWidget();
    verticalLayout_4 = new QVBoxLayout(tabLexique);
    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setSpacing(6);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    labelLemme = new QLabel(tabLexique);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelLemme->sizePolicy().hasHeightForWidth());
    labelLemme->setSizePolicy(sizePolicy);
    labelLemme->setMaximumSize(QSize(16777215, 50));

    horizontalLayout->addWidget(labelLemme);

    lineEditLemme = new QLineEdit(tabLexique);

    horizontalLayout->addWidget(lineEditLemme);

    verticalLayout_2->addLayout(horizontalLayout);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_2);

    horizontalLayout_3->addLayout(verticalLayout_2);

    verticalLayout_3 = new QVBoxLayout();
    verticalLayout_3->setSpacing(6);
    formLayout = new QFormLayout();
    formLayout->setSpacing(6);
    formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    labelGrq = new QLabel(tabLexique);

    formLayout->setWidget(0, QFormLayout::LabelRole, labelGrq);

    lineEditGrq = new QLineEdit(tabLexique);

    formLayout->setWidget(0, QFormLayout::FieldRole, lineEditGrq);

    lineEditTr = new QLineEdit(tabLexique);
    formLayout->setWidget(4, QFormLayout::FieldRole, lineEditTr);

    labelTr = new QLabel(tabLexique);
    formLayout->setWidget(4, QFormLayout::LabelRole, labelTr);

    labelModele = new QLabel(tabLexique);
    labelModele->setLayoutDirection(Qt::LeftToRight);
    labelModele->setScaledContents(false);
    labelModele->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    formLayout->setWidget(1, QFormLayout::LabelRole, labelModele);

    lineEditModeles = new QLineEdit(tabLexique);
    formLayout->setWidget(1, QFormLayout::FieldRole, lineEditModeles);

    labelR2 = new QLabel(tabLexique);
    labelR2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    formLayout->setWidget(2, QFormLayout::LabelRole, labelR2);

    lineSupin = new QLineEdit(tabLexique);

    formLayout->setWidget(2, QFormLayout::FieldRole, lineSupin);

    labelSupin = new QLabel(tabLexique);
    labelSupin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    formLayout->setWidget(3, QFormLayout::LabelRole, labelSupin);

    lineEdit_3 = new QLineEdit(tabLexique);

    formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_3);

    verticalLayout_3->addLayout(formLayout);

    textEditFlexion = new QTextEdit(tabLexique);

    verticalLayout_3->addWidget(textEditFlexion);

    horizontalLayout_3->addLayout(verticalLayout_3);

    verticalLayout_4->addLayout(horizontalLayout_3);

    tabWidget->addTab(tabLexique, QString());
    tabModeles = new QWidget();
    verticalLayout_8 = new QVBoxLayout(tabModeles);
    verticalLayout_8->setSpacing(6);
    verticalLayout_8->setContentsMargins(11, 11, 11, 11);
    verticalLayout_7 = new QVBoxLayout();
    verticalLayout_7->setSpacing(6);
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    verticalLayout_6 = new QVBoxLayout();
    verticalLayout_6->setSpacing(6);
    comboModele = new QComboBox(tabModeles);

    verticalLayout_6->addWidget(comboModele);

    listView = new QListView(tabModeles);

    verticalLayout_6->addWidget(listView);


    horizontalLayout_2->addLayout(verticalLayout_6);

    verticalLayout_5 = new QVBoxLayout();
    verticalLayout_5->setSpacing(6);
    pushButton = new QPushButton(tabModeles);

    verticalLayout_5->addWidget(pushButton);

    pushButton_2 = new QPushButton(tabModeles);

    verticalLayout_5->addWidget(pushButton_2);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_5->addItem(verticalSpacer);

    horizontalLayout_2->addLayout(verticalLayout_5);

    lineEdit = new QLineEdit(tabModeles);

    horizontalLayout_2->addWidget(lineEdit);

    listView_2 = new QListView(tabModeles);

    horizontalLayout_2->addWidget(listView_2);

    verticalLayout_7->addLayout(horizontalLayout_2);

    textEditFlexion_2 = new QTextEdit(tabModeles);

    verticalLayout_7->addWidget(textEditFlexion_2);

    verticalLayout_8->addLayout(verticalLayout_7);

    tabWidget->addTab(tabModeles, QString());
    varGraph = new QWidget();
    comboBox_2 = new QComboBox(varGraph);
    comboBox_2->setGeometry(QRect(50, 30, 72, 22));
    tabWidget->addTab(varGraph, QString());
    tab = new QWidget();
    comboBox_3 = new QComboBox(tab);
    comboBox_3->setGeometry(QRect(50, 60, 72, 22));
    tabWidget->addTab(tab, QString());

    verticalLayout->addWidget(tabWidget);

    setCentralWidget(centralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setGeometry(QRect(0, 0, 1067, 19));
    menuFichier = new QMenu(menuBar);
    setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    menuBar->addAction(menuFichier->menuAction());
    menuFichier->addSeparator();
    menuFichier->addAction(actionCharger);
    menuFichier->addAction(actionQuitter);
    mainToolBar->addAction(actionQuant);

    tabWidget->setCurrentIndex(0);

    QMetaObject::connectSlotsByName(this);

    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    actionQuant->setText(QApplication::translate("MainWindow", "quantit\303\251", Q_NULLPTR));
    actionCharger->setText(QApplication::translate("MainWindow", "Charger", Q_NULLPTR));
    actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
    actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
    labelLemme->setText(QApplication::translate("MainWindow", "Lemme", Q_NULLPTR));
    labelGrq->setText(QApplication::translate("MainWindow", "Forme canonique, avec quantit\303\251s", Q_NULLPTR));
    labelModele->setText(QApplication::translate("MainWindow", "Mod\303\250le", Q_NULLPTR));
    labelR2->setText(QApplication::translate("MainWindow", "g\303\251nitif", Q_NULLPTR));
    labelSupin->setText(QApplication::translate("MainWindow", "supin", Q_NULLPTR));
    labelTr->setText(QApplication::translate("MainWindow", "traductions", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabLexique), QApplication::translate("MainWindow", "Lexique", Q_NULLPTR));
    pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
    pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabModeles), QApplication::translate("MainWindow", "Mod\303\250les", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(varGraph), QApplication::translate("MainWindow", "Variantes graphiques", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Irr\303\251guliers", Q_NULLPTR));
    menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));

    tabWidget->setCurrentIndex(0);

    peuple();
    connecte();
}


MainWindow::~MainWindow()
{
    delete lemcore;
}

void MainWindow::connecte()
{
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(completeur, SIGNAL(activated(QString)), this, SLOT(edLem(QString)));
    connect(lineEditLemme, SIGNAL(returnPressed()), this, SLOT(edLem()));
}

void MainWindow::edLem(QString l)
{
    Lemme * lemme = lemcore->lemme(l);
    if (lemme != 0)
    {
        lineEditGrq->setText(lemme->grq());
    }
}

void MainWindow::edLem()
{
    edLem(lineEditLemme->text()); 
}

void MainWindow::peuple()
{
    lemcore = new LemCore(this);
    // lemmes
    litems.append(lemcore->cles());
	completeur = new QCompleter(litems);
    completeur->setMaxVisibleItems(litems.count());
    QStringListModel* modele = new QStringListModel(litems, completeur);
    completeur->setModel(modele);
    completeur->setCompletionMode(QCompleter::PopupCompletion);
    lineEditLemme->setCompleter(completeur);
    // modèles
    lmodeles.append(lemcore->lModeles());
    completeurM = new  QCompleter(lmodeles);
    completeurM->setMaxVisibleItems(litems.count());
    QStringListModel* modeleM = new QStringListModel(lmodeles, completeurM);
    completeurM->setModel(modeleM);
    completeur->setCompletionMode(QCompleter::PopupCompletion);
    lineEditModeles->setCompleter(completeurM);
}

