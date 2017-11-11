/********************************************************************************
** Form generated from reading UI file 'PluriNotes.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLURINOTES_H
#define UI_PLURINOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "NoteViewer.h"
#include "RelationTree.h"

QT_BEGIN_NAMESPACE

class Ui_PluriNotesClass
{
public:
    QAction *actionNote;
    QAction *actionOuvrir;
    QAction *actionDossier_de_stockage;
    QAction *actionOptions;
    QAction *actionRelations;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QPushButton *removeNoteBtn;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *taskList;
    QLabel *label_2;
    QListWidget *bin;
    QPushButton *restoreBtn;
    NoteViewer *noteViewer;
    QGridLayout *relationTreePanelLayout;
    RelationTree *relationTree;
    QHBoxLayout *horizontalLayout;
    QToolButton *toggleBtn;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuNouveau;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PluriNotesClass)
    {
        if (PluriNotesClass->objectName().isEmpty())
            PluriNotesClass->setObjectName(QStringLiteral("PluriNotesClass"));
        PluriNotesClass->resize(1105, 840);
        actionNote = new QAction(PluriNotesClass);
        actionNote->setObjectName(QStringLiteral("actionNote"));
        actionNote->setEnabled(false);
        actionOuvrir = new QAction(PluriNotesClass);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionDossier_de_stockage = new QAction(PluriNotesClass);
        actionDossier_de_stockage->setObjectName(QStringLiteral("actionDossier_de_stockage"));
        actionOptions = new QAction(PluriNotesClass);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionRelations = new QAction(PluriNotesClass);
        actionRelations->setObjectName(QStringLiteral("actionRelations"));
        centralWidget = new QWidget(PluriNotesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(200, 16777215));
        listWidget->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(listWidget);

        removeNoteBtn = new QPushButton(centralWidget);
        removeNoteBtn->setObjectName(QStringLiteral("removeNoteBtn"));

        verticalLayout_2->addWidget(removeNoteBtn);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        taskList = new QListWidget(centralWidget);
        taskList->setObjectName(QStringLiteral("taskList"));
        sizePolicy.setHeightForWidth(taskList->sizePolicy().hasHeightForWidth());
        taskList->setSizePolicy(sizePolicy);
        taskList->setMaximumSize(QSize(200, 16777215));
        taskList->setStyleSheet(QLatin1String("border-color: rgb(180, 180, 180);\n"
"    background-color: rgb(245, 245, 245);"));
        taskList->setFrameShape(QFrame::StyledPanel);
        taskList->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(taskList);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        bin = new QListWidget(centralWidget);
        bin->setObjectName(QStringLiteral("bin"));
        sizePolicy.setHeightForWidth(bin->sizePolicy().hasHeightForWidth());
        bin->setSizePolicy(sizePolicy);
        bin->setMaximumSize(QSize(200, 16777215));
        bin->setStyleSheet(QLatin1String("border-color: rgb(180, 180, 180);\n"
"    background-color: rgb(245, 245, 245);"));

        verticalLayout->addWidget(bin);

        restoreBtn = new QPushButton(centralWidget);
        restoreBtn->setObjectName(QStringLiteral("restoreBtn"));

        verticalLayout->addWidget(restoreBtn);


        horizontalLayout_2->addLayout(verticalLayout);

        noteViewer = new NoteViewer(centralWidget);
        noteViewer->setObjectName(QStringLiteral("noteViewer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(noteViewer->sizePolicy().hasHeightForWidth());
        noteViewer->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(noteViewer);

        relationTreePanelLayout = new QGridLayout();
        relationTreePanelLayout->setSpacing(6);
        relationTreePanelLayout->setObjectName(QStringLiteral("relationTreePanelLayout"));
        relationTree = new RelationTree(centralWidget);
        relationTree->setObjectName(QStringLiteral("relationTree"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(relationTree->sizePolicy().hasHeightForWidth());
        relationTree->setSizePolicy(sizePolicy2);
        relationTree->setMaximumSize(QSize(0, 16777215));

        relationTreePanelLayout->addWidget(relationTree, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toggleBtn = new QToolButton(centralWidget);
        toggleBtn->setObjectName(QStringLiteral("toggleBtn"));
        toggleBtn->setCursor(QCursor(Qt::PointingHandCursor));
        toggleBtn->setCheckable(true);
        toggleBtn->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout->addWidget(toggleBtn);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);


        relationTreePanelLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(relationTreePanelLayout);

        PluriNotesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PluriNotesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1105, 21));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(false);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuNouveau = new QMenu(menuFichier);
        menuNouveau->setObjectName(QStringLiteral("menuNouveau"));
        PluriNotesClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(PluriNotesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PluriNotesClass->setStatusBar(statusBar);
        toolBar = new QToolBar(PluriNotesClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        PluriNotesClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(menuNouveau->menuAction());
        menuFichier->addSeparator();
        menuFichier->addAction(actionOptions);
        menuFichier->addAction(actionRelations);
        menuNouveau->addAction(actionNote);

        retranslateUi(PluriNotesClass);

        QMetaObject::connectSlotsByName(PluriNotesClass);
    } // setupUi

    void retranslateUi(QMainWindow *PluriNotesClass)
    {
        PluriNotesClass->setWindowTitle(QApplication::translate("PluriNotesClass", "PluriNotes", Q_NULLPTR));
        actionNote->setText(QApplication::translate("PluriNotesClass", "Note", Q_NULLPTR));
        actionOuvrir->setText(QApplication::translate("PluriNotesClass", "Ouvrir...", Q_NULLPTR));
        actionDossier_de_stockage->setText(QApplication::translate("PluriNotesClass", "Dossier de stockage", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("PluriNotesClass", "Settings...", Q_NULLPTR));
        actionRelations->setText(QApplication::translate("PluriNotesClass", "Relations..", Q_NULLPTR));
        label_3->setText(QApplication::translate("PluriNotesClass", "Notes :", Q_NULLPTR));
        removeNoteBtn->setText(QApplication::translate("PluriNotesClass", "Supprimer Note", Q_NULLPTR));
        label->setText(QApplication::translate("PluriNotesClass", "To-Do List :", Q_NULLPTR));
        label_2->setText(QApplication::translate("PluriNotesClass", "Corbeille :", Q_NULLPTR));
        restoreBtn->setText(QApplication::translate("PluriNotesClass", "Retablir Note", Q_NULLPTR));
        toggleBtn->setText(QApplication::translate("PluriNotesClass", "Arborescence", Q_NULLPTR));
        menuFichier->setTitle(QApplication::translate("PluriNotesClass", "Fichiers", Q_NULLPTR));
        menuNouveau->setTitle(QApplication::translate("PluriNotesClass", "Nouveau", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("PluriNotesClass", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PluriNotesClass: public Ui_PluriNotesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLURINOTES_H
