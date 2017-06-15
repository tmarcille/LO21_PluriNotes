#include "PluriNotes.h"
#include "nouvellenote.h"
#include <qDebug>
#include <QList>
#include <QTabWidget>
#include "RelationTree.h"

PluriNotes::PluriNotes(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug()<<"launched";
	ui.setupUi(this);
    ui.relationTree->setMaximumWidth(0);
    ui.relationTree->setMinimumWidth(0);
    ui.noteViewer->attach(*this);
    m_sSettingsFile = QDir::currentPath() + "/config.ini";

    QFileInfo check_file(m_sSettingsFile);

    if (!check_file.exists()){
        QSettings* settings = new QSettings(m_sSettingsFile, QSettings::IniFormat);
        settings->setValue("folder", QDir::currentPath());
        settings->setValue("relationFile", QDir::currentPath() + "/Relations.xml");
        settings->setValue("checkBin","false");
        settings->sync();
        qDebug()<<"file created"<<endl;
    }

    loadSettings();
    ouvrirProjet();

	QObject::connect(ui.actionNote, SIGNAL(triggered()), this, SLOT(nouvelleNote()));
    QObject::connect(ui.actionOptions, SIGNAL(triggered()), this, SLOT(openSettings()));
    QObject::connect(ui.actionRelations, SIGNAL(triggered()), this, SLOT(openRelations()));
    QObject::connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(ouvrirNote(QListWidgetItem*)));
    QObject::connect(ui.toggleBtn, SIGNAL(toggled(bool)), this, SLOT(reactToPannelToggle(bool)));
    QObject::connect(ui.removeNoteBtn, SIGNAL(clicked()), this, SLOT(removeBtnClicked()));
    QObject::connect(ui.restoreBtn, SIGNAL(clicked()), this, SLOT(restoreBtnClicked()));

}


void PluriNotes::loadSettings()
{

    QSettings settings(m_sSettingsFile, QSettings::IniFormat);
    QString sText = settings.value("folder", "").toString();
    QString rText = settings.value("relationFile", "").toString();

    NotesManager& m = NotesManager::getManager();
    m.setFoldername(sText);

    RelationManager& r = RelationManager::getManager();
    r.setFilename(rText);

    qDebug()<<"settings loaded"<<settings.value("folder", "").toString()<<endl;
    qDebug()<<"settings loaded"<<settings.value("relationFile", "").toString()<<endl;

}

void PluriNotes::closeEvent(QCloseEvent *event)
{
    NotesManager& m = NotesManager::getManager();
    for (NotesManager::Iterator it = m.getIterator(); !it.isDone(); it.next()) {
            if (ui.noteViewer->isOpen(it.current().getId()))
                ui.noteViewer->closeNote(it.current().getId());
    }

    QSettings* settings = new QSettings(m_sSettingsFile, QSettings::IniFormat);
    if ((settings->value("checkBin", "").toString() == "false") && (ui.bin->count() != 0)){
        QDialog* dialog = new QDialog();
        dialog->setModal(true);
        VidageCorbeille* x = new VidageCorbeille();
        int dialogCode = x->exec();
        if (dialogCode == QDialog::Accepted) {
            int count = ui.bin->count();
            for(int index = 0;
                index < count;
                index++)
            {
                ui.bin->setCurrentRow(index);
                restoreBtnClicked();
            }
        }
    }
}

void PluriNotes::openSettings()
{
    SettingsDialog* x = new SettingsDialog(m_sSettingsFile);
    if(x->exec() == QDialog::Accepted){

        //si on a sauvegardé des changements dans les paramètres, on recharge le projet

        NotesManager& m = NotesManager::getManager();


        for (NotesManager::Iterator it = m.getIterator(); !it.isDone(); it.next()) {
                if (ui.noteViewer->isOpen(it.current().getId())){
                    ui.noteViewer->closeNote(it.current().getId());}

        }
        NotesManager::freeManager();
        RelationManager::freeManager();
        loadSettings();
        ouvrirProjet();
    }
}

void PluriNotes::openRelations()
{
    RelationEditor* x = new RelationEditor();
    x->show();
}

