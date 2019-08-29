/*******************************************************************************
 * Copyright (c) 2019, Induspotis, Inc.
 * All rights reserved.
 *
 * qwidgetplugin : [description]
 *
 * filename : qwidgetplugin.h
 * author   : hubq(hubq@induspotis.com)
 * create   : 2019-08-06 03:22:47 UTC
 * modified : 2019-08-16 07:14:20 UTC
\******************************************************************************/

#ifndef __QWIDGETPLUGIN_H__
#define __QWIDGETPLUGIN_H__

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include <QWidget>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>

#include <functional>
#include <type_traits>
#include <typeinfo>

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//
template <class QWidgetClass, bool isWidgetContainer = false,
  bool isUseDefaultCreator = true>
class QWidgetPluginT : public QObject, public QDesignerCustomWidgetInterface
{
  // Q_OBJECT
  Q_INTERFACES(QDesignerCustomWidgetInterface)

 public:
  QWidgetPluginT(QObject* parent = nullptr);

 public:
  virtual bool     isContainer() const override;
  virtual bool     isInitialized() const override;
  virtual QIcon    icon() const override;
  virtual QString  domXml() const override;
  virtual QString  group() const override;
  virtual QString  includeFile() const override;
  virtual QString  name() const override;
  virtual QString  toolTip() const override;
  virtual QString  whatsThis() const override;
  virtual QWidget* createWidget(QWidget* parent) override;
  virtual void     initialize(QDesignerFormEditorInterface* core) override;

 private:
  bool initialized = false;
};

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QWidgetPluginT<QWidgetClass, isWidgetContainer, isUseDefaultCreator>::QWidgetPluginT(
  QObject* parent)
  : QObject(parent)
{
  initialized = false;
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
void QWidgetPluginT<QWidgetClass, isWidgetContainer, isUseDefaultCreator>::initialize(
  QDesignerFormEditorInterface* /* core */)
{
  if (initialized)
    return;

  initialized = true;
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
bool QWidgetPluginT<QWidgetClass, isWidgetContainer,
  isUseDefaultCreator>::isInitialized() const
{
  return initialized;
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QWidget* QWidgetPluginT<QWidgetClass, isWidgetContainer, isUseDefaultCreator>::createWidget(
  QWidget* parent)
{
  using creatorType =
    std::conditional<isUseDefaultCreator, QWidgetClass, QWidget>::type;
  return new creatorType(parent);
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QString QWidgetPluginT<QWidgetClass, isWidgetContainer, isUseDefaultCreator>::name() const
{
  const auto& typeName = QString(typeid(QWidgetClass).name());
  const auto  startPos = typeName.lastIndexOf(" ");
  if (startPos >= 0) {
    return typeName.right(typeName.size() - startPos - 1);
  } else {
    return typeName;
  }
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QString QWidgetPluginT<QWidgetClass, isWidgetContainer, isUseDefaultCreator>::group() const
{
  return "QWidget";
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QIcon QWidgetPluginT<QWidgetClass, isWidgetContainer, isUseDefaultCreator>::icon() const
{
  return QIcon();
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QString QWidgetPluginT<QWidgetClass, isWidgetContainer, isUseDefaultCreator>::toolTip() const
{
  return "A widget provided by qwidgetplugin";
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QString QWidgetPluginT<QWidgetClass, isWidgetContainer,
  isUseDefaultCreator>::whatsThis() const
{
  return "A widget provided by qwidgetplugin";
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
bool QWidgetPluginT<QWidgetClass, isWidgetContainer,
  isUseDefaultCreator>::isContainer() const
{
  return isWidgetContainer;
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QString QWidgetPluginT<QWidgetClass, isWidgetContainer, isUseDefaultCreator>::domXml() const
{
  return "<widget class=\"" + name()
         + "\" "
           "name=\"_"
         + name().toLower() + "\"/>\n";
}

template <class QWidgetClass, bool isWidgetContainer, bool isUseDefaultCreator>
QString QWidgetPluginT<QWidgetClass, isWidgetContainer,
  isUseDefaultCreator>::includeFile() const
{
  return "";
}

////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __QWIDGETPLUGIN_H__
////////////////////////////////// EOF /////////////////////////////////////////
