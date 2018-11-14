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
    actionDiff = new QAction(this);
    actionQuitter = new QAction(this);

    actionQuant = new QAction(this);
    actionCharger = new QAction(this);
    actionQuitter = new QAction(this);
    actionDiff = new QAction(this);
    centralWidget = new QWidget(this);
    verticalLayout = new QVBoxLayout(centralWidget);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    tabWidget = new QTabWidget(centralWidget);
    tabLexique = new QWidget();
    verticalLayout_3 = new QVBoxLayout(tabLexique);
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setContentsMargins(11, 11, 11, 11);
    splitter = new QSplitter(tabLexique);
    splitter->setOrientation(Qt::Horizontal);
    widget = new QWidget(splitter);
    verticalLayout_G = new QVBoxLayout(widget);
    verticalLayout_G->setSpacing(6);
    verticalLayout_G->setContentsMargins(11, 11, 11, 11);
    verticalLayout_G->setContentsMargins(0, 0, 0, 0);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    labelLemme = new QLabel(widget);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelLemme->sizePolicy().hasHeightForWidth());
    labelLemme->setSizePolicy(sizePolicy);
    labelLemme->setMaximumSize(QSize(16777215, 50));

    horizontalLayout->addWidget(labelLemme);

    lineEditLemme = new QLineEdit(widget);

    horizontalLayout->addWidget(lineEditLemme);


    verticalLayout_G->addLayout(horizontalLayout);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_G->addItem(verticalSpacer_2);

    splitter->addWidget(widget);
    widget1 = new QWidget(splitter);
    verticalLayout_D = new QVBoxLayout(widget1);
    verticalLayout_D->setSpacing(6);
    verticalLayout_D->setContentsMargins(11, 11, 11, 11);
    verticalLayout_D->setContentsMargins(0, 0, 0, 0);
    formLayout_L = new QFormLayout();
    formLayout_L->setSpacing(6);
    formLayout_L->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    labelGrq = new QLabel(widget1);

    formLayout_L->setWidget(0, QFormLayout::LabelRole, labelGrq);

    lineEditGrq = new QLineEdit(widget1);

    formLayout_L->setWidget(0, QFormLayout::FieldRole, lineEditGrq);

    labelModele = new QLabel(widget1);
    labelModele->setLayoutDirection(Qt::LeftToRight);
    labelModele->setScaledContents(false);
    labelModele->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    formLayout_L->setWidget(1, QFormLayout::LabelRole, labelModele);

    lineEditModeles = new QLineEdit(widget1);

    formLayout_L->setWidget(1, QFormLayout::FieldRole, lineEditModeles);

    labelInfectum = new QLabel(widget1);
    labelInfectum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    formLayout_L->setWidget(2, QFormLayout::LabelRole, labelInfectum);

    lineEditInfectum = new QLineEdit(widget1);

    formLayout_L->setWidget(2, QFormLayout::FieldRole, lineEditInfectum);

    labelPerfectum = new QLabel(widget1);

    formLayout_L->setWidget(3, QFormLayout::LabelRole, labelPerfectum);

    lineEditPerfectum = new QLineEdit(widget1);

    formLayout_L->setWidget(3, QFormLayout::FieldRole, lineEditPerfectum);

    labelSupin = new QLabel(widget1);
    labelSupin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    formLayout_L->setWidget(4, QFormLayout::LabelRole, labelSupin);

    lineSupin = new QLineEdit(widget1);

    formLayout_L->setWidget(4, QFormLayout::FieldRole, lineSupin);

    labelTr = new QLabel(widget1);

    formLayout_L->setWidget(6, QFormLayout::LabelRole, labelTr);

    lineEditTr = new QLineEdit(widget1);

    formLayout_L->setWidget(6, QFormLayout::FieldRole, lineEditTr);

    labelMorpho = new QLabel(widget1);

    formLayout_L->setWidget(5, QFormLayout::LabelRole, labelMorpho);

    lineMorpho = new QLineEdit(widget1);

    formLayout_L->setWidget(5, QFormLayout::FieldRole, lineMorpho);


    verticalLayout_D->addLayout(formLayout_L);

    textEditFlexion = new QTextEdit(widget1);

    verticalLayout_D->addWidget(textEditFlexion);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    boutonEnr = new QPushButton(widget1);

    horizontalLayout_3->addWidget(boutonEnr);

    boutonSuppr = new QPushButton(widget1);

    horizontalLayout_3->addWidget(boutonSuppr);


    verticalLayout_D->addLayout(horizontalLayout_3);

    splitter->addWidget(widget1);

    verticalLayout_3->addWidget(splitter);

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
    menuFichier->addAction(actionDiff);
    menuFichier->addAction(actionQuitter);
    mainToolBar->addAction(actionQuant);

    tabWidget->setCurrentIndex(0);

    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    actionQuant->setText(QApplication::translate("MainWindow", "quantit\303\251", Q_NULLPTR));
    actionCharger->setText(QApplication::translate("MainWindow", "Charger", Q_NULLPTR));
    actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
    actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
    actionDiff->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer un fichier diff", Q_NULLPTR));
    labelLemme->setText(QApplication::translate("MainWindow", "Lemme", Q_NULLPTR));
    labelGrq->setText(QApplication::translate("MainWindow", "Forme canonique, avec quantit\303\251s", Q_NULLPTR));
    labelModele->setText(QApplication::translate("MainWindow", "Mod\303\250le", Q_NULLPTR));
    labelInfectum->setText(QApplication::translate("MainWindow", "rad. infectum", Q_NULLPTR));
    labelPerfectum->setText(QApplication::translate("MainWindow", "rad. parfait", Q_NULLPTR));
    labelSupin->setText(QApplication::translate("MainWindow", "rad. supin", Q_NULLPTR));
    labelTr->setText(QApplication::translate("MainWindow", "traductions", Q_NULLPTR));
    labelMorpho->setText(QApplication::translate("MainWindow", "morphologie", Q_NULLPTR));
    boutonEnr->setText(QApplication::translate("MainWindow", "Enregistrer", Q_NULLPTR));
    boutonSuppr->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabLexique), QApplication::translate("MainWindow", "Lexique", Q_NULLPTR));
    pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
    pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabModeles), QApplication::translate("MainWindow", "Mod\303\250les", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(varGraph), QApplication::translate("MainWindow", "Variantes graphiques", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Irr\303\251guliers", Q_NULLPTR));
    menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));
    tabWidget->setCurrentIndex(0);

    // liste des lignes demandant des quantités
    lignes
        << lineEditGrq
        << lineEditModeles
        << lineEditInfectum
        << lineEditPerfectum  
        << lineSupin;
    aaa << "aăā"
        << "eĕē"
        << "iĭī"
        << "oŏō"
        << "uŭū"
        << "yyy";
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
    connect(actionQuant, SIGNAL(triggered()), this, SLOT(rotQ()));
}

