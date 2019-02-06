/*   mainwindow.cpp
 *
 *  This file is part of EDITCOL.
 *
 *  EDITCOL is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  EDITCOL is distributed in the hope that it will be useful,
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

/*

   FIXME
    
    - Revoir le classement alphabétique du lemmes.la du module
    - Retours arrière : Quand on tombe à l'intérieur d'un mot, la 
      fin du mot n'est pas recherchée.
    - L'ajout d'irrégulier n'est pas dynamique

   TODO
/  - première utilisation : ouvrir l'onglet module, donner une marche à
     suivre dans le label d'info.
   - prendre les listes dans LemCore plutôt que dans les fichiers.
     (seulement pour irregs).
   - suppression d'un lemme : trouver une syntaxe
     prévoir une gestion des lignes lemmes commentées
   - rendre l'homonymie de la clé plus ergonomique
 */

#include <QFileDialog>
#include <QMessageBox>
#include <quazip/quazip.h>
#include <quazip/quazipfile.h>
#include <mainwindow.h>

MainWindow::MainWindow()
{
    // actions
    actionArr       = new QAction(this);
    actionArrArr    = new QAction(this);
    actionQuant     = new QAction(this);
    actionDebut     = new QAction(this);
    actionDiff      = new QAction(this);
    actionEchecPrec = new QAction(this);
    actionEchecSuiv = new QAction(this);
    actionOuvrir    = new QAction(this);
    actionQuitter   = new QAction(this);
    // ui
    centralWidget = new QWidget(this);
    verticalLayout = new QVBoxLayout(centralWidget);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    // label d'info sur les lexiques
    labelInfo = new QLabel(centralWidget);
    verticalLayout->addWidget(labelInfo);
    // conteneur des onglets
    tabWidget = new QTabWidget(centralWidget);

    // onglet Lexique
    tabLexique = new QWidget();
    verticalLayout_Lex = new QVBoxLayout(tabLexique);
    verticalLayout_Lex->setSpacing(6);
    verticalLayout_Lex->setContentsMargins(11, 11, 11, 11);
    splitter = new QSplitter(tabLexique);
    splitter->setMouseTracking(false);
    splitter->setFrameShape(QFrame::NoFrame);
    splitter->setOrientation(Qt::Horizontal);
    frame = new QFrame(splitter);
    frame->setFrameShape(QFrame::Box);
    verticalLayout_3 = new QVBoxLayout(frame);
    verticalLayout_3->setSpacing(6);
    verticalLayout_3->setContentsMargins(11, 11, 11, 11);
    labelContexte = new QLabel(frame);
    labelContexte->setWordWrap(true);
    labelContexte->setTextFormat(Qt::RichText);
    verticalLayout_3->addWidget(labelContexte);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    labelLemme = new QLabel(frame);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelLemme->sizePolicy().hasHeightForWidth());
    labelLemme->setSizePolicy(sizePolicy);
    labelLemme->setMaximumSize(QSize(16777215, 50));
    horizontalLayout->addWidget(labelLemme);
    lineEditLemme = new QLineEdit(frame);
    horizontalLayout->addWidget(lineEditLemme);
    verticalLayout_3->addLayout(horizontalLayout);
    // layout boutons
    horizontalLayoutBtns = new QHBoxLayout();
    bSuppr = new QPushButton(frame);
    horizontalLayoutBtns->addWidget(bSuppr);
    bEchecPrec = new QToolButton();
    bEchecPrec->setDefaultAction(actionEchecPrec);
    horizontalLayoutBtns->addWidget(bEchecPrec);
    bEchecSuiv = new QToolButton();
    bEchecSuiv->setDefaultAction(actionEchecSuiv);
    horizontalLayoutBtns->addWidget(bEchecSuiv);
    bArr    = new QToolButton();
    bArr->setDefaultAction(actionArr);
    bArrArr = new QToolButton();
    bArrArr->setDefaultAction(actionArrArr);
    bDebut  = new QToolButton();
    bDebut->setDefaultAction(actionDebut);
    horizontalLayoutBtns->addWidget(bArr);
    horizontalLayoutBtns->addWidget(bArrArr);
    horizontalLayoutBtns->addWidget(bDebut);
    verticalLayout_3->addLayout(horizontalLayoutBtns);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout_3->addItem(verticalSpacer_2);
    splitter->addWidget(frame);
    frame1 = new QFrame(splitter);
    frame1->setFrameShape(QFrame::Box);
    verticalLayout_2 = new QVBoxLayout(frame1);
    verticalLayout_2->setSpacing(6);
    verticalLayout_2->setContentsMargins(11, 11, 11, 11);
    formLayout = new QFormLayout();
    formLayout->setSpacing(6);
    labelGrq = new QLabel(frame1);
    formLayout->setWidget(0, QFormLayout::LabelRole, labelGrq);
    horizontalLayout_grq = new QHBoxLayout();
    horizontalLayout_grq->setSpacing(6);
    lineEditGrq = new QLineEdit(frame1);
    horizontalLayout_grq->addWidget(lineEditGrq);
    //checkBoxVb = new QCheckBox(frame1);
    //horizontalLayout_grq->addWidget(checkBoxVb);
    formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_grq);
    labelModele = new QLabel(frame1);
    labelModele->setLayoutDirection(Qt::LeftToRight);
    labelModele->setScaledContents(false);
    labelModele->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    formLayout->setWidget(1, QFormLayout::LabelRole, labelModele);
    comboBoxModele = new QComboBox(frame1);
    formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxModele);
    labelPerfectum = new QLabel(frame1);
    formLayout->setWidget(2, QFormLayout::LabelRole, labelPerfectum);
    lineEditPerfectum = new QLineEdit(frame1);
    formLayout->setWidget(2, QFormLayout::FieldRole, lineEditPerfectum);
    labelSupin = new QLabel(frame1);
    labelSupin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    formLayout->setWidget(3, QFormLayout::LabelRole, labelSupin);
    lineSupin = new QLineEdit(frame1);
    formLayout->setWidget(3, QFormLayout::FieldRole, lineSupin);
    labelMorpho = new QLabel(frame1);
    formLayout->setWidget(4, QFormLayout::LabelRole, labelMorpho);
    lineMorpho = new QLineEdit(frame1);
    formLayout->setWidget(4, QFormLayout::FieldRole, lineMorpho);
    labelTr = new QLabel(frame1);
    formLayout->setWidget(5, QFormLayout::LabelRole, labelTr);
    lineEditTr = new QLineEdit(frame1);
    formLayout->setWidget(5, QFormLayout::FieldRole, lineEditTr);
    verticalLayout_2->addLayout(formLayout);
    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    boutonEnr = new QPushButton(frame1);
    horizontalLayout_3->addWidget(boutonEnr);
    boutonSuppr = new QPushButton(frame1);
    horizontalLayout_3->addWidget(boutonSuppr);
    boutonLemSuiv = new QPushButton(frame1);
    horizontalLayout_3->addWidget(boutonLemSuiv);
    verticalLayout_2->addLayout(horizontalLayout_3);
    textEditFlexion = new QTextEdit(frame1);
    textEditFlexion->setReadOnly(true);
    verticalLayout_2->addWidget(textEditFlexion);
    splitter->addWidget(frame1);
    verticalLayout_Lex->addWidget(splitter);
    tabWidget->addTab(tabLexique, QString());

    // onglet variantes graphiques
    tabVarGraph = new QWidget();
    verticalLayout_5 = new QVBoxLayout(tabVarGraph);
    verticalLayout_5->setSpacing(6);
    verticalLayout_5->setContentsMargins(11, 11, 11, 11);
    splitterVarGraph = new QSplitter(tabVarGraph);
    splitterVarGraph->setOrientation(Qt::Horizontal);
    layoutWidget = new QWidget(splitterVarGraph);
    verticalLayoutConf = new QVBoxLayout(layoutWidget);
    verticalLayoutConf->setSpacing(6);
    verticalLayoutConf->setContentsMargins(11, 11, 11, 11);
    verticalLayoutConf->setContentsMargins(0, 0, 0, 0);
    label_3 = new QLabel(layoutWidget);
    verticalLayoutConf->addWidget(label_3);
    // test de lemmatisation
    horizontalLayoutTest = new QHBoxLayout();
    horizontalLayoutTest->setSpacing(6);
    labelTest = new QLabel(layoutWidget);
    horizontalLayoutTest->addWidget(labelTest);
    lineEditTest = new QLineEdit(layoutWidget);
    horizontalLayoutTest->addWidget(lineEditTest);
    labelLemTest = new QLabel(layoutWidget);
    horizontalLayoutTest->addWidget(labelLemTest);
    verticalLayoutConf->addLayout(horizontalLayoutTest);
    // bouton de préanalyse
    horizontalLayoutBtnPre = new QHBoxLayout();
    horizontalLayoutBtnPre->setSpacing(6);
    btnPre = new QPushButton(layoutWidget);
    horizontalLayoutBtnPre->addWidget(btnPre);
    horizontalSpacerPre = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayoutBtnPre->addItem(horizontalSpacerPre);
    verticalLayoutConf->addLayout(horizontalLayoutBtnPre);
    formLayoutCochesVar = new QFormLayout();
    formLayoutCochesVar->setSpacing(6);
    formLayoutCochesVar->setContentsMargins(13, 13, -1, -1);
    labelVariante = new QLabel(layoutWidget);
    formLayoutCochesVar->setWidget(0, QFormLayout::LabelRole, labelVariante);
    checkBoxAe = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(1, QFormLayout::LabelRole, checkBoxAe);
    checkBox_H = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(2, QFormLayout::LabelRole, checkBox_H);
    checkBox_Mihi = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(3, QFormLayout::LabelRole, checkBox_Mihi);
    checkBox_IJ = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(4, QFormLayout::LabelRole, checkBox_IJ);
    checkBox_UV = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(5, QFormLayout::LabelRole, checkBox_UV);
    checkBox_TICI = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(6, QFormLayout::LabelRole, checkBox_TICI);
    checkBox_MPN = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(7, QFormLayout::LabelRole, checkBox_MPN);
    checkBox_PH = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(8, QFormLayout::LabelRole, checkBox_PH);
    verticalLayoutConf->addLayout(formLayoutCochesVar);
    splitterVarGraph->addWidget(layoutWidget);
    splitter_2 = new QSplitter(splitterVarGraph);
    splitter_2->setOrientation(Qt::Vertical);
    plainTextEditVariantes = new QPlainTextEdit(splitter_2);
    splitter_2->addWidget(plainTextEditVariantes);
    layoutWidget1 = new QWidget(splitter_2);
    verticalLayout_4 = new QVBoxLayout(layoutWidget1);
    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setContentsMargins(11, 11, 11, 11);
    verticalLayout_4->setContentsMargins(0, 0, 0, 0);
    btnEnrVar = new QPushButton(layoutWidget1);
    verticalLayout_4->addWidget(btnEnrVar);
    splitter_2->addWidget(layoutWidget1);
    splitterVarGraph->addWidget(splitter_2);
    verticalLayout_5->addWidget(splitterVarGraph);
    tabWidget->addTab(tabVarGraph, QString());
    verticalLayout->addWidget(tabWidget);

    // onglet irréguliers
    tabIrr = new QWidget();
    verticalLayout_I = new QVBoxLayout(tabIrr);
    verticalLayout_I->setSpacing(6);
    verticalLayout_I->setContentsMargins(11, 11, 11, 11);
    splitterIrr = new QSplitter(tabIrr);
    splitterIrr->setOrientation(Qt::Horizontal);
    widget = new QWidget(splitterIrr);
    verticalLayout_Irr = new QVBoxLayout(widget);
    verticalLayout_Irr->setSpacing(6);
    verticalLayout_Irr->setContentsMargins(11, 11, 11, 11);
    verticalLayout_Irr->setContentsMargins(0, 0, 0, 0);
    formLayout_2 = new QFormLayout();
    formLayout_2->setSpacing(6);
    labelLemmeIrr = new QLabel(widget);
    formLayout_2->setWidget(0, QFormLayout::LabelRole, labelLemmeIrr);
    linLemmeIrr = new QLineEdit(widget);
    formLayout_2->setWidget(0, QFormLayout::FieldRole, linLemmeIrr);
    linIrreg = new QLineEdit(widget);
    formLayout_2->setWidget(1, QFormLayout::FieldRole, linIrreg);
    lineEditNumMorpho = new QLineEdit(widget);
    formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEditNumMorpho);
    labelNumMorpho = new QLabel(widget);
    formLayout_2->setWidget(2, QFormLayout::LabelRole, labelNumMorpho);
    verticalLayout_Irr->addLayout(formLayout_2);
    listWidgetMorphos = new QListWidget(widget);
    listWidgetMorphos->setSelectionMode(QAbstractItemView::ExtendedSelection);
    verticalLayout_Irr->addWidget(listWidgetMorphos);
    labelFormeIrr = new QLabel(widget);
    formLayout_2->setWidget(1, QFormLayout::LabelRole, labelFormeIrr);
    labelMorphoIrr = new QLabel(widget);
    formLayout_2->setWidget(3, QFormLayout::LabelRole, labelMorphoIrr);
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    btnPers = new QToolButton(widget);
    btnCas = new QToolButton(widget);
    btnGenre = new QToolButton(widget);
    btnNb = new QToolButton(widget);
    btnTps = new QToolButton(widget);
    btnMod = new QToolButton(widget);
    btnVx = new QToolButton(widget);
    btnAj = new QToolButton(widget);
    horizontalLayout_2->addWidget(btnPers);
    horizontalLayout_2->addWidget(btnCas);
    horizontalLayout_2->addWidget(btnGenre);
    horizontalLayout_2->addWidget(btnNb);
    horizontalLayout_2->addWidget(btnMod);
    horizontalLayout_2->addWidget(btnTps);
    horizontalLayout_2->addWidget(btnVx);
    horizontalLayout_2->addWidget(btnAj);
    formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout_2);
    splitterIrr->addWidget(widget);
    widgetM = new QWidget(splitterIrr);
    verticalLayoutIrrCentre = new QVBoxLayout(widgetM);
    verticalLayoutIrrCentre->setSpacing(6);
    verticalLayoutIrrCentre->setContentsMargins(11, 11, 11, 11);
    verticalLayoutIrrCentre->setContentsMargins(0, 0, 0, 0);
    spacerIrrHaut = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayoutIrrCentre->addItem(spacerIrrHaut);
    bAjIrr = new QPushButton(widgetM);
    verticalLayoutIrrCentre->addWidget(bAjIrr);
    bsupprIrr = new QPushButton(widgetM);
    verticalLayoutIrrCentre->addWidget(bsupprIrr);
    spacerIrrBas = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayoutIrrCentre->addItem(spacerIrrBas);
    splitterIrr->addWidget(widgetM);
    listWidgetIrr = new QListWidget(splitterIrr);
    splitterIrr->addWidget(listWidgetIrr);
    verticalLayout_I->addWidget(splitterIrr);
    tabWidget->addTab(tabIrr, QString());

    // onglet Modules
    tabM = new QWidget();
    verticalLayoutM = new QVBoxLayout(tabM);
    verticalLayoutM->setSpacing(6);
    verticalLayoutM->setContentsMargins(11, 11, 11, 11);
    splitterM = new QSplitter(tabM);
    splitterM->setOrientation(Qt::Horizontal);
    widget = new QWidget(splitterM);
    verticalLayoutLM = new QVBoxLayout(widget);
    verticalLayoutLM->setSpacing(6);
    verticalLayoutLM->setContentsMargins(11, 11, 11, 11);
    verticalLayoutLM->setContentsMargins(0, 0, 0, 0);
    labelM = new QLabel(widget);
    verticalLayoutLM->addWidget(labelM);
    listWidgetM = new QListWidget(widget);
    listWidgetM->setSelectionMode(QAbstractItemView::SingleSelection);
    verticalLayoutLM->addWidget(listWidgetM);
    splitterM->addWidget(widget);
    widgetM = new QWidget(splitterM);
    verticalLayoutD = new QVBoxLayout(widgetM);
    verticalLayoutD->setSpacing(6);
    verticalLayoutD->setContentsMargins(11, 11, 11, 11);
    horizontalLayoutM = new QHBoxLayout();
    horizontalLayoutM->setSpacing(6);
    lineEditM = new QLineEdit(widgetM);
    horizontalLayoutM->addWidget(lineEditM);
    pushButtonCreeM = new QPushButton(widgetM);
    horizontalLayoutM->addWidget(pushButtonCreeM);
    verticalLayoutD->addLayout(horizontalLayoutM);
    pushButtonActM = new QPushButton(widgetM);
    verticalLayoutD->addWidget(pushButtonActM);
    pushButtonDesactM = new QPushButton(widgetM);
    verticalLayoutD->addWidget(pushButtonDesactM);
    pushButtonSupprM = new QPushButton(widgetM);
    verticalLayoutD->addWidget(pushButtonSupprM);
    pushButtonPaquet = new QPushButton(widgetM);
    verticalLayoutD->addWidget(pushButtonPaquet);
    pushButtonInstM = new QPushButton(widgetM);
    verticalLayoutD->addWidget(pushButtonInstM);
    labelInfoM = new QLabel(widgetM);
    verticalLayoutD->addWidget(labelInfoM);
    verticalSpacerM = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayoutD->addItem(verticalSpacerM);
    splitterM->addWidget(widgetM);
    verticalLayoutM->addWidget(splitterM);
    tabWidget->addTab(tabM, QString());
    // intégration et index courant
    setCentralWidget(centralWidget);
    tabWidget->setCurrentIndex(0);
    // barre d'outils
    mainToolBar = new QToolBar(this);
    mainToolBar->addAction(actionOuvrir);
    mainToolBar->addAction(actionQuant);
    //mainToolBar->addAction(actionEchecSuiv);
    mainToolBar->addAction(actionQuitter);
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    // barre de menu
    menuBar = new QMenuBar(this);
    menuBar->setGeometry(QRect(0, 0, 1067, 19));
    menuFichier = new QMenu(menuBar);
    setMenuBar(menuBar);
    menuBar->addAction(menuFichier->menuAction());
    //menu_Aide = new QMenu(menuBar);
    //menuBar->addAction(menu_Aide->menuAction());
    menuFichier->addSeparator();
    menuFichier->addAction(actionDiff);
    menuFichier->addAction(actionOuvrir);
    mainToolBar->addAction(actionQuant);
    menuFichier->addAction(actionQuitter);
    // bare d'état
    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    // textes
    retranslateUi();
    QSettings settings("Collatinus", "ecce");
    // état de la fenêtre
    settings.beginGroup("fenetre");
    restoreGeometry(settings.value("geometry").toByteArray());
    //restoreState(settings.value("windowState").toByteArray());
    settings.endGroup();
    // dernier fichier chargé
    settings.beginGroup("fichiers");
    fichier = settings.value("fichier", "").toString();
    posFC = settings.value("signet","0").toLongLong();
    forme = settings.value("forme", "").toString();
    settings.endGroup();
    settings.beginGroup("lexique");
    module = settings.value("module", "").toString();
    if (!fichier.isEmpty())
    {
        ouvrir(fichier, posFC);
    }
    settings.endGroup();

    // liste des lignes demandant des quantités
    lignes
        << lineEditGrq
        << lineEditPerfectum
        << lineSupin
        << linIrreg;
    // voyelles avec quantité Ctrl+W
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

