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

   TODO
   - lors de la recherche des échecs : afficher le contexte du texte source
   - Vérifier que les radicaux des lemmes perso sont bien mis à jour, ou
     ne les calculer qu'à la fin de l'initialisation.
   - tant que le lemme n'est pas changé, tant qu'il est incomplet, désactiver
     boutonEnr.
   - suppression d'un lemme : il suffit de commenter sa ligne
     prévoir une gestion des lignes lemmes commentées
   - nom : ecce (ecce collatinistorum communitatis editor)
   - compression des données utilisateur
   - lecture et restitution des en-têtes des fichiers de données ;
   - peupler les éditeurs de variantes graphiques 
   - mettre au point une taxonomie des pos ?
   - rendre l'homonymie plus ergonomique
   - Chemin absolu des données A et B
   - initialisation d'un module
 */

#include <QFileDialog>
#include <QVector>
#include <mainwindow.h>

MainWindow::MainWindow()
{
    actionQuant = new QAction(this);
    actionQuitter = new QAction(this);
    actionDiff = new QAction(this);
    actionOuvrir = new QAction(this);
    //  setupUi
    centralWidget = new QWidget(this);
    verticalLayout_9 = new QVBoxLayout(centralWidget);
    verticalLayout_9->setSpacing(6);
    verticalLayout_9->setContentsMargins(11, 11, 11, 11);
    tabWidget = new QTabWidget(centralWidget);
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
    bHomon = new QPushButton(frame);
    horizontalLayout->addWidget(bHomon);
    bSuppr = new QPushButton(frame);
    horizontalLayout->addWidget(bSuppr);
    bEchecSuiv = new QPushButton(frame);
    horizontalLayout->addWidget(bEchecSuiv);

    verticalLayout_3->addLayout(horizontalLayout);

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

    checkBoxVb = new QCheckBox(frame1);
    horizontalLayout_grq->addWidget(checkBoxVb);


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
    verticalLayout_2->addLayout(horizontalLayout_3);

    textEditFlexion = new QTextEdit(frame1);
    textEditFlexion->setReadOnly(true);
    verticalLayout_2->addWidget(textEditFlexion);

    splitter->addWidget(frame1);

    verticalLayout_Lex->addWidget(splitter);

    tabWidget->addTab(tabLexique, QString());
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

    checkBox_ae = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(1, QFormLayout::FieldRole, checkBox_ae);
    checkBox_H = new QCheckBox(layoutWidget);


    formLayoutCochesVar->setWidget(2, QFormLayout::LabelRole, checkBox_H);

    checkBox_h = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(2, QFormLayout::FieldRole, checkBox_h);

    checkBox_Mihi = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(3, QFormLayout::LabelRole, checkBox_Mihi);

    checkBox_mihi = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(3, QFormLayout::FieldRole, checkBox_mihi);

    checkBox_IJ = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(4, QFormLayout::LabelRole, checkBox_IJ);

    checkBox_ij = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(4, QFormLayout::FieldRole, checkBox_ij);

    checkBox_UV = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(5, QFormLayout::LabelRole, checkBox_UV);

    checkBox_uv = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(5, QFormLayout::FieldRole, checkBox_uv);

    checkBox_TICI = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(6, QFormLayout::LabelRole, checkBox_TICI);

    checkBox_tici = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(6, QFormLayout::FieldRole, checkBox_tici);

    checkBox_MPN = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(7, QFormLayout::LabelRole, checkBox_MPN);

    checkBox_mpn = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(7, QFormLayout::FieldRole, checkBox_mpn);

    checkBox_PH = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(8, QFormLayout::LabelRole, checkBox_PH);

    checkBox_ph = new QCheckBox(layoutWidget);
    formLayoutCochesVar->setWidget(8, QFormLayout::FieldRole, checkBox_ph);

    label_tju = new QLabel(layoutWidget);
    formLayoutCochesVar->setWidget(0, QFormLayout::FieldRole, label_tju);

    verticalLayoutConf->addLayout(formLayoutCochesVar);

    splitterVarGraph->addWidget(layoutWidget);
    splitter_2 = new QSplitter(splitterVarGraph);
    splitter_2->setOrientation(Qt::Vertical);
    plainTextEditVariantes = new QPlainTextEdit(splitter_2);
    plainTextEditVariantes->setReadOnly(true);
    splitter_2->addWidget(plainTextEditVariantes);
    layoutWidget1 = new QWidget(splitter_2);
    verticalLayout_4 = new QVBoxLayout(layoutWidget1);
    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setContentsMargins(11, 11, 11, 11);
    verticalLayout_4->setContentsMargins(0, 0, 0, 0);
    btnEnrVar = new QPushButton(layoutWidget1);
    verticalLayout_4->addWidget(btnEnrVar);
    label_AutresVar = new QLabel(layoutWidget1);
    verticalLayout_4->addWidget(label_AutresVar);

    plainTextEdit_AutresVar = new QPlainTextEdit(layoutWidget1);
    verticalLayout_4->addWidget(plainTextEdit_AutresVar);

    splitter_2->addWidget(layoutWidget1);
    splitterVarGraph->addWidget(splitter_2);

    verticalLayout_5->addWidget(splitterVarGraph);

    tabWidget->addTab(tabVarGraph, QString());

    verticalLayout_9->addWidget(tabWidget);

    // irr
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
    widget1 = new QWidget(splitterIrr);
    verticalLayoutIrrCentre = new QVBoxLayout(widget1);
    verticalLayoutIrrCentre->setSpacing(6);
    verticalLayoutIrrCentre->setContentsMargins(11, 11, 11, 11);
    verticalLayoutIrrCentre->setContentsMargins(0, 0, 0, 0);
    spacerIrrHaut = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayoutIrrCentre->addItem(spacerIrrHaut);
    bAjIrr = new QPushButton(widget1);
    verticalLayoutIrrCentre->addWidget(bAjIrr);
    bsupprIrr = new QPushButton(widget1);
    verticalLayoutIrrCentre->addWidget(bsupprIrr);

    spacerIrrBas = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayoutIrrCentre->addItem(spacerIrrBas);

    splitterIrr->addWidget(widget1);
    listWidgetIrr = new QListWidget(splitterIrr);
    splitterIrr->addWidget(listWidgetIrr);
    verticalLayout_I->addWidget(splitterIrr);

    tabWidget->addTab(tabIrr, QString());
    // fin irr

    setCentralWidget(centralWidget);
    tabWidget->setCurrentIndex(0);

    // Menus et barres

    mainToolBar = new QToolBar(this);
    mainToolBar->addAction(actionQuant);
    mainToolBar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, mainToolBar);

    menuBar = new QMenuBar(this);
    menuBar->setGeometry(QRect(0, 0, 1067, 19));
    menuFichier = new QMenu(menuBar);
    setMenuBar(menuBar);
    menuBar->addAction(menuFichier->menuAction());
    //menu_Aide = new QMenu(menuBar);
    //menuBar->addAction(menu_Aide->menuAction());
    menuFichier->addSeparator();
    //menuFichier->addAction(actionCopier);
    menuFichier->addAction(actionDiff);
    menuFichier->addAction(actionOuvrir);
    menuFichier->addAction(actionQuitter);
    mainToolBar->addAction(actionQuant);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    // doc de l'onglet variantes graphiques
    docVarGraph =
    "!          vargraph.la\n"
    "!\n"
    "!  Dans ce fichier sont enregistrées les variantes\n"
    "! graphiques du corpus traité. Chaque ligne est\n"
    "! composée de deux chaînes séparées par le caractère\n"
    "! ';' ou le caractère '>'.\n"
    "! La première chaîne est la graphie classique, la\n"
    "! seconde est la variante du corpus traité. Si\n"
    "! la variante est systématiquement employée, et que\n"
    "! la graphie classique disparaît, on utilise le\n"
    "! séparateur '>'. Si les deux graphies coexistent,\n"
    "! on utilise ';'. Par exemple, si la chaîne \"ae\"\n"
    "! devient quelquefois \"e\", on note :\n"
    "! ae;e\n"
    "! Mais si \"ae\" devient toujours \"e\", on note :\n"
    "! ae>e\n"
    "!\n";

    retranslateUi();

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

