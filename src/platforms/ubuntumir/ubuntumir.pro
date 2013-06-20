TARGET = qubuntumir
TEMPLATE = lib

QT += core-private gui-private platformsupport-private sensors-private

DEFINES += MESA_EGL_NO_X11_HEADERS
QMAKE_CXXFLAGS += -fvisibility=hidden -fvisibility-inlines-hidden
QMAKE_LFLAGS += -Wl,-no-undefined

CONFIG(debug) {
  QMAKE_CXXFLAGS_DEBUG += -Werror
}

SOURCES = main.cc 

CONFIG += plugin link_prl

PRE_TARGETDEPS = ../ubuntucommon/libqubuntucommon.a ../base/libubuntubase.a

INCLUDEPATH += ..
LIBS += -L../ubuntucommon -lqubuntucommon -lubuntu_application_api_mirclient -L../base -lubuntubase

OTHER_FILES += ubuntu.json

target.path += $$[QT_INSTALL_PLUGINS]/platforms
INSTALLS += target