/*
void MainWindow::reserve()
{
    lemme = lemcore->lemmeDisque(lineEditLemme->text());
    if (lemme != 0)
    {
        edLem("-reserve");
        lineEditTr->setText(lemcore->trDisque(lemme->cle()));
    }
}
*/

void MainWindow::retranslateUi()
{
    setWindowTitle(QApplication::translate("Collatinus", "Ecce", Q_NULLPTR));
    actionDiff->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer un fichier diff", Q_NULLPTR));
    actionEchecPrec->setText(QApplication::translate("MainWindow", "\303\251chec précédent", Q_NULLPTR));
    actionEchecPrec->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
    actionEchecSuiv->setText(QApplication::translate("MainWindow", "\303\251chec suivant", Q_NULLPTR));
    actionEchecSuiv->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
    actionArr->setText("<");
    actionArrArr->setText("<<");
    actionDebut->setText(QApplication::translate("MainWindow","début", Q_NULLPTR));
    actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir un fichier texte"));
    actionOuvrir->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
    actionQuant->setText(QApplication::translate("MainWindow", "a\304\203\304\201", Q_NULLPTR));
    actionQuant->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", Q_NULLPTR));
    actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
    actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
    labelInfo->setText(QApplication::translate("MainWindow",
                                               "Ecce - chargement…", Q_NULLPTR));
    labelLemme->setText(QApplication::translate("MainWindow", "Lemme", Q_NULLPTR));
    //bHomon->setText(QApplication::translate("MainWindow", "homon.", Q_NULLPTR));
    bSuppr->setText(QApplication::translate("MainWindow", "suppr.", Q_NULLPTR));
    labelGrq->setText(QApplication::translate("MainWindow", "Forme canonique, avec quantit\303\251s", Q_NULLPTR));
    //checkBoxVb->setText(QApplication::translate("MainWindow", "verbe", Q_NULLPTR));
    labelModele->setText(QApplication::translate("MainWindow", "Mod\303\250le", Q_NULLPTR));
    labelPerfectum->setText(QApplication::translate("MainWindow", "rad. parfait", Q_NULLPTR));
    labelSupin->setText(QApplication::translate("MainWindow", "rad. supin", Q_NULLPTR));
    labelMorpho->setText(QApplication::translate("MainWindow", "morphologie", Q_NULLPTR));
    labelTr->setText(QApplication::translate("MainWindow", "traductions", Q_NULLPTR));
    boutonEnr->setText(QApplication::translate("MainWindow", "Enregistrer", Q_NULLPTR));
    boutonSuppr->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
    boutonLemSuiv->setText(QApplication::translate("MainWindow", "lemme suivant", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabLexique),
                          QApplication::translate("MainWindow", "Lexique", Q_NULLPTR));
    label_3->setText(docVarGraph);
    labelTest->setText("lemmatiser");
    btnPre->setText(QApplication::translate("MainWindow", "Pr\303\251analyse", Q_NULLPTR));
    labelVariante->setText(QApplication::translate("MainWindow", "variante", Q_NULLPTR));
    checkBoxAe->setText(QApplication::translate("MainWindow", "ae > e", Q_NULLPTR));
    checkBox_H->setText(QApplication::translate("MainWindow", "h > -", Q_NULLPTR));
    checkBox_Mihi->setText(QApplication::translate("MainWindow", "mihi > michi", Q_NULLPTR));
    checkBox_IJ->setText(QApplication::translate("MainWindow", "I > J", Q_NULLPTR));
    checkBox_UV->setText(QApplication::translate("MainWindow", "U > V", Q_NULLPTR));
    checkBox_TICI->setText(QApplication::translate("MainWindow", "ti > ci", Q_NULLPTR));
    checkBox_MPN->setText(QApplication::translate("MainWindow", "mn > mpn", Q_NULLPTR));
    checkBox_PH->setText(QApplication::translate("MainWindow", "ph > f", Q_NULLPTR));
    btnEnrVar->setText(QApplication::translate("MainWindow", "enregistrer", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabVarGraph),
                          QApplication::translate("MainWindow", "Variantes graphiques", Q_NULLPTR));
    labelLemmeIrr->setText(QApplication::translate("MainWindow", "Lemme", Q_NULLPTR));
    labelFormeIrr->setText(QApplication::translate("MainWindow",
                                                   "forme irr\303\251guli\303\250re", Q_NULLPTR));
    labelMorphoIrr->setText(QApplication::translate("MainWindow", "rech. morpho", Q_NULLPTR));
    labelNumMorpho->setText(QApplication::translate("MainWindow", "num. morpho", Q_NULLPTR));
    btnPers->setText(QApplication::translate("MainWindow","pers"));
    btnCas->setText(QApplication::translate("MainWindow","cas"));
    btnGenre->setText(QApplication::translate("MainWindow","genre"));
    btnNb->setText(QApplication::translate("MainWindow", "nb"));
    btnTps->setText(QApplication::translate("MainWindow", "tps"));
    btnMod->setText(QApplication::translate("MainWindow", "mod"));
    btnVx->setText(QApplication::translate("MainWindow", "vx"));
    btnAj->setText(QApplication::translate("MainWindow", "^", Q_NULLPTR));
    bAjIrr->setText(QApplication::translate("MainWindow", " > ", Q_NULLPTR));
    bsupprIrr->setText(QApplication::translate("MainWindow", " x ", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabIrr),
                          QApplication::translate("MainWindow", "&irr\303\251guliers", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabM),
                          QApplication::translate("MainWindow", "Modules lexicaux", Q_NULLPTR));
    labelM->setText(QApplication::translate("MainWindow", "modules", Q_NULLPTR));
    pushButtonCreeM->setText(QApplication::translate("MainWindow", "Cr\303\251er un module ", Q_NULLPTR));
    pushButtonActM->setText(QApplication::translate("MainWindow", "activer ce module", Q_NULLPTR));
    pushButtonDesactM->setText(QApplication::translate("MainWindow",
                                                       "d\303\251sactiver le module courant", Q_NULLPTR));
    pushButtonSupprM->setText(QApplication::translate("MainWindow", "supprimer ce module", Q_NULLPTR));
    pushButtonPaquet->setText(QApplication::translate("MainWindow", "générer un paquet", Q_NULLPTR));
    pushButtonInstM->setText(QApplication::translate("MainWindow", "installer un paquet", Q_NULLPTR));
    labelInfoM->setText("info modules");

    menuFichier->setTitle(QApplication::translate("MainWindow", "&Fichier", Q_NULLPTR));
    //menu_Aide->setTitle(QApplication::translate("MainWindow", "&Aide", Q_NULLPTR));
}