void MainWindow::reserve()
{
    lemme = lemcore->lemmeDisque(lineEditLemme->text());
    if (lemme != 0)
    {
        edLem("-reserve");
        lineEditTr->setText(lemcore->trDisque(lemme->cle()));
    }
}

void MainWindow::retranslateUi()
{
    setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    actionQuant->setText(QApplication::translate("MainWindow", "a\304\203\304\201", Q_NULLPTR));
    actionQuant->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", Q_NULLPTR));
    actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
    actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
    actionDiff->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer un fichier diff", Q_NULLPTR));
    actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir un fichier texte"));
    actionOuvrir->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
    //actionCopier->setText(QApplication::translate("MainWindow", "copier un jeu de donn\303\251es", Q_NULLPTR));
    labelLemme->setText(QApplication::translate("MainWindow", "Lemme", Q_NULLPTR));
    bHomon->setText(QApplication::translate("MainWindow", "homon.", Q_NULLPTR));
    bSuppr->setText(QApplication::translate("MainWindow", "suppr.", Q_NULLPTR));
    bEchecSuiv->setText(QApplication::translate("MainWindow", "échec >", Q_NULLPTR));
    labelGrq->setText(QApplication::translate("MainWindow", "Forme canonique, avec quantit\303\251s", Q_NULLPTR));
    checkBoxVb->setText(QApplication::translate("MainWindow", "verbe", Q_NULLPTR));
    labelModele->setText(QApplication::translate("MainWindow", "Mod\303\250le", Q_NULLPTR));
    labelPerfectum->setText(QApplication::translate("MainWindow", "rad. parfait", Q_NULLPTR));
    labelSupin->setText(QApplication::translate("MainWindow", "rad. supin", Q_NULLPTR));
    labelMorpho->setText(QApplication::translate("MainWindow", "morphologie", Q_NULLPTR));
    labelTr->setText(QApplication::translate("MainWindow", "traductions", Q_NULLPTR));
    boutonEnr->setText(QApplication::translate("MainWindow", "Enregistrer", Q_NULLPTR));
    boutonSuppr->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabLexique),
                          QApplication::translate("MainWindow", "Lexique", Q_NULLPTR));

    //label_3->setText(QApplication::translate("MainWindow", docVarGraph, Q_NULLPTR));
    label_3->setText(docVarGraph);
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

