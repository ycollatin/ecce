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

    - bouton supprimer une ligne
    - rendre le combo modele plus ergonomique
    - Chemin absolu des données A et B
    - initialisation d'un module
    - analyser la version médiévale de C11
*/

#include <QFileDialog>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    actionQuant = new QAction(this);
    actionCopier = new QAction(this);
    actionDiff = new QAction(this);
    actionQuitter = new QAction(this);

    centralWidget = new QWidget(this);
    verticalLayout = new QVBoxLayout(centralWidget);
    tabWidget = new QTabWidget(centralWidget);

    tabLexique = new QWidget();
    verticalLayout_Lex = new QVBoxLayout(tabLexique);
    splitter = new QSplitter(tabLexique);
    splitter->setOrientation(Qt::Horizontal);
    frame = new QFrame(splitter);
    frame->setFrameShape(QFrame::Box);
    verticalLayout_G = new QVBoxLayout(frame);
    verticalLayout_G->setSpacing(6);
    verticalLayout_G->setContentsMargins(11, 11, 11, 11);
    verticalLayout_G->setContentsMargins(0, 0, 0, 0);
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
    verticalLayout_G->addLayout(horizontalLayout);
    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout_G->addItem(verticalSpacer_2);
    splitter->addWidget(frame);
    frame1 = new QFrame(splitter);
    frame1->setFrameShape(QFrame::Box);
    verticalLayout_D = new QVBoxLayout(frame1);
    verticalLayout_D->setSpacing(6);
    verticalLayout_D->setContentsMargins(11, 11, 11, 11);
    verticalLayout_D->setContentsMargins(0, 0, 0, 0);
    formLayout_L = new QFormLayout();
    formLayout_L->setSpacing(6);
    formLayout_L->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    labelGrq = new QLabel(frame1);
    formLayout_L->setWidget(0, QFormLayout::LabelRole, labelGrq);
    horizontalLayout_grq = new QHBoxLayout();
    lineEditGrq = new QLineEdit(frame1);
    horizontalLayout_grq->addWidget(lineEditGrq);
    checkBoxVb = new QCheckBox(frame1);
    horizontalLayout_grq->addWidget(checkBoxVb);
    formLayout_L->setLayout(0, QFormLayout::FieldRole, horizontalLayout_grq);

    labelModele = new QLabel(frame1);
    labelModele->setLayoutDirection(Qt::LeftToRight);
    labelModele->setScaledContents(false);
    labelModele->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    formLayout_L->setWidget(1, QFormLayout::LabelRole, labelModele);
    comboBoxModele = new QComboBox(frame1);
    formLayout_L->setWidget(1, QFormLayout::FieldRole, comboBoxModele);
    labelPerfectum = new QLabel(frame1);
    formLayout_L->setWidget(2, QFormLayout::LabelRole, labelPerfectum);
    lineEditPerfectum = new QLineEdit(frame1);
    formLayout_L->setWidget(2, QFormLayout::FieldRole, lineEditPerfectum);
    labelSupin = new QLabel(frame1);
    labelSupin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    formLayout_L->setWidget(3, QFormLayout::LabelRole, labelSupin);
    lineSupin = new QLineEdit(frame1);
    formLayout_L->setWidget(3, QFormLayout::FieldRole, lineSupin);
    labelTr = new QLabel(frame1);
    formLayout_L->setWidget(4, QFormLayout::LabelRole, labelTr);
    lineEditTr = new QLineEdit(frame1);
    formLayout_L->setWidget(4, QFormLayout::FieldRole, lineEditTr);
    labelMorpho = new QLabel(frame1);
    formLayout_L->setWidget(5, QFormLayout::LabelRole, labelMorpho);
    lineMorpho = new QLineEdit(frame1);
    formLayout_L->setWidget(5, QFormLayout::FieldRole, lineMorpho);
    verticalLayout_D->addLayout(formLayout_L);
    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    boutonEnr = new QPushButton(frame1);
    horizontalLayout_3->addWidget(boutonEnr);
    boutonSuppr = new QPushButton(frame1);
    horizontalLayout_3->addWidget(boutonSuppr);
    verticalLayout_D->addLayout(horizontalLayout_3);
    textEditFlexion = new QTextEdit(frame1);
    textEditFlexion->setReadOnly(true);
    verticalLayout_D->addWidget(textEditFlexion);
    splitter->addWidget(frame1);
    verticalLayout_Lex->addWidget(splitter);
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
    tabVarGraph = new QWidget();
    comboBox_3 = new QComboBox(tabVarGraph);
    comboBox_3->setGeometry(QRect(50, 60, 72, 22));
    tabWidget->addTab(tabVarGraph, QString());
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
    menuFichier->addAction(actionCopier);
    menuFichier->addAction(actionDiff);
    menuFichier->addAction(actionQuitter);
    mainToolBar->addAction(actionQuant);
    tabWidget->setCurrentIndex(0);

    setWindowTitle(QApplication::translate("MainWindow", "Collatinus, données", Q_NULLPTR));
    actionQuant->setText(QApplication::translate("MainWindow","aăā (Ctrl+W)", Q_NULLPTR));
    actionQuant->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", Q_NULLPTR));
    actionCopier->setText(QApplication::translate("MainWindow", "Copier un jeu de données", Q_NULLPTR));
    actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
    actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
    actionDiff->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer un fichier diff", Q_NULLPTR));
    labelLemme->setText(QApplication::translate("MainWindow", "Lemme", Q_NULLPTR));
    labelGrq->setText(QApplication::translate("MainWindow", "Forme canonique, avec quantit\303\251s", Q_NULLPTR));
    checkBoxVb->setText(QApplication::translate("MainWindow", "verbe", Q_NULLPTR));
    labelModele->setText(QApplication::translate("MainWindow", "Mod\303\250le", Q_NULLPTR));
    labelPerfectum->setText(QApplication::translate("MainWindow", "rad. parfait", Q_NULLPTR));
    labelSupin->setText(QApplication::translate("MainWindow", "rad. supin", Q_NULLPTR));
    labelTr->setText(QApplication::translate("MainWindow", "traductions", Q_NULLPTR));
    labelMorpho->setText(QApplication::translate("MainWindow", "morphologie", Q_NULLPTR));
    bHomon->setText(QApplication::translate("MainWindow", "homon.", Q_NULLPTR));
    bSuppr->setText(QApplication::translate("MainWindow", "suppr.", Q_NULLPTR));
    boutonEnr->setText(QApplication::translate("MainWindow", "Enregistrer", Q_NULLPTR));
    boutonSuppr->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabLexique), QApplication::translate("MainWindow", "Lexique", Q_NULLPTR));
    pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
    pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabModeles), QApplication::translate("MainWindow", "Mod\303\250les", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(varGraph), QApplication::translate("MainWindow", "Variantes graphiques", Q_NULLPTR));
    tabWidget->setTabText(tabWidget->indexOf(tabVarGraph), QApplication::translate("MainWindow", "Irr\303\251guliers", Q_NULLPTR));
    menuFichier->setTitle(QApplication::translate("MainWindow", "&Fichier", Q_NULLPTR));
    tabWidget->setCurrentIndex(0);

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
            /*
            QFile f("data/lemmes.la");
            f.remove();
            f.open(QFile::WriteOnly);
            QTextStream flux(&f);
            for (int j=0;j<listeLemmesLa.count();++j)
                flux << listeLemmesLa.at(j)<<'\n';
            f.close();
            */
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