MainWindow::~MainWindow()
{
}

void MainWindow::activerM()
{
    QListWidgetItem* item = listWidgetM->currentItem();
    module = item->text();
    QSettings settings("Collatinus", "ecce");
    settings.beginGroup("lexique");
    settings.setValue("module", module);
    settings.endGroup();
    // recharger toutes les données
    reinit();
}

void MainWindow::ajIrr()
{
    QString lin = QString("%1:%2:%3")
        .arg(linIrreg->text())
        .arg(linLemmeIrr->text())
        .arg(lineEditNumMorpho->text());
    //insereLigne(lin, ajDir+"irregs.la");
    editModule(linIrreg->text(), lin, ajDir+"irregs.la");
}

// ajoute les nْ° des morphos sélectionnées à la forme irrégulière
void MainWindow::ajMorph()
{
    QList<QListWidgetItem*> liste = listWidgetMorphos->selectedItems();
    for (int i=0;i<liste.count();++i)
    {
        QListWidgetItem *item = liste.at(i);
        int n = lMorphos.key(item->text());
        QStringList lm = lineEditNumMorpho->text().split(',', QString::SkipEmptyParts);
        lm.append(QString::number(n));
        lineEditNumMorpho->setText(lm.join(','));
    }
}

void MainWindow::arr()
{
    posFC -= 200;
    if (posFC < 0) posFC = 0;
    QTextStream flux(&fCorpus);
    flux.seek(posFC);
    QChar c='\0';
    do flux >> c; while (c.isLetter());
    posFC = flux.pos();
    while (!echecs.isEmpty() && echecs.last() > posFC)
        echecs.removeLast();
    forme.clear();
    labelContexte->setText(contexte(posFC, ""));
    majInfo();
}

