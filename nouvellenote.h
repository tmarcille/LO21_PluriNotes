//fenetre de cr�ation d'une note

#ifndef NOUVELLENOTE_H
#define NOUVELLENOTE_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class NouvelleNote;
}

/**
 * \brief La classe NouvelleNote permet de g�n�rer une fenetre pour cr�er une nouvelle note
 * \details Dans cette fenetre l'utilisateur peut choisir le type et l'id d'une note
 *
 */
class NouvelleNote : public QDialog
{
    Q_OBJECT

public:
    explicit NouvelleNote(QWidget *parent = 0);
    ~NouvelleNote();

    /**
     * \brief Nom que l'utilisateur a rentre pour la note.
     * \return QString avec le nom.
     */
    QString getNom() const;

    /**
     * \brief Type de Note que l'utilisateur a selectionne.
     * \return QString avec le type.
     */
	QString getSelectedType() const;
private:
    Ui::NouvelleNote *ui;
	
    public slots:

};

#endif // NOUVELLENOTE_H
