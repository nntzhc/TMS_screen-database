FORMS += \
    menuwidget.ui \
    sortwidget.ui \
    mainwidget.ui \
    loginwidget.ui \
    signupwidget.ui \
    selectmodewidget.ui \
    singlemode.ui \
    seriesmode.ui \
    modifymode.ui \
    fileswidget.ui \
    tipsdlg.ui \
    addmode.ui


HEADERS += \
    menuwidget.h \
    sortwidget.h \
    mainwidget.h \
    loginwidget.h \
    signupwidget.h \
    selectmodewidget.h \
    singlemode.h \
    seriesmode.h \
    modifymode.h \
    fileswidget.h \
#    studentinfo.h \
    tipsdlg.h \
    patientinfo.h \
    schemeinfo.h \
    addmode.h \
    sqlitedbaoperator.h \
    dbpage.h \
#    frmdbpage.h


SOURCES += \
    menuwidget.cpp \
    sortwidget.cpp \
    mainwidget.cpp \
    main.cpp \
    loginwidget.cpp \
    signupwidget.cpp \
    selectmodewidget.cpp \
    singlemode.cpp \
    seriesmode.cpp \
    modifymode.cpp \
    fileswidget.cpp \
    tipsdlg.cpp \
    patientinfo.cpp \
    schemeinfo.cpp \
    addmode.cpp \
    sqlitedbaoperator.cpp \
    dbpage.cpp
#    frmdbpage.cpp


QT += widgets

QT       += core gui sql
