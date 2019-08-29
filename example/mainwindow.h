/*******************************************************************************
 * Copyright (c) 2019, Induspotis, Inc.
 * All rights reserved.
 *
 * mainwindow : [description]
 *
 * filename : mainwindow.h
 * author   : hubq(hubq@induspotis.com)
 * create   : 2019-08-16 02:08:34 UTC
 * modified : 2019-08-16 06:51:14 UTC
\******************************************************************************/

#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include <QWidget>

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//
namespace Ui {
class MainWindow;
}  // namespace Ui

class MainWindow : public QWidget
{
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);

 protected:
  void init();

 private:
  Ui::MainWindow* ui;
};

////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __MAINWINDOW_H__
////////////////////////////////// EOF /////////////////////////////////////////
