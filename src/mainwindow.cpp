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

/*
   FIXME

   Les lemmes modifiés s'ajoutent au lieu de remplacer.

   TODO

   - rendre le choix du modele plus ergonomique
   mettre au point une taxonomie des pos ?
   - rendre l'homonymie plus ergonomique
   - Chemin absolu des données A et B
   - initialisation d'un module
   - analyser la version médiévale de C11
 */

#include <QFileDialog>
#include <mainwindow.h>

MainWindow::MainWindow()
{
    actionQuant = new QAction(this);
    actionQuitter = new QAction(this);
    actionDiff = new QAction(this);
    actionCopier = new QAction(this);
    //  setupUi
    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    verticalLayout_9 = new QVBoxLayout(centralWidget);
    verticalLayout_9->setSpacing(6);
    verticalLayout_9->setContentsMargins(11, 11, 11, 11);
    verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
    tabWidget = new QTabWidget(centralWidget);
    tabWidget->setObjectName(QStringLiteral("tabWidget"));
    tabLexique = new QWidget();
    tabLexique->setObjectName(QStringLiteral("tabLexique"));
    verticalLayout_Lex = new QVBoxLayout(tabLexique);
    verticalLayout_Lex->setSpacing(6);
    verticalLayout_Lex->setContentsMargins(11, 11, 11, 11);
    verticalLayout_Lex->setObjectName(QStringLiteral("verticalLayout_Lex"));
    splitter = new QSplitter(tabLexique);
    splitter->setObjectName(QStringLiteral("splitter"));
    splitter->setMouseTracking(false);
    splitter->setFrameShape(QFrame::NoFrame);
    splitter->setOrientation(Qt::Horizontal);
    frame = new QFrame(splitter);
    frame->setObjectName(QStringLiteral("frame"));
    frame->setFrameShape(QFrame::Box);
    verticalLayout_3 = new QVBoxLayout(frame);
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setContentsMargins(11, 11, 11, 11);
    verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    labelLemme = new QLabel(frame);
    labelLemme->setObjectName(QStringLiteral("labelLemme"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelLemme->sizePolicy().hasHeightForWidth());
    labelLemme->setSizePolicy(sizePolicy);
    labelLemme->setMaximumSize(QSize(16777215, 50));

    horizontalLayout->addWidget(labelLemme);

    lineEditLemme = new QLineEdit(frame);
    lineEditLemme->setObjectName(QStringLiteral("lineEditLemme"));

    horizontalLayout->addWidget(lineEditLemme);

    bHomon = new QPushButton(frame);
    bHomon->setObjectName(QStringLiteral("bHomon"));

    horizontalLayout->addWidget(bHomon);

    bSuppr = new QPushButton(frame);
    bSuppr->setObjectName(QStringLiteral("bSuppr"));

    horizontalLayout->addWidget(bSuppr);


    verticalLayout_3->addLayout(horizontalLayout);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_3->addItem(verticalSpacer_2);

    splitter->addWidget(frame);
    frame1 = new QFrame(splitter);
    frame1->setObjectName(QStringLiteral("frame1"));
    frame1->setFrameShape(QFrame::Box);
    verticalLayout_2 = new QVBoxLayout(frame1);
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setContentsMargins(11, 11, 11, 11);
    verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
    formLayout = new QFormLayout();
    formLayout->setSpacing(6);
    formLayout->setObjectName(QStringLiteral("formLayout"));
    labelGrq = new QLabel(frame1);
    labelGrq->setObjectName(QStringLiteral("labelGrq"));

    formLayout->setWidget(0, QFormLayout::LabelRole, labelGrq);

    horizontalLayout_grq = new QHBoxLayout();
    horizontalLayout_grq->setSpacing(6);
    horizontalLayout_grq->setObjectName(QStringLiteral("horizontalLayout_grq"));
    lineEditGrq = new QLineEdit(frame1);
    lineEditGrq->setObjectName(QStringLiteral("lineEditGrq"));

    horizontalLayout_grq->addWidget(lineEditGrq);

    checkBoxVb = new QCheckBox(frame1);
    checkBoxVb->setObjectName(QStringLiteral("checkBoxVb"));

    horizontalLayout_grq->addWidget(checkBoxVb);


    formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_grq);

    labelModele = new QLabel(frame1);
    labelModele->setObjectName(QStringLiteral("labelModele"));
    labelModele->setLayoutDirection(Qt::LeftToRight);
    labelModele->setScaledContents(false);
    labelModele->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    formLayout->setWidget(1, QFormLayout::LabelRole, labelModele);

    comboBoxModele = new QComboBox(frame1);
    comboBoxModele->setObjectName(QStringLiteral("comboBoxModele"));

    formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxModele);

    labelPerfectum = new QLabel(frame1);
    labelPerfectum->setObjectName(QStringLiteral("labelPerfectum"));

    formLayout->setWidget(2, QFormLayout::LabelRole, labelPerfectum);

    lineEditPerfectum = new QLineEdit(frame1);
    lineEditPerfectum->setObjectName(QStringLiteral("lineEditPerfectum"));

    formLayout->setWidget(2, QFormLayout::FieldRole, lineEditPerfectum);

    labelSupin = new QLabel(frame1);
    labelSupin->setObjectName(QStringLiteral("labelSupin"));
    labelSupin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    formLayout->setWidget(3, QFormLayout::LabelRole, labelSupin);

    lineSupin = new QLineEdit(frame1);
    lineSupin->setObjectName(QStringLiteral("lineSupin"));

    formLayout->setWidget(3, QFormLayout::FieldRole, lineSupin);

    labelMorpho = new QLabel(frame1);
    labelMorpho->setObjectName(QStringLiteral("labelMorpho"));

    formLayout->setWidget(4, QFormLayout::LabelRole, labelMorpho);

    lineMorpho = new QLineEdit(frame1);
    lineMorpho->setObjectName(QStringLiteral("lineMorpho"));

    formLayout->setWidget(4, QFormLayout::FieldRole, lineMorpho);

    labelTr = new QLabel(frame1);
    labelTr->setObjectName(QStringLiteral("labelTr"));

    formLayout->setWidget(5, QFormLayout::LabelRole, labelTr);

    lineEditTr = new QLineEdit(frame1);
    lineEditTr->setObjectName(QStringLiteral("lineEditTr"));

    formLayout->setWidget(5, QFormLayout::FieldRole, lineEditTr);


    verticalLayout_2->addLayout(formLayout);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
    boutonEnr = new QPushButton(frame1);
    boutonEnr->setObjectName(QStringLiteral("boutonEnr"));

    horizontalLayout_3->addWidget(boutonEnr);

    boutonSuppr = new QPushButton(frame1);
    boutonSuppr->setObjectName(QStringLiteral("boutonSuppr"));
    boutonEnr = new QPushButton(frame1);

    horizontalLayout_3->addWidget(boutonSuppr);


    verticalLayout_2->addLayout(horizontalLayout_3);

    textEditFlexion = new QTextEdit(frame1);
    textEditFlexion->setObjectName(QStringLiteral("textEditFlexion"));
    textEditFlexion->setReadOnly(true);

    verticalLayout_2->addWidget(textEditFlexion);

    splitter->addWidget(frame1);

    verticalLayout_Lex->addWidget(splitter);

    tabWidget->addTab(tabLexique, QString());
    tabVarGraph = new QWidget();
    tabVarGraph->setObjectName(QStringLiteral("tabVarGraph"));
    verticalLayout_5 = new QVBoxLayout(tabVarGraph);
    verticalLayout_5->setSpacing(6);
    verticalLayout_5->setContentsMargins(11, 11, 11, 11);
    verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
    splitterVarGraph = new QSplitter(tabVarGraph);
    splitterVarGraph->setObjectName(QStringLiteral("splitterVarGraph"));
    splitterVarGraph->setOrientation(Qt::Horizontal);
    layoutWidget = new QWidget(splitterVarGraph);
    layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
    verticalLayoutConf = new QVBoxLayout(layoutWidget);
    verticalLayoutConf->setSpacing(6);
    verticalLayoutConf->setContentsMargins(11, 11, 11, 11);
    verticalLayoutConf->setObjectName(QStringLiteral("verticalLayoutConf"));
    verticalLayoutConf->setContentsMargins(0, 0, 0, 0);
    label_3 = new QLabel(layoutWidget);
    label_3->setObjectName(QStringLiteral("label_3"));

    verticalLayoutConf->addWidget(label_3);

    horizontalLayoutBtnPre = new QHBoxLayout();
    horizontalLayoutBtnPre->setSpacing(6);
    horizontalLayoutBtnPre->setObjectName(QStringLiteral("horizontalLayoutBtnPre"));
    btnPre = new QPushButton(layoutWidget);
    btnPre->setObjectName(QStringLiteral("btnPre"));

    horizontalLayoutBtnPre->addWidget(btnPre);

    horizontalSpacerPre = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayoutBtnPre->addItem(horizontalSpacerPre);


    verticalLayoutConf->addLayout(horizontalLayoutBtnPre);

    formLayoutCochesVar = new QFormLayout();
    formLayoutCochesVar->setSpacing(6);
    formLayoutCochesVar->setObjectName(QStringLiteral("formLayoutCochesVar"));
    formLayoutCochesVar->setContentsMargins(13, 13, -1, -1);
    labelVariante = new QLabel(layoutWidget);
    labelVariante->setObjectName(QStringLiteral("labelVariante"));

    formLayoutCochesVar->setWidget(0, QFormLayout::LabelRole, labelVariante);

    checkBoxAe = new QCheckBox(layoutWidget);
    checkBoxAe->setObjectName(QStringLiteral("checkBoxAe"));

    formLayoutCochesVar->setWidget(1, QFormLayout::LabelRole, checkBoxAe);

    checkBox_ae = new QCheckBox(layoutWidget);
    checkBox_ae->setObjectName(QStringLiteral("checkBox_ae"));

    formLayoutCochesVar->setWidget(1, QFormLayout::FieldRole, checkBox_ae);

    checkBox_H = new QCheckBox(layoutWidget);
    checkBox_H->setObjectName(QStringLiteral("checkBox_H"));


    formLayoutCochesVar->setWidget(2, QFormLayout::LabelRole, checkBox_H);

    checkBox_h = new QCheckBox(layoutWidget);
    checkBox_h->setObjectName(QStringLiteral("checkBox_h"));

    formLayoutCochesVar->setWidget(2, QFormLayout::FieldRole, checkBox_h);

    checkBox_Mihi = new QCheckBox(layoutWidget);
    checkBox_Mihi->setObjectName(QStringLiteral("checkBox_Mihi"));

    formLayoutCochesVar->setWidget(3, QFormLayout::LabelRole, checkBox_Mihi);

    checkBox_mihi = new QCheckBox(layoutWidget);
    checkBox_mihi->setObjectName(QStringLiteral("checkBox_mihi"));

    formLayoutCochesVar->setWidget(3, QFormLayout::FieldRole, checkBox_mihi);

    checkBox_IJ = new QCheckBox(layoutWidget);
    checkBox_IJ->setObjectName(QStringLiteral("checkBox_IJ"));

    formLayoutCochesVar->setWidget(4, QFormLayout::LabelRole, checkBox_IJ);

    checkBox_ij = new QCheckBox(layoutWidget);
    checkBox_ij->setObjectName(QStringLiteral("checkBox_ij"));

    formLayoutCochesVar->setWidget(4, QFormLayout::FieldRole, checkBox_ij);

    checkBox_UV = new QCheckBox(layoutWidget);
    checkBox_UV->setObjectName(QStringLiteral("checkBox_UV"));

    formLayoutCochesVar->setWidget(5, QFormLayout::LabelRole, checkBox_UV);

    checkBox_uv = new QCheckBox(layoutWidget);
    checkBox_uv->setObjectName(QStringLiteral("checkBox_uv"));

    formLayoutCochesVar->setWidget(5, QFormLayout::FieldRole, checkBox_uv);

    checkBox_TICI = new QCheckBox(layoutWidget);
    checkBox_TICI->setObjectName(QStringLiteral("checkBox_TICI"));

    formLayoutCochesVar->setWidget(6, QFormLayout::LabelRole, checkBox_TICI);

    checkBox_tici = new QCheckBox(layoutWidget);
    checkBox_tici->setObjectName(QStringLiteral("checkBox_tici"));

    formLayoutCochesVar->setWidget(6, QFormLayout::FieldRole, checkBox_tici);

    checkBox_MPN = new QCheckBox(layoutWidget);
    checkBox_MPN->setObjectName(QStringLiteral("checkBox_MPN"));

    formLayoutCochesVar->setWidget(7, QFormLayout::LabelRole, checkBox_MPN);

    checkBox_mpn = new QCheckBox(layoutWidget);
    checkBox_mpn->setObjectName(QStringLiteral("checkBox_mpn"));

    formLayoutCochesVar->setWidget(7, QFormLayout::FieldRole, checkBox_mpn);

    checkBox_PH = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(8, QFormLayout::LabelRole, checkBox_PH);

    checkBox_ph = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(8, QFormLayout::FieldRole, checkBox_ph);

    label_tju = new QLabel(layoutWidget);
    label_tju->setObjectName(QStringLiteral("label_tju"));

    formLayoutCochesVar->setWidget(0, QFormLayout::FieldRole, label_tju);


    verticalLayoutConf->addLayout(formLayoutCochesVar);

    splitterVarGraph->addWidget(layoutWidget);
    splitter_2 = new QSplitter(splitterVarGraph);
    splitter_2->setObjectName(QStringLiteral("splitter_2"));
    splitter_2->setOrientation(Qt::Vertical);
    plainTextEditVariantes = new QPlainTextEdit(splitter_2);
    plainTextEditVariantes->setObjectName(QStringLiteral("plainTextEditVariantes"));
    plainTextEditVariantes->setReadOnly(true);
    splitter_2->addWidget(plainTextEditVariantes);
    layoutWidget1 = new QWidget(splitter_2);
    layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
    verticalLayout_4 = new QVBoxLayout(layoutWidget1);
    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setContentsMargins(11, 11, 11, 11);
    verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
    verticalLayout_4->setContentsMargins(0, 0, 0, 0);
    label_AutresVar = new QLabel(layoutWidget1);
    label_AutresVar->setObjectName(QStringLiteral("label_AutresVar"));

    verticalLayout_4->addWidget(label_AutresVar);

    plainTextEdit_AutresVar = new QPlainTextEdit(layoutWidget1);
    plainTextEdit_AutresVar->setObjectName(QStringLiteral("plainTextEdit_AutresVar"));

    verticalLayout_4->addWidget(plainTextEdit_AutresVar);

    splitter_2->addWidget(layoutWidget1);
    splitterVarGraph->addWidget(splitter_2);

    verticalLayout_5->addWidget(splitterVarGraph);

    tabWidget->addTab(tabVarGraph, QString());

    verticalLayout_9->addWidget(tabWidget);

