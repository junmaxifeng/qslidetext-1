/*******************************************************************************
 * Copyright (c) 2018, Induspotis, Inc.
 * All rights reserved.
 *
 * qslide : [description]
 *
 * filename : qslide.cc
 * author   : Sluvian(wy@hit.edu.cn)
 * create   : 2018-09-17 07:52:02 UTC
 * modified : 2018-09-18 01:21:13 UTC
\******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include <QEvent>
#include <QFontMetrics>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

#include "qslidetext.h"
#include "qslidetext_p.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Inner Scope Objects
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//
QSlideTextPrivate::QSlideTextPrivate(QSlideText* q)
    : q_ptr(q)
    , m_text("")
    , m_mode(QSlideText::Still)
    , m_speed(QSlideText::Normal)
    , m_bckLayerKf(1, 1)
    , m_bckLayer(1, 1)
    , m_boderColor(Qt::black)
    , m_backgroundColor(Qt::black)
    , m_gridColor(Qt::black)
    , m_txtLayer(1, 1)
    , m_textColor(Qt::green)
    , m_gridLayer(1, 1)
    , m_drawPosX(0)
    , m_drawPosY(0)
    , m_gridStep(5)
    , m_space(20)
    , m_algin(QSlideText::AlignCenter)
    , m_isDrawText(false)
{}

void QSlideTextPrivate::init()
{
    Q_Q(QSlideText);

    // setup timer
    QObject::connect(&m_timer, &QTimer::timeout, [=]() {
        if (m_mode == QSlideText::Slide) {
            if (m_drawRect.width()) {
                m_drawPosX -= 1;
                if (abs(m_drawPosX + m_space) >= (m_drawRect.width())) {
                    m_drawPosX = 0;
                }
            }
        }
        if (m_mode == QSlideText::Intermittent) {
            if (m_algin == QSlideText::AlignCenter) {
                m_drawPosX = (q->width() - m_textRect.width()) / 2;
            }
            if (m_algin == QSlideText::AlignLeft) {
                m_drawPosX = 0;
            }
            if (m_algin == QSlideText::AlignRight) {
                m_drawPosX = q->width() - m_textRect.width();
            }

            if (!m_isDrawText) {
                m_drawPosX += 3 * m_drawRect.width();
            }

            m_isDrawText = !m_isDrawText;
        }

        q->update();
    });

    // initialize update
    update(true);
}

void QSlideTextPrivate::update(bool repaint)
{
    Q_Q(QSlideText);

    // mode check
    if (m_text.isEmpty()) {
        m_mode = QSlideText::Still;
    }

    // draw backgroud
    /**
     * update by kf   190829
     **/
    if (repaint) {
        int width=q->width();
        int height=q->height();
        // prepare background
        m_bckLayerKf = m_bckLayerKf.scaled(q->size());
        m_bckLayerKf.fill(QColor(255,0,0));
        QPainter painter(&m_bckLayerKf);

        //draw border
        QBrush brush;
        brush.setColor(QColor(0,255,0));//rgb
        brush.setStyle(Qt::Dense1Pattern);
        painter.setBrush(brush);
        for(int i=0;i<width;i+=10)
        {
            painter.drawRect(i, 0, 5, 5);
            painter.drawRect(i, height-1-4, 5, 5);
        }
        for(int j=0;j<height;j+=10)
        {
            painter.drawRect(0, j, 5, 5);
            painter.drawRect(width-1-4, j,5, 5);
        }
    }

    // draw backgroud
    if (repaint) {
        // prepare background
        m_bckLayer = m_bckLayer.scaled(q->size()-QSize(10,10));
        m_bckLayer.fill(QColor(70,70,70));
        QPainter painter(&m_bckLayer);

        // draw boder
        painter.setPen(m_boderColor);
        painter.drawRect(0, 0, q->width() - 1, q->height() - 1);
    }

    // draw grid
    if (repaint) {
        // prepare background
        m_gridLayer = m_gridLayer.scaled(q->size());
        m_gridLayer.fill(QColor(0, 0, 0,0));
        QPainter painter(&m_gridLayer);

        // draw grid
        m_gridColor.setAlpha(100);
        painter.setPen(m_gridColor);
        for (int i = 0; i < q->width(); i += m_gridStep) {
            painter.drawLine(i, 0, i, q->height());
        }
        for (int j = 0; j < q->height(); j += m_gridStep) {
            painter.drawLine(0, j, q->width(), j);
        }
    }

    // draw text
    if (repaint) {
        // fetch font
        QFont font = q->font();
        font.setPixelSize(q->height() * 0.8);

        // test size
        m_textRect = QFontMetrics(font).boundingRect(m_text);
        m_drawRect = m_textRect;
        if (q->width() > m_drawRect.width()) {
            m_drawRect.setWidth(q->width());
        }
        m_drawPosY = (q->height() - m_textRect.height()) / 2;

        // prepare text layer
        if (m_drawRect.width() && m_drawRect.height()) {
            m_txtLayer = m_txtLayer.scaled(m_drawRect.size());
        }
        m_txtLayer.fill(QColor(0, 0, 0, 0));
        QPainter painter(&m_txtLayer);

        // draw text
        painter.setFont(font);
        painter.setPen(m_textColor);
        painter.drawText(m_txtLayer.rect(), 0, m_text);
    }

    // setup timer
    {
        int interval = 0;
        switch (m_speed) {
        case QSlideText::VerySlow:
            interval = 500;
            break;
        case QSlideText::Slow:
            interval = 250;
            break;
        case QSlideText::Fast:
            interval = 25;
            break;
        case QSlideText::VeryFast:
            interval = 5;
            break;
        case QSlideText::Normal:
        default:
            interval = 50;
            break;
        }

        // start timer
        if (m_mode == QSlideText::Slide || m_mode == QSlideText::Intermittent) {
            m_timer.start(interval);
        } else {
            if (m_timer.isActive()) {
                m_timer.stop();
            }
        }
    }

    // update draw position
    {
        if (m_mode == QSlideText::Still) {
            if (m_algin == QSlideText::AlignCenter) {
                m_drawPosX = (q->width() - m_textRect.width()) / 2;
            }
            if (m_algin == QSlideText::AlignLeft) {
                m_drawPosX = 0;
            }
            if (m_algin == QSlideText::AlignRight) {
                m_drawPosX = q->width() - m_textRect.width();
            }
        }
    }

    // request update
    q->update();
}

