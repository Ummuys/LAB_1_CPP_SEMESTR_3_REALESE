QT += core gui widgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base_func.cpp \
    main.cpp \
    mainwindow.cpp \
    window_bubblesort.cpp \
    window_datachoise.cpp \
    window_filechoise.cpp \
    window_heapsort.cpp \
    window_insertionsort.cpp \
    window_lenchoise.cpp \
    window_mergesort.cpp \
    window_quicksort.cpp \
    window_selectionsort.cpp \
    work_with_files.cpp

HEADERS += \
    base_func.h \
    mainwindow.h \
    sort.h \
    window_bubblesort.h \
    window_datachoise.h \
    window_filechoise.h \
    window_heapsort.h \
    window_insertionsort.h \
    window_lenchoise.h \
    window_mergesort.h \
    window_quicksort.h \
    window_selectionsort.h \
    work_with_files.h

FORMS += \
    mainwindow.ui \
    window_bubblesort.ui \
    window_datachoise.ui \
    window_filechoise.ui \
    window_heapsort.ui \
    window_insertionsort.ui \
    window_lenchoise.ui \
    window_mergesort.ui \
    window_quicksort.ui \
    window_selectionsort.ui

win32::RC_FILE = icon_rc.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icon_rc.rc
