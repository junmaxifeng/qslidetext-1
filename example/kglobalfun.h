#ifndef KGLOBALFUN_H
#define KGLOBALFUN_H

#include <QObject>
#include <QColor>
#include <QRgb>

class KGlobalFun : public QObject
{
    Q_OBJECT
public:
    static QPixmap rasterizedPixmap(const QPixmap& pixmap,int cellW,int cellH,QRgb backGrd=qRgb(70,70,70));

};

#endif // KGLOBALFUN_H
