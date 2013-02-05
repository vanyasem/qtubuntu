// This file is part of QtUbuntu, a set of Qt components for Ubuntu.
// Copyright © 2013 Canonical Ltd.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; version 3.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef QUBUNTUBASEINTEGRATION_H
#define QUBUNTUBASEINTEGRATION_H

#include <qpa/qplatformintegration.h>

class QAbstractEventDispatcher;

class QUbuntuBaseIntegration : public QPlatformIntegration {
 public:
  QUbuntuBaseIntegration();
  ~QUbuntuBaseIntegration();

  // QPlatformIntegration methods.
  bool hasCapability(QPlatformIntegration::Capability cap) const;
  QAbstractEventDispatcher* guiThreadEventDispatcher() const { return eventDispatcher_; }
  QPlatformNativeInterface* nativeInterface() const { return nativeInterface_; }
  QPlatformBackingStore* createPlatformBackingStore(QWindow* window) const;
  QPlatformOpenGLContext* createPlatformOpenGLContext(QOpenGLContext* context) const;
  QPlatformOpenGLContext* createPlatformOpenGLContext(QOpenGLContext* context);
  QPlatformFontDatabase* fontDatabase() const { return fontDb_; }
  QPlatformClipboard* clipboard() const { return clipboard_; }
  QStringList themeNames() const;
  QPlatformTheme* createPlatformTheme(const QString& name) const;

 private:
  QAbstractEventDispatcher* eventDispatcher_;
  QPlatformNativeInterface* nativeInterface_;
  QPlatformFontDatabase* fontDb_;
  QPlatformClipboard* clipboard_;
};

#endif  // QUBUNTUBASEINTEGRATION_H