// irr
        tabIrr = new QWidget();
        tabIrr->setObjectName(QStringLiteral("tabIrr"));
        verticalLayout_I = new QVBoxLayout(tabIrr);
        verticalLayout_I->setSpacing(6);
        verticalLayout_I->setContentsMargins(11, 11, 11, 11);
        verticalLayout_I->setObjectName(QStringLiteral("verticalLayout_7"));
        splitterIrr = new QSplitter(tabIrr);
        splitterIrr->setObjectName(QStringLiteral("splitterIrr"));
        splitterIrr->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitterIrr);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_IrrG = new QVBoxLayout(widget);
        verticalLayout_IrrG->setSpacing(6);
        verticalLayout_IrrG->setContentsMargins(11, 11, 11, 11);
        verticalLayout_IrrG->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        linLemmeIrr = new QLineEdit(widget);
        linLemmeIrr->setObjectName(QStringLiteral("linLemmeIrr"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, linLemmeIrr);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bInitMorpho = new QLineEdit(widget);
        bInitMorpho->setObjectName(QStringLiteral("bInitMorpho"));

        horizontalLayout_2->addWidget(bInitMorpho);

        bPlusMorpho = new QPushButton(widget);
        bPlusMorpho->setObjectName(QStringLiteral("bPlusMorpho"));

        horizontalLayout_2->addWidget(bPlusMorpho);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        linIrreg = new QLineEdit(widget);
        linIrreg->setObjectName(QStringLiteral("linIrreg"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, linIrreg);


        verticalLayout_IrrG->addLayout(formLayout_2);

        textBrowserMorphos = new QTextBrowser(widget);
        textBrowserMorphos->setObjectName(QStringLiteral("textBrowserMorphos"));

        verticalLayout_IrrG->addWidget(textBrowserMorphos);

        splitterIrr->addWidget(widget);
        widget1 = new QWidget(splitterIrr);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayoutIrrCentre = new QVBoxLayout(widget1);
        verticalLayoutIrrCentre->setSpacing(6);
        verticalLayoutIrrCentre->setContentsMargins(11, 11, 11, 11);
        verticalLayoutIrrCentre->setObjectName(QStringLiteral("verticalLayoutIrrCentre"));
        verticalLayoutIrrCentre->setContentsMargins(0, 0, 0, 0);
        spacerIrrHaut = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutIrrCentre->addItem(spacerIrrHaut);

        bAjIrr = new QPushButton(widget1);
        bAjIrr->setObjectName(QStringLiteral("bAjIrr"));

        verticalLayoutIrrCentre->addWidget(bAjIrr);

        bsupprIrr = new QPushButton(widget1);
        bsupprIrr->setObjectName(QStringLiteral("bsupprIrr"));

        verticalLayoutIrrCentre->addWidget(bsupprIrr);

        spacerIrrBas = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutIrrCentre->addItem(spacerIrrBas);

        splitterIrr->addWidget(widget1);
        textBrowserIrr = new QTextBrowser(splitterIrr);
        textBrowserIrr->setObjectName(QStringLiteral("textBrowserIrr"));
        splitterIrr->addWidget(textBrowserIrr);

        verticalLayout_I->addWidget(splitterIrr);

        tabWidget->addTab(tabIrr, QString());
// fin irr

    setCentralWidget(centralWidget);

    tabWidget->setCurrentIndex(0);

    // Menus et barre d'état


    mainToolBar = new QToolBar(this);
    mainToolBar->addAction(actionQuant);
    mainToolBar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, mainToolBar);

    menuBar = new QMenuBar(this);
    menuBar->setGeometry(QRect(0, 0, 1067, 19));
    menuFichier = new QMenu(menuBar);
    //menu_Aide = new QMenu(menuBar);
    setMenuBar(menuBar);

    statusBar = new QStatusBar(this);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    setStatusBar(statusBar);

    menuBar->addAction(menuFichier->menuAction());
    //menuBar->addAction(menu_Aide->menuAction());
    menuFichier->addSeparator();
    menuFichier->addAction(actionCopier);
    menuFichier->addAction(actionDiff);
    menuFichier->addAction(actionQuitter);
    mainToolBar->addAction(actionQuant);

    retranslateUi();

    // liste des lignes demandant des quantités
    lignes
        << lineEditGrq
        //<< lineEditInfectum
        << lineEditPerfectum
        << lineSupin;
    aaa << "aăā"
        << "eĕē"
        << "iĭī"
        << "oŏō"
        << "uŭū"
        << "yўȳ"
        << "AĂĀ"
        << "EĔĒ"
        << "IĬĪ"
        << "OŎŌ"
        << "UŬŪ"
        << "YЎȲ";
    peuple();
    connecte();
}