void MainWindow::arrArr()
{
    posFC = posFC / 2;
    QTextStream flux(&fCorpus);
    flux.seek(posFC);
    QChar c='\0';
    do flux >> c; while (c.isLetter());
    posFC = flux.pos();
    while (!echecs.isEmpty() && echecs.last() > posFC)
        echecs.removeLast();
    forme.clear();
    labelContexte->setText(contexte(posFC, ""));
    majInfo();
}

QString MainWindow::cle(QString ligne)
{
    QString ret = ligne.section(QRegExp("[\\W]"),0,0);
    return Ch::atone(Ch::deramise(ret));
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    QSettings settings("Collatinus", "ecce");
    settings.beginGroup("fenetre");
    settings.setValue("geometry", saveGeometry());
    //settings.setValue("windowState", saveState());
    settings.endGroup();
    settings.beginGroup("lexique");
    settings.setValue("module", module);
    settings.endGroup();
    settings.beginGroup("fichiers");
    settings.setValue("signet", posFC);
    settings.setValue("forme", forme);
    settings.endGroup();
    QMainWindow::closeEvent(event);
}

void MainWindow::connecte()
{
    // fichier
    //connect(actionCopier, SIGNAL(triggered()), this, SLOT(copier()));
    connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrir()));
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    // édition
    //connect(checkBoxVb, SIGNAL(toggled(bool)), this, SLOT(lignesVisibles(bool)));
    connect(completeur, SIGNAL(activated(QString)), this, SLOT(edLem(QString)));
    connect(lineEditLemme, SIGNAL(textChanged(QString)), this, SLOT(edLem(QString)));
    connect(actionQuant, SIGNAL(triggered()), this, SLOT(rotQ()));
    connect(boutonEnr, SIGNAL(clicked()), this, SLOT(enr()));
    //connect(boutonSuppr, SIGNAL(clicked()), this, SLOT(suppr()));
    connect(boutonLemSuiv, SIGNAL(clicked()), this, SLOT(lemSuiv()));
    //connect(bSuppr, SIGNAL(clicked()), this, SLOT(suppr()));
    connect(actionArr, SIGNAL(triggered()), this, SLOT(arr()));
    connect(actionArrArr, SIGNAL(triggered()), this, SLOT(arrArr()));
    connect(actionDebut, SIGNAL(triggered()), this, SLOT(debut()));
    connect(bEchecSuiv, SIGNAL(clicked()), this, SLOT(echec()));
    connect(actionEchecPrec, SIGNAL(triggered()), this, SLOT(echecPrec()));
    connect(actionEchecSuiv, SIGNAL(triggered()), this, SLOT(echec()));
    // màj de la flexion
    connect(lineEditGrq, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    connect(lineEditGrq, SIGNAL(textChanged(QString)), comboBoxModele, SLOT(show()));
    connect(comboBoxModele, SIGNAL(currentTextChanged(QString)), this, SLOT(ligneLa(QString)));
    connect(comboBoxModele, SIGNAL(currentTextChanged(QString)), this, SLOT(lignesVisibles(QString)));
    connect(lineEditPerfectum, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    connect(lineSupin, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    // test de lemmatisation
    connect(lineEditTest, SIGNAL(textChanged(QString)), this, SLOT(teste(QString)));
    // préanalyse et variantes
    connect(btnPre, SIGNAL(clicked()), this, SLOT(preAn()));
    connect(checkBoxAe, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_H, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_Mihi, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_IJ, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_UV, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_TICI, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_MPN, SIGNAL(clicked()), this, SLOT(coche()));
    connect(checkBox_PH, SIGNAL(clicked()), this, SLOT(coche()));
    connect(btnEnrVar, SIGNAL(clicked()), this, SLOT(enrVar()));
    // irréguliers
    connect(btnPers, SIGNAL(clicked()), this, SLOT(siPers()));
    connect(btnCas, SIGNAL(clicked()), this, SLOT(siCas()));
    connect(btnGenre, SIGNAL(clicked()), this, SLOT(siGenre()));
    connect(btnNb, SIGNAL(clicked()), this, SLOT(siNb()));
    connect(btnMod, SIGNAL(clicked()), this, SLOT(siMod()));
    connect(btnTps, SIGNAL(clicked()), this, SLOT(siTps()));
    connect(btnVx, SIGNAL(clicked()), this, SLOT(siVx()));
    connect(btnAj, SIGNAL(clicked()), this, SLOT(ajMorph()));
    connect(listWidgetIrr, SIGNAL(pressed(QModelIndex)), this, SLOT(editIrr(QModelIndex)));
    connect(bAjIrr, SIGNAL(clicked()), this, SLOT(ajIrr()));
    connect(bsupprIrr, SIGNAL(clicked()), this, SLOT(supprIrr()));
    // modules lexicaux
    connect(pushButtonCreeM, SIGNAL(clicked()), this, SLOT(creerM()));
    connect(pushButtonActM, SIGNAL(clicked()), this, SLOT(activerM()));
    connect(pushButtonSupprM, SIGNAL(clicked()), this, SLOT(supprM()));
    connect(pushButtonPaquet, SIGNAL(clicked()), this, SLOT(paquet()));
    connect(pushButtonInstM, SIGNAL(clicked()), this, SLOT(instM()));

}

QString MainWindow::contexte(qint64 p, QString f)
{
    QString ret;
    QTextStream flux(&fCorpus);
    flux.setAutoDetectUnicode(true);
    if (p < 201)
    {
        flux.seek(0);
        ret = flux.read(p-1);
    }
    else
    {
        flux.seek(p-201);
        ret = flux.read(200);
    }
    ret.append(flux.read(200));
    if (f.isEmpty()) return ret;
    int dm = ret.indexOf(f);
    int fm = ret.indexOf(QRegExp("\\b"), dm+2);
    ret.insert(fm, "</strong>");
    ret.insert(dm, "<strong>");
    ret.replace("\n", "<br/>");
    return ret;
}

/**
 * \fn void MainWindow::creerM()
 * \brief Création d'un module lexical
 */
void MainWindow::creerM()
{
    QString nm = lineEditM->text().simplified();
    if (nm.isEmpty()) return;
    // si le module existe déjà, erreur
    // créer le répertoire + les fichiers lemmes.la et lemmes.fr
    QString moduletmp = nm;
    nm.prepend(modDir);
    nm.append('/');
    if (!QFile::exists(nm))
    {
        QDir dir;
        dir.mkpath(nm);
    }
    // avec leur nom en commentaire
    QFile fm(nm+"lemmes.la");
    if (!fm.open(QFile::WriteOnly)) return;
    QTextStream(&fm) << "!    lemmes.la\n";
    fm.close();
    QFile ff(nm+"lemmes.fr");
    if (!ff.open(QFile::WriteOnly)) return;
    QTextStream(&ff) << "!    lemmes.fr\n";
    ff.close();
    QFile fi(nm+"irregs.la");
    if (!fi.open(QFile::WriteOnly)) return;
    QTextStream(&fi) << "!    irregs.la\n";
    fi.close();
    QFile fv(nm+"vargraph.la");
    if (!fv.open(QFile::WriteOnly)) return;
    QTextStream(&fv) << docVarGraph;
    fv.close();
    module = moduletmp;
    // sauver le nom du nouveau module
    QSettings settings("Collatinus", "ecce");
    settings.beginGroup("lexique");
    settings.setValue("module", module);
    settings.endGroup();
    // recharger toutes les données
    reinit();
    // affichage
    QListWidgetItem* item = new QListWidgetItem(module, listWidgetM);
    listWidgetM->setCurrentItem(item);
}

void MainWindow::debut()
{
    posFC = 0;
    fCorpus.seek(0);
    echecs.clear();
    forme.clear();
    labelContexte->setText(contexte(0, ""));
    majInfo();
}

void MainWindow::echec()
{
    QTextStream flux(&fCorpus);
    flux.seek(posFC);
    QChar c;
    //QString forme;
    bool arret = false;
    qint64 fluxpos = flux.pos();
    qint64 posEchec = fluxpos;
    while(!flux.atEnd() && !arret)
    {
        forme.clear();
        // passer l'entremots
        do
        {
            flux >> c;
        }
        while (!flux.atEnd() && !c.isLetter());
        // retenir la position du premier caractère entre mots
        fluxpos = flux.pos();
        // lire la forme
        do
        {
            forme.append(c);
            flux >> c;
        }
        while (!flux.atEnd() && c.isLetter());
        // la forme est compète. Lemmatisation
        posEchec = fluxpos;
        ml = lemcore->lemmatiseM(forme, true);
        // appliquer les règles aval
        QStringList lfti = lemcore->ti(forme);
        for (int i=0;i<lfti.count();++i)
        {
            QString fti = lfti.at(i);
            if (fti != forme)
            {
                MapLem nml = lemcore->lemmatiseM(fti, true, 0, false);
                //MapLem nml = lemcore->lemmatise(fti);
                for(int j=0;j<nml.count();++j)
                {
                    Lemme* nl = nml.keys().at(j);
                    ml.insert(nl, nml.value(nl));
                }
            }
        }
        if (ml.isEmpty())
        {
            arret = true;
            lineEditLemme->setText(forme);
            labelContexte->setText(contexte(fluxpos, forme));
            echecs.append(posEchec);
        }
        else
        {
            arret = true;
            // voir si une lemmatisation vient du lexique
            // classique ou du module lexical
            for (int i=0;i<ml.keys().count();++i)
            {
                Lemme* l = ml.keys().at(i);
                arret = arret && l->origin() > 1;
            }
            if (arret)
            {
                labelContexte->setText(contexte(fluxpos, forme));
                iLemSuiv = -1;
                lemSuiv();
                echecs.append(posEchec);
            }
        }
    }
    majInfo();
    posFC = flux.pos();
}

void MainWindow::echecPrec()
{
    if (echecs.count() > 1)
    {
        echecs.removeLast();
        if (echecs.count() > 1)
            posFC = echecs.takeLast()-1;
        else posFC = 0;
    }
    else posFC = 0;
    echec();
}

void MainWindow::editIrr(const QModelIndex &m)
{
    QString lin = qvariant_cast<QString>(m.data());
    QStringList sections = lin.split(':');
    linLemmeIrr->setText(sections.at(0));
    linIrreg->setText(sections.at(1));
    lineEditNumMorpho->setText(sections.at(2));
}

/**
 * \fn void MainWindow::editModule(QString k, QString l, QString f)
 * \brief écrit sur le disque dans le fichier f les changements
 * La ligne l de clé k. Si la clé est introuvable, la ligne
 * est ajoutée à sa place dans l'ordre alpha. Sinon, la ligne
 * l remplace la lignre trouvée.
 */
void MainWindow::editModule(QString k, QString l, QString f)
{
    QStringList lignes = lisLignes(f);
    bool fait = false;
    QRegExp sep("\\Ŵ");
    for (int i=0;i<lignes.count();++i)
    {
        QString lin = lignes.at(i);
        int c = QString::compare(Ch::atone(lin), Ch::atone(l), Qt::CaseInsensitive);
        /*
        if (c == 0)
        {
            std::cerr << qPrintable(l+" est un doublon dans "+f+"\n");
            fait = true;
            break;
        }
        */
        // si la clé est identique, remplacer la ligne
        QString cle = Ch::atone(lin.section(sep,0,0));
        if (cle == k)
        {
            lignes[i] = l;
            fait = true;
            break;
        }
        else if (c > 0)
        {
            lignes.insert(i, l);
            fait = true;
            break;
        }
    }
    if (!fait) lignes.append(l);
    QFile file(f);
    file.open(QFile::WriteOnly);
    QTextStream(&file) << lignes.join('\n');
    file.close();
}

void MainWindow::edLem(QString l)
{
    lineEditGrq->clear();
    lineEditPerfectum->clear();
    lineSupin->clear();
    lineMorpho->clear();
    lineEditTr->clear();
    textEditFlexion->clear();
    if (!litems.contains(l))
    {
        lemme = 0;
        // effacer les lignes
    }
    else
    {
        if (lemme == 0) lemme = lemcore->lemme(l);
        if (lemme != 0)
        {
            QString t = "enregistrer ";
            QStringList lo;
            lo << "module"<<"class."<<"ext.";
            t.append(lo.at(lemme->origin()));
            boutonEnr->setText(t);
            // si lem est issu de lem_ext, modifier l'intitulé du bouton
            textEditFlexion->setText(flexion->tableau(lemme));
            lineEditGrq->setText(lemme->champ0());
            comboBoxModele->setCurrentIndex(lemcore->lModeles().indexOf(lemme->grModele()));
            lineMorpho->setText(lemme->indMorph());
            lineEditTr->setText(lemme->traduction("fr"));
            lignesVisibles(comboBoxModele->currentText());
        }
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
            QChar pos = lemme->modele()->pos();
            lignesVisibles(lemme->modele()->gr());
            switch(numrad)
            {
                case 1: // génitif et perfectum
                    {
                        // TODO comparer la génération automatique de radical
                        // le radical
                        QString g = lemme->grq();
                        QString gen = lemme->modele()->genRadical(1);
                        int oter = gen.section(',', 0, 0).toInt();
                        QString ajouter = gen.section(',', 1, 1);
                        if (g.endsWith(0x0306)) g.chop(1);
                        g.chop(oter);
                        if (ajouter != "0") g.append(ajouter);
                        if (g != grq)
                        {
                            lineEditPerfectum->setText(grq);
                        }
                        break;
                    }
                case 2: // supin
                    {
                        if (QString("vw").contains(pos))
                        {
                            QString g = lemme->grq();
                            QString gen = lemme->modele()->genRadical(2);
                            int oter = gen.section(',', 0, 0).toInt();
                            QString ajouter = gen.section(',', 1, 1);
                            if (g.endsWith(0x0306)) g.chop(1);
                            g.chop(oter);
                            if (ajouter != "0") g.append(ajouter);
                            if (g != grq)
                                lineSupin->setText(grq);
                        }
                        break;
                    }
                default:
                    {
                        break;
                    }
            }
        }
    }
}

void MainWindow::enr()
{
    if (nLemme == 0) return;
    // radicaux et morphologie
    //QString lc = lineEditLemme->text();
    QString ltr = lineEditTr->text();
    QString grq = lineEditGrq->text();
    if (ltr.isEmpty() || grq.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Il faut donner au moins la forme canonique et une traduction");
        msgBox.exec();
        return;
    }
    QString linLa = ligneLa();
    QString lc = linLa.section(QRegExp("[=|]"),0,0);
    lc = Ch::atone(lc);
    // lc est-il un homographe ?
    bool remplace = true;
    if (lemme != 0 && lemme->origin() < 2)
    {
        for (int i=1;i<4;++i)
        {
            QString lci = QString("%1%2").arg(lc).arg(i);
            if (i == 1) lci = lc;
            if (litems.contains(lci))
                continue;
            else
            {
                QMessageBox::StandardButton rep;
                rep = QMessageBox::question(this, "lexique",
                                            "Le lexique a un lemme "+lc
                                            +". Le remplacer ?",
                                            QMessageBox::Yes|QMessageBox::No
                                            |QMessageBox::Cancel);
                if (rep == QMessageBox::No)
                {
                    lc = lci;
                    break;
                }
                else if (rep == QMessageBox::Cancel)
                    return;
                else break;
            }
        }
    }
    QString linFr = QString("%1:%2")
        .arg(Ch::atone(lc))
        .arg(ltr);
    // latin
    editModule(lc, linLa, ajDir+"/lemmes.la");
    // français
    editModule(lc, linFr, ajDir+"/lemmes.fr");
    // màj du compléteur
    litems.append(lc);
    modele = new QStringListModel(litems);
    modele->setStringList(litems);
    completeur->setModel(modele);
    if (remplace)
    {
        lemcore->remplaceLemme(nLemme);
        lemme = nLemme;
    }
    else lemcore->ajLemme(nLemme);
}

void MainWindow::instM()
{
    QString ch = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    QString chp = QFileDialog::getOpenFileName(this,
                                               "paquet du module à installer",
                                               ch, "paquets Collatinus (*.col)");
    if (chp.isEmpty()) return;
    QFileInfo info(chp);
    QString nmod= info.baseName();
    QDir dir(modDir);
    dir.mkdir(nmod);
    QuaZip zip(chp);
    zip.open(QuaZip::mdUnzip);
    zip.goToFirstFile();
    do
    {
        QuaZipFile zipFile(&zip);
        if (!zipFile.open(QIODevice::ReadOnly)) continue;
        QFile out(zipFile.getActualFileName());
        if (!out.open(QIODevice::WriteOnly)) continue;;
        char c;
        while (zipFile.getChar(&c)) out.putChar(c);
        out.flush();
        out.close();
        zipFile.close();
    }
    while (zip.goToNextFile());
    // ajouter le paquet à la liste et le sélectionner
    module = nmod;
    QListWidgetItem* item = new QListWidgetItem(module, listWidgetM);
    listWidgetM->setCurrentItem(item);
    // charger le paquet
    activerM();
}

void MainWindow::lemSuiv()
{
    if (ml.isEmpty()) return;
    ++iLemSuiv;
    if (iLemSuiv >= ml.keys().count())
        iLemSuiv = 0;
    lemme = ml.keys().at(iLemSuiv);
    edLem(lemme->cle());
    //lineEditLemme->setText(lemme->cle());
}

/**
 * \fn QString MainWindow::ligneLa(QString modl)
 * \brief calcule un lemme d'après les champs
 *        renseignés, affiche sa flexion.
 *        et renvoie la ligne capable de créer
 *        le lemme.
 */
QString MainWindow::ligneLa(QString modl)
{
    if (modl.isEmpty()) modl = comboBoxModele->currentText();
    // chercher s'il existe un lemme dont la clé est 
    // celle de lineEditLemme
    //QString grq;
    //if (lemme != 0) grq = lemme->grqNh();
    QString grq = lineEditGrq->text();
    int nbOcc = 1;
    if (lemme != 0) nbOcc = lemme->nbOcc();
    QString ret = gabaritLa
        .arg(grq)
        .arg(modl)
        .arg(lineEditPerfectum->text())
        .arg(lineSupin->text())
        .arg(lineMorpho->text())
        .arg(nbOcc);
    //nLemme = new Lemme(ret, 0, lemcore, lineEditLemme->text());
    nLemme = new Lemme(ret, 0, lemcore);
    textEditFlexion->setText(flexion->tableau(nLemme));
    return ret;
}

void MainWindow::lignesVisibles(QString chModele)
{
    Modele* m = lemcore->modele(chModele);
    if (m == 0) return;
    QChar p = m->pos();
    switch (p.toLatin1())
    {
        case 'v':
        case 'w':
            labelPerfectum->setText("rad. perfectum");
            labelSupin->show();
            lineSupin->show();
            break;
        case 'a':
        case 'n':
            labelPerfectum->setText("rad. génitif");
            labelSupin->hide();
            lineSupin->clear();
            lineSupin->hide();
            break;
        default:
            break;
    }
}

QString MainWindow::ligneFr()
{
    QString cl;
    if (lemme != 0) cl = lemme->cleF();
    else if (nLemme != 0) cl = nLemme->cleF();
    else return "";
    return QString("%1|%2")
        //.arg(lineEditLemme->text())
        .arg(cl)
        .arg(lineEditTr->text());
}

QStringList MainWindow::lisLignes(QString nf, bool ignoreComm)
{
    QFile f(nf);
    f.open(QFile::ReadOnly);
    QTextStream flux(&f);
    flux.setCodec("UTF-8"); // Pour windôze !
    QStringList retour;
    while (!flux.atEnd())
    {
        QString lin = flux.readLine();
        if (ignoreComm && lin.startsWith('!')) continue;
        retour.append(lin);
    }
    f.close();
    return retour;
}

void MainWindow::ouvrir(QString nf, qint64 p)
{
    if (nf.isEmpty())
    {
        fichier = QFileDialog::getOpenFileName(0, "Fichier à analyser", "./");
    }
    else fichier = nf;
    if (fichier.isEmpty()) return;
    fCorpus.close();
    fCorpus.setFileName(fichier);
    if (!fCorpus.open(QFile::ReadOnly))
    {
        std::cerr << qPrintable(" ne peux ouvrir "+nf);
        return;
    }
    tailleF = fCorpus.size();
    posFC = p;
    if (posFC > 0) posFC--;
    else debut();
    fCorpus.seek(posFC);
    labelContexte->setText(contexte(posFC, forme));
    QSettings settings("Collatinus", "ecce");
    settings.beginGroup("fichiers");
    settings.setValue("fichier", fichier);
    settings.endGroup();
    majInfo();
    echecs.clear();
}

void MainWindow::majInfo()
{
    qreal p = 100 * posFC / tailleF;
    labelInfo->setText(QString("ecce - module actuel <strong>%1</strong> "
                       "texte analysé : <strong>%2</strong> %3 \% %4")
        .arg(module)
        .arg(fichier)
        .arg(p)
        .arg(posFC));
}

void MainWindow::majLinMorph()
{
    // construire une regexp reflétant l'état des boutons
    QString re = "%1\\s*%2\\s*%3\\s*%4\\s*%5\\s*%6\\s*%7";
    // personne
    QString p = "\\w*";
    if (iPers > 0) p = lPers.at(iPers);
    // cas
    QString c = "\\w*";
    if (iCas > 0) c = lCas.at(iCas);
    // genre
    QString g = "\\w*";
    if (iGenre > 0) g = lGenre.at(iGenre);
    // nombre
    QString n = "\\w*";
    if (iNb > 0) n = lNb.at(iNb);
    // mode
    QString m = "\\w*";
    if (iMod > 0) m = lMod.at(iMod);
    // temps
    QString t = "\\w*";
    if (iTps > 0) t = lTps.at(iTps);
    // voix
    QString v = "\\w*";
    if (iVx > 0) v = lVx.at(iVx);

    QString mm = re.arg(p).arg(c).arg(g).arg(n)
        .arg(m).arg(t).arg(v);

    // màj de la liste
    listWidgetMorphos->clear();
    for (int i=0;i<lMorphos.count();++i)
    {
        QString lin = lMorphos.value(i);
        if (QRegExp(mm).exactMatch(lin))
            new QListWidgetItem(lin, listWidgetMorphos);
    }
}

void MainWindow::paquet()
{
    QListWidgetItem* item = listWidgetM->currentItem();
    QString nom = item->text();
    QString rep = nom;
    rep.prepend(modDir);
    QDir dir(rep);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);
    QString sortie = QString("%1/%2.col")
        .arg(QStandardPaths::writableLocation(QStandardPaths::HomeLocation))
        .arg(nom);
    QuaZip zip(sortie);
    zip.open(QuaZip::mdCreate);
    QuaZipFile out(&zip);
    QFile in;
    char c;
	QFileInfoList entrees = dir.entryInfoList();
	for (int i=0;i<entrees.count();++i)
    {
        QString n = QString("%1/%2").arg(rep).arg(entrees.at(i).fileName());
	    in.setFileName(n);
        in.open(QIODevice::ReadOnly);
        out.open(QIODevice::WriteOnly,
                 QuaZipNewInfo(in.fileName(),
                               in.fileName()));
        while(in.getChar(&c) && out.putChar(c));
        out.close();
        in.close();
    }
    QString info;
    QTextStream(&info)
        << "Le paquet "<<sortie
        << " a été enregisré.";
    labelInfoM->setText(info.toLatin1());
}

