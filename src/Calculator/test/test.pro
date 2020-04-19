QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_math_lib_test.cpp

LIBS +=

unix:!macx: LIBS += -L$$OUT_PWD/../math_lib/ -lmath_lib

INCLUDEPATH += $$PWD/../math_lib
DEPENDPATH += $$PWD/../math_lib

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../math_lib/libmath_lib.a
