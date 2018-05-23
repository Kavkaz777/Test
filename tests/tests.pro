include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     tst_test1.h \
    ../app/common.h\
   ../app/text/_text.h\
  ../app/text/text.h\
  fibonachi_test.h/


SOURCES +=     main.cpp \
    ../app/showreveven.c\
       ../app/load.c\
../app/text/remove_all.c\
../app/text/process_forward.c\
../app/text/append_line.c\
../app/text/create_text.c\

INCLUDEPATH += ../app
