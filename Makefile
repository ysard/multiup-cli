#############################################################################
# Makefile for building: multiup_cli
# Generated by qmake (3.0) (Qt 5.4.0)
# Project:  multiup_cli.pro
# Template: app
# Command: /media/DATA/Qt_unix/5.4/gcc_64/bin/qmake -o Makefile multiup_cli.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DCURL_STATICLIB -DHTTP_ONLY
CFLAGS        = -pipe -O2 -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -fPIE $(DEFINES)
INCPATH       = -I../../../Qt_unix/5.4/gcc_64/mkspecs/linux-g++ -I. -Idependances-developpement/curl-7.44.0-devel-unix-static/include
QMAKE         = /media/DATA/Qt_unix/5.4/gcc_64/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = multiup_cli1.0.0
DISTDIR = /media/DATA/Projets/multiup/multiup_cli/.tmp/multiup_cli1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/media/DATA/Qt_unix/5.4/gcc_64
LIBS          = $(SUBLIBS) -L./dependances-developpement/curl-7.44.0-devel-unix-static/lib -lcurl 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainClass.cpp \
		dependances-developpement/jsoncpp/dist/jsoncpp.cpp 
OBJECTS       = main.o \
		mainClass.o \
		jsoncpp.o
DIST          = ../../../Qt_unix/5.4/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/shell-unix.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/unix.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/linux.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/qconfig.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_location.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webengine.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webview.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webview_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/lex.prf \
		multiup_cli.pro mainClass.h \
		Config.h \
		dependances-developpement/jsoncpp/dist/json/json-forwards.h \
		dependances-developpement/jsoncpp/dist/json/json.h main.cpp \
		mainClass.cpp \
		dependances-developpement/jsoncpp/dist/jsoncpp.cpp
QMAKE_TARGET  = multiup_cli
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = multiup_cli


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: multiup_cli.pro ../../../Qt_unix/5.4/gcc_64/mkspecs/linux-g++/qmake.conf ../../../Qt_unix/5.4/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/shell-unix.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/unix.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/linux.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/qconfig.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_location.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webengine.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webview.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webview_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt_unix/5.4/gcc_64/mkspecs/features/lex.prf \
		multiup_cli.pro
	$(QMAKE) -o Makefile multiup_cli.pro
../../../Qt_unix/5.4/gcc_64/mkspecs/features/spec_pre.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/common/shell-unix.conf:
../../../Qt_unix/5.4/gcc_64/mkspecs/common/unix.conf:
../../../Qt_unix/5.4/gcc_64/mkspecs/common/linux.conf:
../../../Qt_unix/5.4/gcc_64/mkspecs/common/gcc-base.conf:
../../../Qt_unix/5.4/gcc_64/mkspecs/common/gcc-base-unix.conf:
../../../Qt_unix/5.4/gcc_64/mkspecs/common/g++-base.conf:
../../../Qt_unix/5.4/gcc_64/mkspecs/common/g++-unix.conf:
../../../Qt_unix/5.4/gcc_64/mkspecs/qconfig.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_core.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_core_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_declarative.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designer.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designer_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_enginio.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_gui.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_gui_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_help.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_help_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_location.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_location_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_network.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_network_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_nfc.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_positioning.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qml.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qml_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quick.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quick_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_script.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_script_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sql.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_sql_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_svg.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_svg_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webengine.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkit.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_websockets.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webview.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_webview_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xml.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xml_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/qt_functions.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/qt_config.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/linux-g++/qmake.conf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/spec_post.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/exclusive_builds.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/default_pre.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/resolve_config.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/default_post.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/warn_on.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/testcase_targets.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/exceptions.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/yacc.prf:
../../../Qt_unix/5.4/gcc_64/mkspecs/features/lex.prf:
multiup_cli.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile multiup_cli.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

check: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp mainClass.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/curl.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/curlver.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/curlbuild.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/curlrules.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/easy.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/multi.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/typecheck-gcc.h \
		Config.h \
		dependances-developpement/jsoncpp/dist/json/json-forwards.h \
		dependances-developpement/jsoncpp/dist/json/json.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainClass.o: mainClass.cpp mainClass.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/curl.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/curlver.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/curlbuild.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/curlrules.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/easy.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/multi.h \
		dependances-developpement/curl-7.44.0-devel-unix-static/include/curl/typecheck-gcc.h \
		Config.h \
		dependances-developpement/jsoncpp/dist/json/json-forwards.h \
		dependances-developpement/jsoncpp/dist/json/json.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainClass.o mainClass.cpp

jsoncpp.o: dependances-developpement/jsoncpp/dist/jsoncpp.cpp dependances-developpement/jsoncpp/dist/json/json.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o jsoncpp.o dependances-developpement/jsoncpp/dist/jsoncpp.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
