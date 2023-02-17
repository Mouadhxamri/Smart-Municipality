QT       += core gui sql network printsupport testlib serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia testlib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    amende.cpp \
    arduino.cpp \
    arduno_temp.cpp \
    certifdeces.cpp \
    citoyent.cpp \
    client.cpp \
    commerciale.cpp \
    connexion.cpp \
    contrat.cpp \
    departement.cpp \
    employe.cpp \
    excel.cpp \
    fourriere.cpp \
    login.cpp \
    lumiere.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    permisconstr.cpp \
    server.cpp \
    temp.cpp \
    vehicule.cpp

HEADERS += \
    amende.h \
    arduino.h \
    arduno_temp.h \
    certifdeces.h \
    citoyent.h \
    client.h \
    commerciale.h \
    connexion.h \
    contrat.h \
    departement.h \
    employe.h \
    excel.h \
    fourriere.h \
    login.h \
    lumiere.h \
    mainwindow.h \
    notification.h \
    permisconstr.h \
    server.h \
    temp.h \
    vehicule.h

FORMS += \
    client.ui \
    login.ui \
    lumiere.ui \
    mainwindow.ui \
    server.ui \
    temp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    iconn.qrc \
    img.qrc \
