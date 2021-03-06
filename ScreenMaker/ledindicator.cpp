#include "ledindicator.h"
#include <QPainter>

LedIndicator::LedIndicator(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(28, 28);
    lit = false;
    ledOnColor=Qt::green;
    ledOffColor=Qt::red;
    ledOnPattern = Qt::SolidPattern;
    ledOffPattern = Qt::SolidPattern;
    ledSize=20;
}

void LedIndicator::paintEvent(QPaintEvent *) {
  QPainter p(this);
  lit ?  p.setBrush(QBrush(ledOnColor, ledOnPattern)) : p.setBrush(QBrush(ledOffColor, ledOffPattern));
  QPoint center(ledSize/2-1/2,ledSize/2-1/2);
  p.drawEllipse(center,ledSize/2,ledSize/2);

}

void LedIndicator::switchLedIndicator() {
  lit = ! lit;
  repaint();
}
void LedIndicator::setState(bool state)
{
    lit = state;
    repaint();
}
void LedIndicator::toggle()
{
    lit = ! lit;
    repaint();
}

void LedIndicator::setOnColor(QColor onColor)
{
    ledOnColor=onColor;
    repaint();
}
void LedIndicator::setOffColor(QColor offColor)
{
    ledOffColor=offColor;
    repaint();
}
void LedIndicator::setOnPattern(Qt::BrushStyle onPattern)
{
    ledOnPattern=onPattern;
    repaint();
}
void LedIndicator::setColor_noShow(QColor Color)
{
    ledOnColor=Color;
    repaint();
}
void LedIndicator::setOffPattern(Qt::BrushStyle offPattern)
{
    ledOffPattern=offPattern;
    repaint();
}
void LedIndicator::setLedSize(int size)
{
    ledSize=size;
    setFixedSize(size, size);
    repaint();
}
