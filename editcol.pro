VERSION = "alpha"
DEFINES += VERSION=\\\"$$VERSION\\\"

TEMPLATE = app
TARGET = editcol
INCLUDEPATH += . src
DEPENDPATH += .

QT += widgets

# QMAKE_CXXFLAGS += -Wall -Wextra -pedantic -fstack-protector-strong
# QMAKE_CPPFLAGS += -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2

CONFIG += release_binary

# TRANSLATIONS    = collatinus_fr.ts
# TRANSLATIONS    += collatinus_en.ts

unix:!macx:DESTDIR = bin
OBJECTS_DIR= obj/
MOC_DIR = moc/
QMAKE_DISTCLEAN += $${DESTDIR}/editcol

# Input
HEADERS += src/ch.h \
           src/diff_match_patch.cpp \
           src/flexion.h \
           src/irregs.h \
           src/lemCore.h \
           src/lemme.h \
		   src/modele.h \
           src/mainwindow.h 

SOURCES += src/ch.cpp \
           src/diff_match_patch.h \
           src/flexion.cpp \
           src/irregs.cpp \
           src/lemCore.cpp \
           src/lemme.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/modele.cpp

#RESOURCES += editcol.qrc
#RC_ICONS = res/editcol.ico