void MainWindow::retranslateUi()
{
    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    actionQuant->setText(QApplication::translate("MainWindow", "a\304\203\304\201", Q_NULLPTR));
    actionQuant->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", Q_NULLPTR));
    actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
    actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
    actionDiff->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer un fichier diff", Q_NULLPTR));
    actionCopier->setText(QApplication::translate("MainWindow", "copier un jeu de donn\303\251es", Q_NULLPTR));
    labelLemme->setText(QApplication::translate("MainWindow", "Lemme", Q_NULLPTR));
    bHomon->setText(QApplication::translate("MainWindow", "homon.", Q_NULLPTR));
    bSuppr->setText(QApplication::translate("MainWindow", "suppr.", Q_NULLPTR));
    labelGrq->setText(QApplication::translate("MainWindow", "Forme canonique, avec quantit\303\251s", Q_NULLPTR));
    checkBoxVb->setText(QApplication::translate("MainWindow", "verbe", Q_NULLPTR));
    labelModele->setText(QApplication::translate("MainWindow", "Mod\303\250le", Q_NULLPTR));
    labelPerfectum->setText(QApplication::translate("MainWindow", "rad. parfait", Q_NULLPTR));
    labelSupin->setText(QApplication::translate("MainWindow", "rad. supin", Q_NULLPTR));
    labelMorpho->setText(QApplication::translate("MainWindow", "morphologie", Q_NULLPTR));
    labelTr->setText(QApplication::translate("MainWindow", "traductions", Q_NULLPTR));
    boutonEnr->setText(QApplication::translate("MainWindow", "Enregistrer", Q_NULLPTR));
    boutonSuppr->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabLexique), QApplication::translate("MainWindow", "Lexique", Q_NULLPTR));
    label_3->setText(QApplication::translate("MainWindow", "Doc", Q_NULLPTR));
    btnPre->setText(QApplication::translate("MainWindow", "Pr\303\251analyse", Q_NULLPTR));
    labelVariante->setText(QApplication::translate("MainWindow", "variante", Q_NULLPTR));
    checkBoxAe->setText(QApplication::translate("MainWindow", "ae > e", Q_NULLPTR));
    checkBox_ae->setText(QString());
    checkBox_H->setText(QApplication::translate("MainWindow", "h > -", Q_NULLPTR));
    checkBox_h->setText(QString());
    checkBox_Mihi->setText(QApplication::translate("MainWindow", "mihi > michi", Q_NULLPTR));
    checkBox_mihi->setText(QString());
    checkBox_IJ->setText(QApplication::translate("MainWindow", "I > J", Q_NULLPTR));
    checkBox_ij->setText(QString());
    checkBox_UV->setText(QApplication::translate("MainWindow", "U > V", Q_NULLPTR));
    checkBox_uv->setText(QString());
    checkBox_TICI->setText(QApplication::translate("MainWindow", "ti > ci", Q_NULLPTR));
    checkBox_tici->setText(QString());
    checkBox_MPN->setText(QApplication::translate("MainWindow", "mn > mpn", Q_NULLPTR));
    checkBox_mpn->setText(QString());
    checkBox_PH->setText(QApplication::translate("MainWindow", "ph > f", Q_NULLPTR));
    checkBox_ph->setText(QString());
    label_tju->setText(QApplication::translate("MainWindow", "toujours utilis\303\251e", Q_NULLPTR));
    label_AutresVar->setText(QApplication::translate("MainWindow", "Autres variantes", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabVarGraph), QApplication::translate("MainWindow", "Variantes graphiques", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Lemme", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "forme irr\303\251guli\303\250re", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Morphologie", Q_NULLPTR));
        bPlusMorpho->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "r\303\251init", Q_NULLPTR));
        bAjIrr->setText(QApplication::translate("MainWindow", "ajouter >", Q_NULLPTR));
        bsupprIrr->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabIrr), QApplication::translate("MainWindow", "Irr\303\251guliers", Q_NULLPTR));
    menuFichier->setTitle(QApplication::translate("MainWindow", "&Fichier", Q_NULLPTR));
    //menu_Aide->setTitle(QApplication::translate("MainWindow", "&Aide", Q_NULLPTR));
}