void MainWindow::peuple()
{
    // définir d'abord les répertoires de l'appli
    // et le répertoire personnel, où sont les modules lexicaux
    resDir = Ch::chemin("collatinus/"+module,'d');
    if (!resDir.endsWith('/')) resDir.append('/');
    // TODO : création, et QSettings pour module
    modDir = Ch::chemin("collatinus/", 'p');
    if (!modDir.endsWith('/')) modDir.append('/');
    if (!module.isEmpty())
    {
        ajDir = modDir + module;
        if (!ajDir.endsWith('/')) ajDir.append('/');
    }
    else
    {
        ajDir.clear();
        tabWidget->setCurrentIndex(3);
    }
    lemcore = new LemCore(this, resDir, ajDir);
    lemcore->setExtension(true);
    lemcore->setCible("fr");
    flexion = new Flexion(lemcore);
    // lemmes
    litems = lemcore->cles();
    qSort(litems.begin(), litems.end(), Ch::sort_i);
    // compléteur lemmes
	completeur = new QCompleter;
    modele = new QStringListModel(litems);
    completeur->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    completeur->setModel(modele);
    completeur->setMaxVisibleItems(litems.count());
    lineEditLemme->setCompleter(completeur);
    // modèles
    lmodeles = lemcore->lModeles();
    comboBoxModele->addItems(lmodeles);
    // irréguliers
    itemsIrr = lisLignes(module+"/irregs.la", true);
    for (int i=0;i<itemsIrr.count();++i)
    {
        new QListWidgetItem(itemsIrr.at(i), listWidgetIrr);
    }
    // morphos
    lMorphos.clear();
    QStringList listeM = lemcore->lignesFichier(resDir+"morphos.fr");
    for (int i=0;i<listeM.count();++i)
    {
        QString lin = listeM.at(i).simplified();
        if (lin == "nominatif") break;
        lMorphos.insert(lin.section(':',0,0).toInt(), lin.section(':',1,1));
    }
    // variantes graphiques
    lvarGraph = lemcore->lignesFichier(ajDir+"vargraph.la");
    plainTextEditVariantes->setPlainText(lvarGraph.join('\n'));
    // cocher les cases correspondantes
    initCoches(lvarGraph);

    // listes pour les morphos irregs
    lCas << ""; lGenre << ""; lMod << ""; lNb << "";
    lPers << ""; lTps<<""; lVx << "";
    for (int i=0;i<6;++i) lCas   << lemcore->cas(i);
    for (int i=0;i<3;++i) lGenre << lemcore->genre(i);
    for (int i=0;i<3;++i) lMod   << lemcore->modes(i);
    for (int i=0;i<2;++i) lNb    << lemcore->nombre(i);
    lPers <<""<<"1ère"<<"2ème"<<"3ème";
    for (int i=0;i<6;++i) lTps   << lemcore->temps(i);
    for (int i=0;i<2;++i) lTps   << lemcore->voix(i);
    iCas = 0; iGenre = 0; iMod = 0; iNb = 0; iPers = 0;
    iTps = 0; iVx = 0;

    // modules, peupler la liste
    QDir chModules(modDir);
    QStringList lm = chModules.entryList(QStringList() << "*", QDir::NoDotAndDotDot | QDir::Dirs);
    QListWidgetItem* item = 0;
    listWidgetM->clear();
    for (int i=0;i<lm.count();++i)
    {
        QListWidgetItem* ni = new QListWidgetItem(lm.at(i), listWidgetM);
        if (ni->text() == module) item = ni;
    }
    if (item != 0) listWidgetM->setCurrentItem(item);
    majInfo();
}

