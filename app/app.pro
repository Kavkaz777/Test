TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
   load.c \
    showreveven.c \
    text/process_forward.c \
    text/remove_all.c \
    text/append_line.c

HEADERS += \
    myfunc.h \
    common.h \
    text/text.h \
    text/_text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