MainWindow::~MainWindow()
{
}

QString MainWindow::cle(QString ligne)
{
    QString ret = ligne.section(QRegExp("[\\W]"),0,0);
    return Ch::atone(Ch::deramise(ret));
}

void MainWindow::copier()
{

	// vider data/
    QDir folder("data");
    folder.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
	QFileInfoList entrees = folder.entryInfoList();
    foreach(QFileInfo fileInfo, folder.entryInfoList())
	    for (int i=0;i<entrees.count();++i)
        {
		    QFileInfo fileInfo = entrees.at(i);
            if(fileInfo.isFile())
            {
                if(!QFile::remove(fileInfo.filePath()))
                    continue;
            }
        }
	// copie 
    QString nfc = QFileDialog::getExistingDirectory(this, "Collatinus - données à copier", "../");
    if (nfc.isEmpty()) return;
    // copier lemmes.la et lemmes.fr
    QFile::copy(nfc+"/lemmes.la", "data/lemmes.la");
    QFile::copy(nfc+"/lemmes.fr", "data/lemmes.fr");
    //QFile::copy(nfc+"/abreviations.la", "data/abreviations.la");
    QFile::copy(nfc+"/assimilations.la", "data/assimilations.la");
    QFile::copy(nfc+"/contractions.la", "data/contractions.la");
    QFile::copy(nfc+"/irregs.la", "data/irregs.la");
    QFile::copy(nfc+"/modeles.la", "data/modeles.la");
    QFile::copy(nfc+"/morphos.fr", "data/morphos.fr");
    // réinitialiser
    listeLemmesLa.clear();
    listeLemmesFr.clear();
    litems.clear();
    lmodeles.clear();
    comboBoxModele->clear();
    delete lemcore;
    delete completeur;
    peuple();
}

