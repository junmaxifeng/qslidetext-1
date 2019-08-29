/*******************************************************************************
 * Copyright (c) 2018, Induspotis, Inc.
 * All rights reserved.s
 *
 * qslide : [description]
 *
 * filename : qslide.h
 * author   : Sluvian(wy@hit.edu.cn)
 * create   : 2018-09-17 07:52:02 UTC
 * modified : 2019-08-16 06:35:56 UTC
\******************************************************************************/

#ifndef __QSLIDETEXT_HPP__
#define __QSLIDETEXT_HPP__

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include <QWidget>
#include <QtGui>

#include "qslidetext_config.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Inner Scope Objects
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//
class QSlideTextPrivate;
class QSLIDETEXT_API QSlideText : public QWidget
{
  Q_OBJECT
  Q_ENUMS(SlideMode)
  Q_ENUMS(SlideSpeed)
  Q_ENUMS(Alignment)
  Q_PROPERTY(QString text READ text WRITE setText)
  Q_PROPERTY(SlideMode mode READ mode WRITE setMode)
  Q_PROPERTY(SlideSpeed speed READ speed WRITE setSpeed)
  Q_PROPERTY(Alignment align READ align WRITE setAlign)
  Q_PROPERTY(int gridStep READ gridStep WRITE setGridStep)
  Q_PROPERTY(int space READ space WRITE setSpace)
  Q_PROPERTY(QColor boderColor READ boderColor WRITE setBoderColor)
  Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
  Q_PROPERTY(QColor gridColor READ gridColor WRITE setGridColor)
  Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor)

 public:
  enum SlideMode {
    Still,
    Slide,
    Intermittent,
  };

  enum SlideSpeed {
    VerySlow,
    Slow,
    Normal,
    Fast,
    VeryFast,
  };

  enum Alignment {
    AlignLeft,
    AlignCenter,
    AlignRight,
  };

 public:
  // clang-format off
  explicit QSlideText(QWidget* parent = nullptr);
  explicit QSlideText(const QString& text, QWidget* parent = nullptr);
  explicit QSlideText(const QString& text, SlideMode mode, QWidget* parent = nullptr);
  explicit QSlideText(const QString& text, Alignment align, QWidget* parent = nullptr);
  explicit QSlideText(const QString& text, SlideMode mode, Alignment align, QWidget* parent = nullptr);
  // clang-format on
  ~QSlideText();

 public:
  QString    text() const;
  SlideMode  mode() const;
  SlideSpeed speed() const;
  Alignment  align() const;
  int        gridStep() const;
  int        space() const;
  QColor     boderColor() const;
  QColor     backgroundColor() const;
  QColor     gridColor() const;
  QColor     textColor() const;

 public slots:
  void setText(const QString& text);
  void setMode(SlideMode mode);
  void setSpeed(SlideSpeed speed);
  void setAlign(Alignment align);
  void setGridStep(int gridStep);
  void setSpace(int space);
  void setBoderColor(QColor boderColor);
  void setBackgroundColor(QColor backgroundColor);
  void setGridColor(QColor gridColor);
  void setTextColor(QColor textColor);

 public:
  virtual QSize minimumSizeHint() const override;

 protected:
  virtual void paintEvent(QPaintEvent* e) override;
  virtual void resizeEvent(QResizeEvent* e) override;
  virtual bool event(QEvent* ev) override;

 private:
  Q_DECLARE_PRIVATE(QSlideText)
  QSlideTextPrivate* const d_ptr;
};

////////////////////////////////////////////////////////////////////////////////
// Functions
//
#endif  // __QSLIDETEXT_HPP__

////////////////////////////////// EOF /////////////////////////////////////////