QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_math_lib_test.cpp

HEADERS += ../app/math_lib.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../math_lib/release/ -lmath_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../math_lib/debug/ -lmath_lib
else:unix: LIBS += -L$$OUT_PWD/../math_lib/ -lmath_lib

INCLUDEPATH += $$PWD/../math_lib
DEPENDPATH += $$PWD/../math_lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../math_lib/release/libmath_lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../math_lib/debug/libmath_lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../math_lib/release/math_lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../math_lib/debug/math_lib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../math_lib/libmath_lib.a
