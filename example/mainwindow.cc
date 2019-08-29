/*******************************************************************************
 * Copyright (c) 2019, Induspotis, Inc.
 * All rights reserved.
 *
 * mainwindow : [description]
 *
 * filename : mainwindow.cc
 * author   : hubq(hubq@induspotis.com)
 * create   : 2019-08-16 02:08:34 UTC
 * modified : 2019-08-16 02:08:34 UTC
\******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "src/qslidetext.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Inner Scope Objects
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//
MainWindow::MainWindow(QWidget* parent)
  : QWidget(parent)
  , ui(new Ui::MainWindow())
{
  init();
}

void MainWindow::init()
{
  ui->setupUi(this);

  ui->_qslidetext_2->setMode(QSlideText::SlideMode::Slide);
  ui->_qslidetext_3->setMode(QSlideText::SlideMode::Intermittent);
  ui->_qslidetext_6->setMode(QSlideText::SlideMode::Slide);
  ui->_qslidetext_6->setSpeed(QSlideText::SlideSpeed::Fast);

  ui->_qslidetext_4->setAlign(QSlideText::AlignRight);
  ui->_qslidetext_5->setAlign(QSlideText::AlignLeft);
  ui->_qslidetext_5->setMode(QSlideText::SlideMode::Intermittent);

}

////////////////////////////////////////////////////////////////////////////////
// Functions
//

////////////////////////////////// EOF /////////////////////////////////////////
