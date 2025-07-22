QT       += core gui
QT       += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   += c++17
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    Login.cpp \
    addproducts.cpp \
    admin.cpp \
    cashier_product.cpp \
    cashier.cpp \
    cashierwindow.cpp \
    database.cpp \
    globals.cpp \
    inventory.cpp \
    login1.cpp \
    login_failed.cpp \
    login_success.cpp \
    main.cpp \
    person.cpp \
    productmain.cpp \
    products1.cpp \
    report.cpp \
    reportwindow.cpp \
    rw.cpp \
    update.cpp \
    user.cpp \
    utils.cpp

HEADERS += \
    Login.h \
    addproducts.h \
    admin.h \
    cashier_product.h \
    cashier.h \
    cashierwindow.h \
    classes.h \
    dashboard.h \
    dashboard.h \
    database.h \
    functions.h \
    globals.h \
    inventory.h \
    login1.h \
    login_failed.h \
    login_success.h \
    person.h \
    productmain.h \
    products1.h \
    report.h \
    reportwindow.h \
    rw.h \
    update.h \
    user.h \
    utils.h

FORMS += \
    Login.ui \
    cashier.ui\
    addproducts.ui \
    cashier_product.ui \
    cashierwindow.ui \
    login1.ui \
    login_failed.ui \
    update.ui\
    login_success.ui \
    products1.ui \
    reportwindow.ui \
    rw.ui

# Deployment paths
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# ========== OpenCV Setup (Version 4.11) ==========

# Set OpenCV Directory (make sure this path is correct)
OPENCV_DIR = E:/build1/install

# Include OpenCV headers
INCLUDEPATH += $$OPENCV_DIR/include
INCLUDEPATH += $$OPENCV_DIR/include/opencv2

# Library paths (for MinGW)
win32:CONFIG(release, debug|release): LIBS += -L$$OPENCV_DIR/x64/mingw/lib \
    -lopencv_core4110 \
    -lopencv_imgproc4110 \
    -lopencv_highgui4110 \
    -lopencv_imgcodecs4110 \
    -lopencv_objdetect4110 \
    -lopencv_video4110 \
    -lopencv_videoio4110 \
    -lopencv_features2d4110 \
    -lopencv_flann4110\
     -lopencv_face4110

win32:CONFIG(debug, debug|release): LIBS += -L$$OPENCV_DIR/x64/mingw/lib \
    -lopencv_core4110 \
    -lopencv_imgproc4110 \
    -lopencv_highgui4110 \
    -lopencv_imgcodecs4110 \
    -lopencv_objdetect4110 \
    -lopencv_video4110 \
    -lopencv_videoio4110 \
    -lopencv_features2d4110 \
    -lopencv_flann4110\
     -lopencv_face4110

QT+= network
QT += core gui multimedia
QT += core gui widgets multimedia multimediawidgets network
QT += printsupport





QMAKE_CXXFLAGS += -Wa,-mbig-obj


