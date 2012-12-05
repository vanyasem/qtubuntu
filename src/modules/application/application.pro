TARGET = ubuntuapplicationplugin
TEMPLATE = lib

QT += quick-private qml-private

QMAKE_CXXFLAGS += -fvisibility=hidden -fvisibility-inlines-hidden
QMAKE_LFLAGS += -Wl,-no-undefined

CONFIG(debug) {
  QMAKE_CXXFLAGS_DEBUG += -Werror
}

SOURCES = plugin.cc \
          application_manager.cc

HEADERS = application_manager.h \
          logging.h

CONFIG += plugin

INCLUDEPATH += /usr/include/hybris
LIBS += -lubuntu_application_api

target.files += libubuntuapplicationplugin.so qmldir
target.path += $$[QT_INSTALL_IMPORTS]/Ubuntu/Application
INSTALLS += target