void MainWindow::edLem(QString l)
{
    lemme = lemcore->lemme(l);
    if (lemme != 0)
    {
        qDebug()<<"lemme"<<lemme->grq()<<lemme->nbRadicaux()<<"radicaux";
        lineEditGrq->setText(lemme->grq());
        lineEditModeles->setText(lemme->grModele());
        lineMorpho->setText(lemme->indMorph());
        lineEditTr->setText(lemme->traduction("fr"));
        // vider les lignes
        labelInfectum->hide();
        lineEditInfectum->hide();
        labelPerfectum->hide();
        lineEditPerfectum->hide();
        labelSupin->hide();
        lineSupin->hide();
        // radicaux
        for (int i=0;i<lemme->nbRadicaux();++i)
        {
            QList<Radical*> lr = lemme->radical(i);
            qDebug()<<"   i="<<i<<","<<lr.count()<<"variante(s)";
            // les peupler
            QStringList lgrq;
            int numrad = -1;
            if (!lr.isEmpty()) numrad = lr.at(0)->numRad();
            for (int j=0;j<lr.count();++j)
            {
                Radical* r = lr.at(j);
                lgrq.append(r->grq());
            }
            QString grq = lgrq.join(',');
            switch(numrad)
            {
                case 0:
                    {
                        qDebug()<<"   0"<<grq;
                        // verbes, infectum
                        lineEditInfectum->setText(grq);
                        labelInfectum->show();
                        lineEditInfectum->show();
                        break;
                    }
                case 1:
                    {
                        qDebug()<<"   1"<<grq;
                        if (QString("vw").contains(lemme->pos()))
                            labelPerfectum->setText("rad. perfectum");
                        else
                        {
                            // adverbes ?
                            labelPerfectum->setText("rad. génitif");
                        }
                        labelPerfectum->show();
                        lineEditPerfectum->setText(grq);
                        lineEditPerfectum->show();
                        break;
                    }
                case 2:
                    {
                        qDebug()<<"   2"<<grq;
                        break;
                    }
                case 3:
                    {
                        qDebug()<<"   3"<<grq;
                        break;
                    }
                default:
                    {
                        qDebug()<<"   "<<numrad<<grq;
                        break;
                    }
            }
        }
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

void MainWindow::rotQ()
{
    for (int i=0;i<lignes.count();++i)
    {
        if (lignes.at(i)->hasFocus())
        {
            QString texte = lignes.at(i)->text();
            if (texte.isEmpty()) return;
            QChar der = texte.at(texte.length()-1);
            for (int j=0;j<aaa.count();++j)
            {
                QString vvv = aaa.at(j);
                int p = vvv.indexOf(der);
                switch (p)
                {
                    case 0:
                    case 1:
                        p++;
                        break;
                    case 2:
                        p = 0;
                    default: break;
                }
                if (p > -1)
                {
                    texte.chop(1);
                    texte.append(vvv.at(p));
                    lignes.at(i)->setText(texte);
                    return;
                }
            }
            break;
        }
    }
}

