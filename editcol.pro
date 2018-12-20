VERSION = "alpha"
DEFINES += VERSION=\\\"$$VERSION\\\"

TEMPLATE = app
TARGET = editcol
INCLUDEPATH += . src
DEPENDPATH += .

QT += widgets core

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
           src/flexion.h \
           src/irregs.h \
           src/lemcore.h \
           src/lemme.h \
		   src/modele.h \
           src/mainwindow.h \
           src/reglevg.h \

SOURCES += src/ch.cpp \
           src/flexion.cpp \
           src/irregs.cpp \
           src/lemcore.cpp \
           src/lemme.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/modele.cpp \
           src/preanalyse.cpp \
           src/reglevg.cpp

#install
unix: {
    target.path = /usr/bin
    data.files = bin/data/*.*
    data.path = /usr/share/editcol
    INSTALLS += target
    INSTALLS += data
}