void MainWindow::connecte()
{
    // fichier
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(actionCopier, SIGNAL(triggered()), this, SLOT(copier()));
    // édition
    connect(checkBoxVb, SIGNAL(toggled(bool)), this, SLOT(lignesVisibles(bool)));
    connect(completeur, SIGNAL(activated(QString)), this, SLOT(edLem(QString)));
    connect(lineEditLemme, SIGNAL(textChanged(QString)), this, SLOT(edLem(QString)));
    connect(actionQuant, SIGNAL(triggered()), this, SLOT(rotQ()));
    connect(boutonEnr, SIGNAL(clicked()), this, SLOT(enr()));
    connect(boutonSuppr, SIGNAL(clicked()), this, SLOT(suppr()));
    connect(bSuppr, SIGNAL(clicked()), this, SLOT(suppr()));
    // màj de la flexion
    connect(lineEditGrq, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    connect(lineEditGrq, SIGNAL(textChanged(QString)), comboBoxModele, SLOT(show()));
    connect(comboBoxModele, SIGNAL(currentTextChanged(QString)), this, SLOT(ligneLa(QString)));
    connect(lineEditPerfectum, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    connect(lineSupin, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    // préanalyse
    connect(btnPre, SIGNAL(clicked()), this, SLOT(preAn()));
    connect(checkBoxAe, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_ae, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_H, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_h, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_Mihi, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_mihi, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_IJ, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_ij, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_UV, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_uv, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_TICI, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_tici, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_MPN, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_mpn, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_PH, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_ph, SIGNAL(clicked()), this, SLOT(coche()));
}

void MainWindow::edLem(QString l)
{
    if (litems.contains(l))
    {
        lemme = lemcore->lemme(l);
        textEditFlexion->setText(flexion->tableau(lemme));
        lineEditGrq->setText(lemme->champ0());
        comboBoxModele->show();
        comboBoxModele->setCurrentIndex(lemcore->lModeles().indexOf(lemme->grModele()));
        lineMorpho->setText(lemme->indMorph());
        lineEditTr->setText(lemme->traduction("fr"));
        // vider les lignes
        labelPerfectum->hide();
        lineEditPerfectum->hide();
        labelSupin->hide();
        lineSupin->hide();
        // radicaux
        for (int i=0;i<lemme->nbRadicaux();++i)
        {
            QList<Radical*> lr = lemme->radical(i);
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
                        // verbes, infectum
                        //lineEditInfectum->setText(grq);
                        //labelInfectum->show();
                        //lineEditInfectum->show();
                        break;
                    }
                case 1:
                    {
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
                        if (QString("vw").contains(lemme->pos()))
                        {
                            labelSupin->show();
                            lineSupin->show();
                            lineSupin->setText(grq);
                        }
                        break;
                    }
                case 3:
                    {
                        break;
                    }
                default:
                    {
                        break;
                    }
            }
        }
    }
    else
    {
        lemme = 0;
        // effacer les lignes
        lineEditGrq->clear();
        lineEditPerfectum->clear();
        lineSupin->clear();
        lineMorpho->clear();
        lineEditTr->clear();
        textEditFlexion->clear();
        comboBoxModele->hide();
        //comboBoxModele->setCurrentIndex(-1);
        // case à cocher verbe
        checkBoxVb->setChecked(l.endsWith("o")
                               || l.endsWith("or"));
    }
}

void MainWindow::enr()
{
    // radicaux et morphologie
    QString lc = lineEditLemme->text();
    QString linLa = ligneLa();
    QString ltr = lineEditTr->text();
    QString linFr = QString("%1:%2")
        .arg(lc)
        .arg(ltr);
    Lemme* lem = lemcore->lemme(lc);
    if (lem == 0)
    {
        lem = nLemme;
        // ajouter le lemme à la map _lemmes
        lemcore->ajLemme(lem);
        // màj des clés et des lignes à enregistrer
        // latin
        int i = indexOfInsert(linLa, listeLemmesLa);
        listeLemmesLa.insert(i, linLa);
        /*
           listeLemmesLa.append(linLa);
           std::sort(listeLemmesLa.begin(), listeLemmesLa.end(), Ch::sort_i);
         */
        enrLa();
        // français
        i = indexOfInsert(linFr, listeLemmesFr);
        listeLemmesFr.insert(i, linFr);
        /*
           listeLemmesFr.append(linFr);
           std::sort(listeLemmesFr.begin(), listeLemmesFr.end(), Ch::sort_i);
         */
        enrFr();
        qDebug()<<"enrfr ok";
        // màj du compléteur
        litems.append(lc);
        modele.setStringList(litems);
        completeur->setModel(&modele);
        qDebug()<<"::enr ok";
        return;
    }
    if (nLemme == 0) return;
    if (lemme != 0 && nLemme != 0)
    {
        lemcore->remplaceLemme(lemme, nLemme);
        lemme = nLemme;
    }
    QString tr = lem->traduction("fr");
    // enregistrement dans lemmes.la
    for (int i=0;i<listeLemmesLa.count();++i)
    {
        QString ligne = listeLemmesLa.at(i);
        QString cle = this->cle(ligne);
        //QString l = listeLemmesLa.at(i).section(QRegExp("[\\W]"),0,0);
        //QString cle = Ch::atone(Ch::deramise(l));
        if (lem->cle() == cle)
        {
            listeLemmesLa[i] = linLa;
            // enregistrer
            enrLa();
            break;
        }
    }
    // traductions
    int i = 0;
    QString lcl = lc.toLower();
    while(i<listeLemmesFr.count())
    {
        QString l = listeLemmesFr.at(i).section(':',0,0);
        if (l >= lcl)
        {
            if (l == lc && ltr != tr)
            {
                listeLemmesFr[i] = QString("%1:%2")
                    .arg(l)
                    .arg(ltr);
            }
            else if (l > lcl)
            {
                if (i > 0) --i;
                listeLemmesFr.insert(i, QString("%1:%2")
                                     .arg(lc)
                                     .arg(ltr));
            }
            // enregistrer
            enrFr();
            /*
               QFile f("data/lemmes.fr");
               f.remove();
               f.open(QFile::WriteOnly);
               QTextStream flux(&f);
               for (int j=0;j<listeLemmesFr.count();++j)
               flux << listeLemmesFr.at(j)+'\n';
               f.close();
             */
            break;
        }
        ++i;
    }
}

void MainWindow::enrLa()
{
    QFile f("data/lemmes.la");
    f.remove();
    f.open(QFile::WriteOnly);
    QTextStream flux(&f);
    for (int j=0;j<listeLemmesLa.count();++j)
        flux << listeLemmesLa.at(j)<<'\n';
    f.close();
    qDebug()<<"fin enrLa";
}

void MainWindow::enrFr()
{
    QFile f("data/lemmes.fr");
    f.remove();
    f.open(QFile::WriteOnly);
    QTextStream flux(&f);
    for (int j=0;j<listeLemmesFr.count();++j)
        flux << listeLemmesFr.at(j)+'\n';
    f.close();
}

int MainWindow::indexOfInsert(QString s, QStringList l)
{
    s = s.toLower();
    for (int i=0;i<l.count();++i)
    {
        QString lin = l.at(i);
		if (lin.startsWith("!")) continue;
        lin = Ch::atone(lin).toLower();
        if (lin >= s)
            return i;
    }
    return l.count();
}

QString MainWindow::ligneLa(QString modl)
{
    // construire la clé en ajoutant le n° d'homonymie + grq
    // en cas de nouveau lemme, l'utilisateur ajoute ce n°
    if (modl.isEmpty()) modl = comboBoxModele->currentText();
    QString grq = lineEditGrq->text();
    if (grq.isEmpty()) return "";
    QChar d = Ch::der(grq);
    if (d.isDigit()) grq.append(d);
    int nbOcc = 1;
    if (lemme != 0) nbOcc = lemme->nbOcc();
    //QString GabaritLa = "%1|%2|%3|%4|%5|%6";
    QString ret = GabaritLa
        .arg(grq)
        .arg(modl)
        .arg(lineEditPerfectum->text())
        .arg(lineSupin->text())
        .arg(lineMorpho->text())
        .arg(nbOcc);
    nLemme = new Lemme(ret, 0, lemcore);
    nLemme->setCle(lineEditLemme->text());
    textEditFlexion->setText(flexion->tableau(nLemme));
    return ret;
}

void MainWindow::lignesVisibles(bool v)
{
    if (v)
    {
        labelPerfectum->setText("rad. perfectum");
        labelSupin->show();
        lineSupin->show();
    }
    else
    {
        labelPerfectum->setText("rad. génitif");
        labelSupin->hide();
        lineSupin->hide();
    }
}

QString MainWindow::ligneFr()
{
    return QString("%1|%2")
        .arg(lineEditLemme->text())
        .arg(lineEditTr->text());
}

QStringList MainWindow::lisLignes(QString nf)
{
    QFile f(nf);
    f.open(QFile::ReadOnly);
    QTextStream flux(&f);
    flux.setCodec("UTF-8"); // Pour windôze !
    QStringList retour;
    while (!flux.atEnd())
    {
        retour.append(flux.readLine());
    }
    f.close();
    return retour;
}

void MainWindow::peuple()
{
    lemcore = new LemCore(this);
    flexion = new Flexion(lemcore);
    // lemmes
    litems = lemcore->cles();
    qSort(litems.begin(), litems.end(), Ch::sort_i);
    listeLemmesLa = lisLignes("data/lemmes.la");
    listeLemmesFr = lisLignes("data/lemmes.fr");
    // compléteur lemmes
	completeur = new QCompleter;
    modele.setStringList(litems);
    completeur->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    completeur->setModel(&modele);
    completeur->setMaxVisibleItems(litems.count());
    QStringListModel* modele = new QStringListModel(litems, completeur);
    completeur->setModel(modele);
    lineEditLemme->setCompleter(completeur);
    // modèles
    lmodeles = lemcore->lModeles();
    comboBoxModele->addItems(lmodeles);
    //qSort(listeLemmesFr.begin(), listeLemmesFr.end(), Ch::sort_i);
    //qSort(listeLemmesLa.begin(), listeLemmesLa.end(), Ch::sort_i);
}

void MainWindow::rotQ()
{
    for (int i=0;i<lignes.count();++i)
    {
        if (lignes.at(i)->hasFocus())
        {
            QString texte = lignes.at(i)->text();
            if (texte.isEmpty()) return;
            int cp = lignes.at(i)->cursorPosition()-1;
            QChar car = texte.at(cp);
            for (int j=0;j<aaa.count();++j)
            {
                QString vvv = aaa.at(j);
                int p = vvv.indexOf(car);
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
                    texte[cp] = vvv.at(p);
                    lignes.at(i)->setText(texte);
                    lignes.at(i)->setCursorPosition(cp+1);
                    return;
                }
            }
            break;
        }
    }
}

void MainWindow::suppr()
{
    if (lemme == 0) return;
    QString cle = lemme->cle();
    // litems
    litems.removeAt(litems.indexOf(cle));
    // listeLemmesLa
    for (int i=0;i<listeLemmesLa.count();++i)
    {
        QString l = listeLemmesLa.at(i).section(QRegExp("[\\W]"),0,0);
        l = Ch::atone(Ch::deramise(l));
        if (l == cle)
        {
            listeLemmesLa.removeAt(i);
            enrLa();
            break;
        }
    }

    for(int i=0; i<listeLemmesFr.count(); ++i)
    {
        QString l = listeLemmesFr.at(i).section(':',0,0);
        if (l == cle)
        {
            listeLemmesFr.removeAt(i);
            enrFr();
            break;
        }
    }
}
