/*******************************************************************************
 * Copyright (c) 2019, Induspotis, Inc.
 * All rights reserved.
 *
 * qslidetext_p : [description]
 *
 * filename : qslidetext_p.h
 * author   : hubq(hubq@induspotis.com)
 * create   : 2019-08-16 02:08:34 UTC
 * modified : 2019-08-16 06:18:51 UTC
\******************************************************************************/

#ifndef __QSLIDETEXT_P_H__
#define __QSLIDETEXT_P_H__

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include <QColor>

#include "qslidetext.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//
class QSlideTextPrivate
{
  Q_DECLARE_PUBLIC(QSlideText);
  QSlideText* const q_ptr;

 public:
  QSlideTextPrivate(QSlideText* q);

 public:
  void init();
  void update(bool repaint = false);

 public:
  QString                m_text;
  QSlideText::SlideMode  m_mode;
  QSlideText::SlideSpeed m_speed;
  QSlideText::Alignment  m_algin;
  int                    m_gridStep;
  int                    m_space;
  QColor                 m_boderColor;
  QColor                 m_backgroundColor;
  QColor                 m_gridColor;
  QColor                 m_textColor;

  int   m_drawPosX;
  int   m_drawPosY;
  QRect m_drawRect;
  QRect m_textRect;
  bool  m_isDrawText;

  QPixmap m_bckLayerKf;
  QPixmap m_bckLayer;
  QPixmap m_txtLayer;
  QPixmap m_gridLayer;

  QTimer m_timer;
};

////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __QSLIDETEXT_P_H__
////////////////////////////////// EOF /////////////////////////////////////////
