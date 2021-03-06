TEMPLATE = app
TARGET = PluriNotes

QT += core \
      xml \
      multimedia \
      multimediawidgets \
      widgets \
      gui
HEADERS += Article.h \
    ArticleEditeur.h \
    NoteEditeur.h \
    NoteManager.h \
    Notes.h \
    nouvellenote.h \
    PluriNotes.h \
    Media.h \
    MediaEditeur.h \
    player.h \
    SettingsDialog.h \
    NoteViewer.h \
    observator.h \
    Relation.h \
    RelationManager.h \
    RelationWindow.h \
    RelationTree.h \
    tache.h \
    tacheediteur.h
SOURCES += Article.cpp \
    ArticleEditeur.cpp \
    main.cpp \
    NoteEditeur.cpp \
    NoteManager.cpp \
    Notes.cpp \
    nouvellenote.cpp \
    PluriNotes.cpp \
    Media.cpp \
    MediaEditeur.cpp \
    player.cpp \
    SettingsDialog.cpp \
    NoteViewer.cpp \
    Relation.cpp \
    RelationManager.cpp \
    RelationWindow.cpp \
    RelationTree.cpp \
    tache.cpp \
    tacheediteur.cpp
FORMS += PluriNotes.ui \
    nouvellenote.ui \
    SettingsDialog.ui \
    RelationEditor.ui

