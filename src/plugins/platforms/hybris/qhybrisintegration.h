// Copyright © 2012 Canonical Ltd
// FIXME(loicm) Add copyright notice here.

#ifndef QHYBRISINTEGRATION_H
#define QHYBRISINTEGRATION_H

#include "qhybrisscreen.h"
#include <qpa/qplatformintegration.h>
#include <qpa/qplatformscreen.h>

class QAbstractEventDispatcher;
class QHybrisInput;

class QHybrisIntegration : public QPlatformIntegration {
 public:
  QHybrisIntegration();
  ~QHybrisIntegration();

  bool hasCapability(QPlatformIntegration::Capability cap) const;
  QAbstractEventDispatcher* guiThreadEventDispatcher() const { return eventDispatcher_; }
  QPlatformWindow* createPlatformWindow(QWindow* window) const;
  QPlatformWindow* createPlatformWindow(QWindow* window);
  QPlatformBackingStore* createPlatformBackingStore(QWindow* window) const;
  QPlatformOpenGLContext* createPlatformOpenGLContext(QOpenGLContext* context) const;
  QPlatformFontDatabase* fontDatabase() const { return fontDb_; }
  QVariant styleHint(QPlatformIntegration::StyleHint hint) const;

  // FIXME(loicm) Only one window can be created for now, remove that function when adding support
  //     for multiple windows.
  QPlatformWindow* platformWindow() const { return window_; }

 private:
  QAbstractEventDispatcher* eventDispatcher_;
  QPlatformWindow* window_;
  QPlatformFontDatabase* fontDb_;
  QPlatformScreen* screen_;
  QHybrisInput* input_;
};

#endif  // QHYBRISINTEGRATION_H
