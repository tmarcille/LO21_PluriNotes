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
    tache.h \
    tacheediteur.h \
    relation.h \
    relationediteur.h \
    relationmanager.h
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
    tache.cpp \
    tacheediteur.cpp
FORMS += PluriNotes.ui \
    nouvellenote.ui \
    SettingsDialog.ui