void MainWindow::reinit()
{
    qApp->setOverrideCursor(QCursor(Qt::WaitCursor));
    plainTextEditVariantes->clear();
    delete lemcore;
    litems.clear();
    delete completeur;
    delete modele;
    itemsIrr.clear();
    listWidgetM->clear();
    lvarGraph.clear();
    // recharger toutes les données
    posFC = 0;
    peuple();
    qApp->restoreOverrideCursor();
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

void MainWindow::siCas()
{
    ++iCas;
    if (iCas >= lCas.count())
    {
        iCas = 0;
        btnCas->setText("cas");
    }
    else btnCas->setText(lCas.at(iCas));
    majLinMorph();
}

void MainWindow::siGenre()
{
    ++iGenre;
    if (iGenre >= lGenre.count())
    {
        iGenre = 0;
        btnGenre->setText("genre");
    }
    else btnGenre->setText(lGenre.at(iGenre));
    majLinMorph();
}

void MainWindow::siMod()
{
    ++iMod;
    if (iMod >= lMod.count())
    {
        iMod = 0;
        btnMod->setText("mod");
    }
    else btnMod->setText(lMod.at(iMod));
    majLinMorph();
}

void MainWindow::siNb()
{
    ++iNb;
    if (iNb >= lNb.count())
    {
        iNb = 0;
        btnNb->setText("nb");
    }
    else btnNb->setText(lNb.at(iNb));
    majLinMorph();
}

void MainWindow::siPers()
{
    ++iPers;
    if (iPers >= lPers.count())
    {
        iPers = 0;
        btnPers->setText("pers");
    }
    else btnPers->setText(lPers.at(iPers));
    majLinMorph();
}

void MainWindow::siTps()
{
    ++iTps;
    if (iTps >= lTps.count())
    {
        iTps = 0;
        btnTps->setText("tps");
    }
    btnTps->setText(lTps.at(iTps));
    majLinMorph();
}

void MainWindow::siVx()
{
    ++iVx;
    if (iVx >= lVx.count())
    {
        iVx = 0;
        btnVx->setText("Vx");
    }
    else btnVx->setText(lVx.at(iVx));
    majLinMorph();
}

void MainWindow::suppr(QString l, QString f)
{
    std::cout<< "suppr "<<qPrintable(l + " " + f);
}

void MainWindow::supprLa()
{
    if (lemme == 0) return;
    QString cle = lemme->cle();
    // litems
    litems.removeAt(litems.indexOf(cle));
    suppr(ligneLa(), ajDir+"/lemmes.la");
    suppr(ligneFr(), ajDir+"/lemmes.fr");
}

void MainWindow::supprIrr()
{
    QList<QListWidgetItem*> liste = listWidgetIrr->selectedItems();
    for (int i=0;i<liste.count();++i)
    {
        listWidgetIrr->removeItemWidget(liste.at(i));
    }
}

void MainWindow::supprM()
{
    QListWidgetItem* item = listWidgetM->currentItem();
    QString nf = modDir + item->text();
}

void MainWindow::teste(QString f)
{
    MapLem res = lemcore->lemmatiseM(f, true);
    if (res.isEmpty())
    {
        QStringList fti = lemcore->ti(f);
        for (int i=0;i<fti.count();++i)
        {
            MapLem ml = lemcore->lemmatiseM(fti.at(i), true);
            for (int j=0;j<ml.count();++j)
            {
                Lemme* nl = ml.keys().at(j);
                res.insert(nl, ml.value(nl));
            }
        }
    }
    QString test;
    QTextStream fl(&test);
    for (int i=0;i<res.count();++i)
    {
        Lemme* lem = res.keys().at(i);
        QList<SLem> lsl = res.value(lem);
        fl<<lem->humain();
        for (int j=0;j<lsl.count();++j)
        {
            fl<<"<br/>"<<lemcore->morpho(lsl.at(j).morpho);
        }
    }
    labelLemTest->setText(test);
}
