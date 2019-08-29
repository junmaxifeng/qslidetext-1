#include "kglobalfun.h"
#include <QPixmap>
QPixmap KGlobalFun::rasterizedPixmap(const QPixmap& pixmap,int cellW,int cellH,QRgb backGrd)
{
    QImage image=pixmap.toImage();
    int red=0,green=0,blue=0;
    int redCnt=0,greenCnt=0,blueCnt=0;
    int redNew=0,greenNew=0,blueNew=0;
    int redBck=(backGrd&0x00ff0000)>>16;
    int greenBck=(backGrd&0x0000ff00)>>8;
    int blueBck=(backGrd&0x000000ff)>>0;

    for (int i=0;i+cellW<image.width();i+=cellW) {
        for (int j=0;j+cellH<image.height();j+=cellH)
        {
            red=0;green=0;blue=0;redCnt=0;greenCnt=0;blueCnt=0;
            for (int ii=i;ii<i+cellW;ii++) {
                for (int jj=j;jj<j+cellH;jj++) {
                    red+=(image.pixel(ii,jj)&0x00ff0000)>>16;
                    green+=(image.pixel(ii,jj)&0x0000ff00)>>8;
                    blue+=(image.pixel(ii,jj)&0x000000ff)>>0;
                    redCnt+=(image.pixel(ii,jj)&0x00ff0000)?1:0;
                    greenCnt+=(image.pixel(ii,jj)&0x0000ff00)?1:0;
                    blueCnt+=(image.pixel(ii,jj)&0x000000ff)?1:0;
                }
            }
            redNew=redCnt==0?0:red/(cellW*cellH);
            greenNew=greenCnt==0?0:green/(cellW*cellH);
            blueNew=blueCnt==0?0:blue/(cellW*cellH);
            for (int ii=i;ii<i+cellW;ii++)
                for (int jj=j;jj<j+cellH;jj++)
                    image.setPixel(ii,jj,qRgb( (((redNew)&0xff)+redBck)>255?255:(((redNew)&0xff)+redBck),\
                                               (((greenNew)&0xff)+greenBck)>255?255:(((greenNew)&0xff)+greenBck),\
                                               (((blueNew)&0xff)+blueBck)>255?255:(((blueNew)&0xff)+blueBck)));
        }
    }
    return QPixmap::fromImage(image);
}