/*
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
    QFile::copy(nfc+"/lemmes.la", "data/lemmes.la");
    QFile::copy(nfc+"/lemmes.fr", "data/lemmes.fr");
    QFile::copy(nfc+"/assimilations.la", "data/assimilations.la");
    QFile::copy(nfc+"/contractions.la", "data/contractions.la");
    QFile::copy(nfc+"/irregs.la", "data/irregs.la");
    QFile::copy(nfc+"/modeles.la", "data/modeles.la");
    QFile::copy(nfc+"/morphos.fr", "data/morphos.fr");
    if (QFile::exists(nfc+"/vargraph.la"))
        QFile::copy(nfc+"/vargraph.la", "data/vargraph.la");
    else 
    {
        QFile fv("data/vargraph.la");
        fv.open(QFile::WriteOnly);
        QTextStream flux(&fv);
        flux << docVarGraph;
        fv.close();
    }

    // 
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
*/

void MainWindow::connecte()
{
    // fichier
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    //connect(actionCopier, SIGNAL(triggered()), this, SLOT(copier()));
    connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrir()));
    // édition
    connect(checkBoxVb, SIGNAL(toggled(bool)), this, SLOT(lignesVisibles(bool)));
    connect(completeur, SIGNAL(activated(QString)), this, SLOT(edLem(QString)));
    connect(lineEditLemme, SIGNAL(textChanged(QString)), this, SLOT(edLem(QString)));
    connect(lineEditLemme, SIGNAL(returnPressed()), this, SLOT(reserve()));
    connect(actionQuant, SIGNAL(triggered()), this, SLOT(rotQ()));
    connect(boutonEnr, SIGNAL(clicked()), this, SLOT(enr()));
    connect(boutonSuppr, SIGNAL(clicked()), this, SLOT(suppr()));
    connect(bSuppr, SIGNAL(clicked()), this, SLOT(suppr()));
    connect(bEchecSuiv, SIGNAL(clicked()), this, SLOT(echec()));
    // màj de la flexion
    connect(lineEditGrq, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    connect(lineEditGrq, SIGNAL(textChanged(QString)), comboBoxModele, SLOT(show()));
    connect(comboBoxModele, SIGNAL(currentTextChanged(QString)), this, SLOT(ligneLa(QString)));
    connect(lineEditPerfectum, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    connect(lineSupin, SIGNAL(editingFinished()), this, SLOT(ligneLa()));
    // préanalyse et variantes
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
}

void MainWindow::ajIrr()
{
    QString lin = QString("%1:%2:%3")
        .arg(linIrreg->text())
        .arg(linLemmeIrr->text())
        .arg(lineEditNumMorpho->text());
    insereLigne(lin, dirIrr);
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

void MainWindow::echec()
{
    QTextStream flux(&fCorpus);
    flux.seek(posFC);
    bool fini = flux.atEnd();
    QChar c;
    QString forme;
    while(!fini)
    {
        do flux >> c;
        while (!flux.atEnd() && !c.isLetter());
        do
        {
            forme.append(c);
            flux >> c;
        }
        while (!flux.atEnd() && c.isLetter());
        MapLem ml = lemcore->lemmatiseM(forme);
        if (ml.isEmpty())
        {
            lineEditLemme->setText(forme);
            fini = true;
        }
        forme.clear();
    }
    posFC = flux.pos();
}

void MainWindow::editIrr(const QModelIndex &m)
{
    QString lin = qvariant_cast<QString>(m.data());
    QStringList sections = lin.split(':');
    linLemmeIrr->setText(sections.at(0));
    linIrreg->setText(sections.at(1));
    lineEditNumMorpho->setText(sections.at(2));
}

void MainWindow::edLem(QString l)
{
    bool contient = litems.contains(l) || l == "-reserve";
    if (!contient)
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
        checkBoxVb->setChecked(l.endsWith("o")
                               || l.endsWith("or"));
    }
    else
    {
        if (lemme == 0) lemme = lemcore->lemme(l);
        // si lem est issu de lem_ext, modifier l'intitulé du bouton
        if (lemme->origin() > 0)
            boutonEnr->setText("enregistrer (de lem_ext)");
        else boutonEnr->setText("enregistrer");
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
    if (lem == 0 || lem->origin() > 0)
    {
        lem = nLemme;
        // ajouter le lemme à la map _lemmes
        lemcore->ajLemme(lem);
        // màj des clés et des lignes à enregistrer
        // latin
        enrLa(linLa);
        // français
        enrFr(linFr);
        // màj du compléteur
        litems.append(lc);
        modele = new QStringListModel(litems);
        modele->setStringList(litems);
        completeur->setModel(modele);
        return;
    }
    if (nLemme == 0) return;
    if (lemme != 0 && nLemme != 0)
    {
        lemcore->remplaceLemme(lemme, nLemme);
        lemme = nLemme;
    }
    QString tr = lem->traduction("fr");
}

void MainWindow::enrFr(QString l)
{
    insereLigne(l, lemcore->ajDir() + "/lemmes.fr");
}

void MainWindow::enrLa(QString l)
{
    insereLigne(l, lemcore->ajDir()+"/lemmes.la");
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


void MainWindow::insereLigne(QString l, QString f)
{
    qDebug()<<"insereLigne"<<l<<f;
    QStringList lignes = lisLignes(f);
    for (int i=0;i<lignes.count();++i)
    {
        QString lin = lignes.at(i);
        int c = QString::compare(Ch::atone(lin), Ch::atone(l), Qt::CaseInsensitive);
        if (c == 0)
        {
            std::cerr << qPrintable(l+" est un doublon dans "+f);
            return;
        }
        else if (c > 0)
        {
            lignes.insert(i, l);
            return;
        }
    }
    lignes.append(l);
    QFile file(f);
    file.open(QFile::WriteOnly);
    QTextStream(&file) << lignes.join('\n');
    file.close();
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

void MainWindow::ouvrir()
{
    QString nf = QFileDialog::getOpenFileName(0, "Fichier à analyser", "./");
    if (nf.isEmpty()) return;
    fCorpus.setFileName(nf);
    if (!fCorpus.open(QFile::ReadOnly)) return;
    posFC = 0;
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

void MainWindow::peuple()
{
    lemcore = new LemCore(this);
    flexion = new Flexion(lemcore);
    // chemins
    dirLa = lemcore->dirLa();
    dirFr = lemcore->dirFr();
    dirIrr = lemcore->dirIrr();
    dirVg = lemcore->dirVg();
    peupleAjLemmes();
    peupleAjTr();
    peupleAjIrr();
    peupleAjVg();
    // lemmes
    litems = lemcore->cles();
    qSort(litems.begin(), litems.end(), Ch::sort_i);
    listeLemmesLa = lisLignes("data/lemmes.la");
    listeLemmesFr = lisLignes("data/lemmes.fr");
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
    itemsIrr = lisLignes("data/irregs.la", true);
    for (int i=0;i<itemsIrr.count();++i)
    {
        new QListWidgetItem(itemsIrr.at(i), listWidgetIrr);
    }
    // morphos
    lMorphos.clear();
    QStringList listeM = lemcore->lignesFichier("data/morphos.fr");
    for (int i=0;i<listeM.count();++i)
    {
        QString lin = listeM.at(i).simplified();
        if (lin == "nominatif") break;
        lMorphos.insert(lin.section(':',0,0).toInt(), lin.section(':',1,1));
    }
    // variantes graphiques
    lvarGraph = lemcore->lignesFichier("data/vargraph.la");
    plainTextEdit_AutresVar->setPlainText(lvarGraph.join('\n'));

    lCas <<""<<"nominatif"<<"vocatif"<<"accusatif"
        <<"génitif"<<"datif"<<"ablatif"<<"locatif";
    lGenre << "" << "masculin" << "féminin" << "neutre";
    lMod << "" << "indicatif" << "subjonctif"<<"impératif"
        <<"infinitif"<<"participe"<<"gérondif"<<"adjectif verbal";
    lNb << "" << "singulier" << "pluriel";
    lPers << ""<<"1ère"<<"2ème"<<"3ème";
    lTps << "" << "présent" << "futur" << "imparfait"
        << "parfait" << "futur antérieur" << "PQP";
    lVx << "" << "actif" << "passif";
    iCas = 0;
    iGenre = 0;
    iMod = 0;
    iNb = 0;
    iPers = 0;
    iTps = 0;
    iVx = 0;
}

void MainWindow::peupleAjLemmes()
{
    QStringList ll = lisLignes(dirLa, true);
    for (int i=0;i<ll.count();++i)
    {
        Lemme *l = new Lemme(ll.at(i),2, lemcore);
        Lemme *lc = lemcore->lemme(l->cle());
        if (lc != 0)
            lemcore->remplaceLemme(lc, l);
        else lemcore->ajLemme(l);
    }
}

void MainWindow::peupleAjTr()
{
    QStringList ll = lisLignes(dirFr, true);
    for (int i=0;i<ll.count();++i)
    {
        QString lin = ll.at(i);
        Lemme *l = lemcore->lemme(lin.section(':',0,0));
        if (l != 0)
            l->ajTrad(lin.section(':',1), "fr");
    }
}

void MainWindow::peupleAjIrr()
{
}

void MainWindow::peupleAjVg()
{
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
        btnGenre->setText("mfn");
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
    qDebug()<<"suppr"<<l<<f;
}

void MainWindow::supprLa()
{
    if (lemme == 0) return;
    QString cle = lemme->cle();
    // litems
    litems.removeAt(litems.indexOf(cle));
    suppr(ligneLa(), lemcore->ajDir()+"/lemmes.la");
    suppr(ligneFr(), lemcore->ajDir()+"/lemmes.fr");
}

void MainWindow::supprIrr()
{
    QList<QListWidgetItem*> liste = listWidgetIrr->selectedItems();
    for (int i=0;i<liste.count();++i)
    {
        listWidgetIrr->removeItemWidget(liste.at(i));
    }
}
