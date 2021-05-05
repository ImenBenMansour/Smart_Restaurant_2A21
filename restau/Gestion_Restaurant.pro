#-------------------------------------------------
#
# Project created by QtCreator 2021-05-02T13:18:40
#
#-------------------------------------------------

QT       += core gui sql multimedia printsupport charts network serialport  network

CONFIG +=console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gestion_Restaurant
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++11

SOURCES += \
    Plat_recette/arduinofer.cpp \
    RH/arduino.cpp \
        main.cpp \
        welcome.cpp \
    connection.cpp \
    Plat_recette/plat.cpp \
    Plat_recette/recette.cpp \
    Plat_recette/palt_recette.cpp \
    Reservation/commande.cpp \
    Reservation/reservation.cpp \
    Reservation/reservation_commande.cpp \
    Produit_equipement/equipement.cpp \
    Produit_equipement/notification.cpp \
    Produit_equipement/produit.cpp \
    Produit_equipement/produit_equipement.cpp \
    Fidelite/c_abonne.cpp \
    Fidelite/c_carte.cpp \
    Fidelite/smtp.cpp \
    Fidelite/abonne.cpp \
    RH/employe.cpp \
    RH/qrcode.cpp \
    RH/qrcodegeneratordemo.cpp \
    RH/qrcodegeneratorworker.cpp \
    RH/qrwidget.cpp \
    RH/role.cpp \
    RH/rh.cpp \
    Event/event.cpp \
    Event/partenaires.cpp \
    Event/gestionevent.cpp \
    login.cpp

HEADERS += \
    Plat_recette/arduinofer.h \
    RH/arduino.h \
    arduino.h \
        welcome.h \
    connection.h \
    Plat_recette/plat.h \
    Plat_recette/recette.h \
    Plat_recette/palt_recette.h \
    Reservation/commande.h \
    Reservation/reservation.h \
    Reservation/reservation_commande.h \
    Produit_equipement/equipement.h \
    Produit_equipement/notification.h \
    Produit_equipement/produit.h \
    Produit_equipement/produit_equipement.h \
    Fidelite/c_abonne.h \
    Fidelite/c_carte.h \
    Fidelite/smtp.h \
    Fidelite/abonne.h \
    RH/employe.h \
    RH/qrcode.h \
    RH/qrwidget.h \
    RH/role.h \
    RH/stats.h \
    RH/rh.h \
    Event/event.h \
    Event/partenaires.h \
    Event/gestionevent.h \
    login.h

FORMS += \
        welcome.ui \
    Plat_recette/palt_recette.ui \
    Reservation/reservation_commande.ui \
    Produit_equipement/produit_equipement.ui \
    Fidelite/abonne.ui \
    RH/rh.ui \
    Event/gestionevent.ui \
    login.ui

RESOURCES += \
    icons.qrc \
    sounds.qrc \
    style.qrc \
    traduction.qrc

DISTFILES +=