void PluriNotes::ouvrirProjet() {

    ui.taskList->clear();
    ui.listWidget->clear();
    NotesManager& m = NotesManager::getManager();

    qDebug()<<"folder:"<<m.getFoldername();
    qDebug()<<"loadin manager:"<<m.getFoldername();

    m.load();
    for (NotesManager::Iterator it = m.getIterator(); !it.isDone(); it.next()) {
            new QListWidgetItem(it.current().getId(), ui.listWidget);
    }
    //On active le bouton nouvelle note
    ui.actionNote->setEnabled(true);
    createTaskList();
}

void PluriNotes::createTaskList(){

    std::vector<QString> v;
    QString s;
    NotesManager& m = NotesManager::getManager();
    for (NotesManager::Iterator it = m.getIterator(); !it.isDone(); it.next()) {
            if (it.current().getType()=="tache"){
                qDebug()<<"tache found";
                Tache * t = dynamic_cast <Tache*> (&it.current());
                if (t && t->getEchue()=="T" && t->getStatus()!="terminee"){
                    s = t->getEcheance().toString("yyyy.MM.dd") + t->getIntPriorite() + t->getId() + QString(" ") + t->getEcheance().toString("dd/MM/yyyy");
                    if (t->getPriorise()=="T")
                       s = s + QString(" ") + t->getPriorite();
                    v.push_back(s);
                    qDebug()<<"added task"<<t->getId();
                }
            }
    }
    std::sort(v.begin(),v.end());
    for (unsigned int i = 0 ; i<v.size(); ++i){
        s=v[i];
        s=s.remove(0,11);
        new QListWidgetItem(s, ui.taskList);
    }
}

void PluriNotes::ouvrirNote(QListWidgetItem* item) {

    NotesManager& m = NotesManager::getManager();
    Note& n = m.getNote(item->text());
    n.attach(*this);
    qDebug()<<"ouverture note"<<item->text();
    ui.noteViewer->showNote(&n);
}

void PluriNotes::nouvelleNote()
{
	NouvelleNote* x = new NouvelleNote();
	if (x->exec() == QDialog::Accepted) {
		// Ajouter : tri par ordre alphabetique de la liste, verif si la note n'existe pas deja


		NotesManager& m = NotesManager::getManager();
        try{
            qDebug()<<"adding note";
            m.create(x->getSelectedType(),m.getFoldername() + "/" + x->getNom()+".xml");
        }
        catch (NotesException& a){
            if(a.getInfo()=="Note already exists"){
                QMessageBox::information(this, "Error", a.getInfo()) ;
                return;
            }
        }
        QListWidgetItem* nouvelle_note = new QListWidgetItem(x->getNom(), ui.listWidget);
        m.saveAllNotes();
        ouvrirNote(nouvelle_note);
    }
    delete x;
}

void PluriNotes::reactToPannelToggle(bool checked){
    if (checked){
        ui.relationTree->setMaximumWidth(300);
    }
    else {
        ui.relationTree->setMaximumWidth(0);
    }
}

void PluriNotes::removeBtnClicked(){
    NotesManager& m = NotesManager::getManager();

    if (ui.listWidget->currentItem()){
        QString text = ui.listWidget->currentItem()->text();
        if (text!=""){
            m.removeNote(text);
        }
        ui.bin->addItem(text);
        ouvrirProjet();
        if (ui.noteViewer->isOpen(text))
            ui.noteViewer->closeNote(text);
    }
}

void PluriNotes::restoreBtnClicked(){

    NotesManager& m = NotesManager::getManager();
    if (ui.bin->currentItem()){
        QString text = ui.bin->currentItem()->text();
        qDebug()<<"restoring note"<<text;
        if (text!=""){
            m.restoreNote(text);
            qDebug()<<"note restored"<<text;
        }
        qDebug()<<ui.bin->currentItem()->text();
        ui.bin->takeItem(ui.bin->currentRow());
        qDebug()<<"openig project"<<text;

        ouvrirProjet();
    }
}

PluriNotes::~PluriNotes()
{
    NotesManager::freeManager();
}