QSlideText::QSlideText(QWidget* parent)
    : QWidget(parent)
    , d_ptr(new QSlideTextPrivate(this))
{
    d_func()->init();
}

QSlideText::QSlideText(const QString& text, QWidget* parent)
    : QSlideText(parent)
{
    setText(text);
}

QSlideText::QSlideText(const QString& text, SlideMode mode, QWidget* parent)
    : QSlideText(parent)
{
    setText(text);
    setMode(mode);
}

QSlideText::QSlideText(const QString& text, Alignment align, QWidget* parent)
    : QSlideText(parent)
{
    setText(text);
    setAlign(align);
}

QSlideText::QSlideText(
        const QString& text, SlideMode mode, Alignment align, QWidget* parent)
    : QSlideText(parent)
{
    setText(text);
    setMode(mode);
    setAlign(align);
}

QSlideText::~QSlideText()
{
    Q_D(QSlideText);
    d->m_timer.stop();
    delete d_ptr;
}

void QSlideText::paintEvent(QPaintEvent* e)
{
    Q_D(QSlideText);

    QPainter painter(this);
    painter.drawPixmap(0, 0, d->m_bckLayerKf);
    painter.drawPixmap(5, 5, d->m_bckLayer);
    painter.drawPixmap(d->m_drawPosX, d->m_drawPosY, d->m_txtLayer);
    //  painter.drawPixmap(d->m_drawPosX + d->m_space + d->m_drawRect.width(),d->m_drawPosY, d->m_txtLayer);
    painter.drawPixmap(0, 0, d->m_gridLayer);
}

