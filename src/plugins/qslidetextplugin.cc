/*******************************************************************************
 * Copyright (c) 2018, Induspotis, Inc.
 * All rights reserved.
 *
 * xtlibuxcarbonplugins : [description]
 *
 * filename : xtlibuxcarbonplugins.cc
 * author   : hunt978(hubq@induspotis.com)
 * create   : 2018-11-19 07:56:10 UTC
 * modified : 2018-12-09 02:29:47 UTC
\******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include <QtCore/qplugin.h>
#include <QtDesigner/QtDesigner>

#include "../qslidetext.h"
#include "qwidgetplugin.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Inner Scope Objects
//
using QSlideTextPlugin = QWidgetPluginT<QSlideText>;

////////////////////////////////////////////////////////////////////////////////
// Classes
//

class QSlideTextPluginCollection : public QObject,
                                   public QDesignerCustomWidgetCollectionInterface
{
  Q_OBJECT

  Q_PLUGIN_METADATA(
    IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
  Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

  QList<QDesignerCustomWidgetInterface*> plugins;

 public:
  QSlideTextPluginCollection(QObject* parent = 0)
    : QObject(parent)
  {
    plugins.append(new QSlideTextPlugin(this));
  }

  QList<QDesignerCustomWidgetInterface*> customWidgets() const Q_DECL_OVERRIDE
  {
    return plugins;
  }
};

////////////////////////////////////////////////////////////////////////////////
// Functions
//

////////////////////////////////// EOF /////////////////////////////////////////

#include "qslidetextplugin.moc"