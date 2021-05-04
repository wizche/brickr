######################################################################
# Automatically generated by qmake (2.01a) ven. oct. 21 15:07:33 2016
######################################################################

TEMPLATE = app
TARGET = brickr
CONFIG += c++11
DEPENDPATH += . forms src
INCLUDEPATH += . src
INCLUDEPATH += ./vcglib/
INCLUDEPATH += ./vcglib/eigenlib
QT += svg opengl
LIBS += -lGLU
QMAKE_CXXFLAGS += -std=c++11

# Input
HEADERS += src/AssemblyPlugin.h \
           src/AssemblyWidget.h \
           src/LegoBrick.h \
           src/LegoCloud.h \
           src/LegoCloudNode.h \
           src/LegoDimensions.h \
           src/LegoGraph.h \
           src/model.h \
           src/openglscene.h \
           src/QDebugStream.h \
           src/Vector3.h \
           src/Modeler.h 
FORMS += forms/AssemblyWidget.ui
SOURCES += src/AssemblyPlugin.cpp \
           src/AssemblyWidget.cpp \
           src/LegoCloud.cpp \
           src/LegoCloudNode.cpp \
           src/main.cpp \
           src/model.cpp \
           src/openglscene.cpp \
           src/Modeler.cpp 