void QSlideText::resizeEvent(QResizeEvent* e)
{
    QWidget::resizeEvent(e);
    Q_D(QSlideText);
    d->update(true);
}

QSlideText::SlideMode QSlideText::mode() const
{
    Q_D(const QSlideText);
    return d->m_mode;
}

void QSlideText::setMode(SlideMode mode)
{
    Q_D(QSlideText);

    if (d->m_mode != mode) {
        d->m_mode = mode;
        d->update();
    }
}

QString QSlideText::text() const
{
    Q_D(const QSlideText);
    return d->m_text;
}

void QSlideText::setText(const QString& text)
{
    Q_D(QSlideText);

    if (d->m_text != text) {
        d->m_text = text;
        d->update(true);
    }
}

QSlideText::SlideSpeed QSlideText::speed() const
{
    Q_D(const QSlideText);
    return d->m_speed;
}

QSlideText::Alignment QSlideText::align() const
{
    Q_D(const QSlideText);
    return d->m_algin;
}

void QSlideText::setSpeed(SlideSpeed speed)
{
    Q_D(QSlideText);

    if (d->m_speed != speed) {
        d->m_speed = speed;
        d->update();
    }
}

void QSlideText::setAlign(Alignment algin)
{
    Q_D(QSlideText);

    if (d->m_algin != algin) {
        d->m_algin = algin;
        d->update();
    }
}

int QSlideText::gridStep() const
{
    Q_D(const QSlideText);
    return d->m_gridStep;
}

int QSlideText::space() const
{
    Q_D(const QSlideText);
    return d->m_space;
}

QColor QSlideText::boderColor() const
{
    Q_D(const QSlideText);
    return d->m_boderColor;
}

QColor QSlideText::backgroundColor() const
{
    Q_D(const QSlideText);
    return d->m_backgroundColor;
}

QColor QSlideText::gridColor() const
{
    Q_D(const QSlideText);
    return d->m_gridColor;
}

QColor QSlideText::textColor() const
{
    Q_D(const QSlideText);
    return d->m_textColor;
}

void QSlideText::setGridStep(int gridStep)
{
    Q_D(QSlideText);

    if (d->m_gridStep != gridStep) {
        d->m_gridStep = (gridStep < 1) ? 1 : gridStep;
        d->update(true);
    }
}

void QSlideText::setSpace(int space)
{
    Q_D(QSlideText);

    if (d->m_space != space) {
        d->m_space = (space < 1) ? 1 : space;
        d->update();
    }
}

void QSlideText::setBoderColor(QColor boderColor)
{
    Q_D(QSlideText);

    if (d->m_boderColor != boderColor) {
        d->m_boderColor = boderColor;
        d->update(true);
    }
}

void QSlideText::setBackgroundColor(QColor backgroundColor)
{
    Q_D(QSlideText);

    if (d->m_backgroundColor != backgroundColor) {
        d->m_backgroundColor = backgroundColor;
        d->update(true);
    }
}

void QSlideText::setGridColor(QColor gridColor)
{
    Q_D(QSlideText);

    if (d->m_gridColor != gridColor) {
        d->m_gridColor = gridColor;
        d->update(true);
    }
}

void QSlideText::setTextColor(QColor textColor)
{
    Q_D(QSlideText);

    if (d->m_textColor != textColor) {
        d->m_textColor = textColor;
        d->update(true);
    }
}

bool QSlideText::event(QEvent* ev)
{
    if ((ev->type() == QEvent::FontChange)
            || (ev->type() == QEvent::ApplicationFontChange)) {
        Q_D(QSlideText);
        d->update(true);
    }
    return QWidget::event(ev);
}

QSize QSlideText::minimumSizeHint() const
{
    return QSize(10, 10);
}

////////////////////////////////////////////////////////////////////////////////
// Functions
//

////////////////////////////////// EOF /////////////////////////////////////////
