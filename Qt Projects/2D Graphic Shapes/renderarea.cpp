#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <cmath>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(QColor (0, 0, 255)),
    mShape(Astroid),
    mPen(Qt::white)
{
    mPen.setWidth(2);
    onShapeChanged();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(400, 400);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 400);
}

QPointF RenderArea::compute(float t)
{
    switch (mShape)
    {
        case Astroid:
            return computeAstroid(t);
            break;
        case Cycloid:
            return computeCycloid(t);
            break;
        case HuygensCycloid:
            return computeHuygensCycloid(t);
            break;
        case HypoCycloid:
            return computeHypoCycloid(t);
            break;
        case Line:
            return computeLine(t);
            break;
        case Circle:
            return computeCircle(t);
            break;
        case Ellipse:
            return computeEllipse(t);
            break;
        case Starfish:
            return computeStarfish(t);
            break;
        default:
            break;
    }
    return QPointF(0, 0);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setBrush(mBackgroundColor);
    painter.setPen(mPen);

    painter.drawRect(this->rect());

    QPoint center = this->rect().center();

    QPointF prevPoint = compute(0);
    QPoint prevPixel{};
    prevPixel.setX(prevPoint.x() * mScale + center.x());
    prevPixel.setY(prevPoint.y() * mScale + center.y());

    float step = mIntervalLength / mStepCount;
    for(float t = 0; t < mIntervalLength; t += step)
    {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        painter.drawLine(pixel, prevPixel);

        prevPixel = pixel;
    }
    QPointF point = compute(mIntervalLength);

    QPoint pixel;
    pixel.setX(point.x() * mScale + center.x());
    pixel.setY(point.y() * mScale + center.y());

    painter.drawLine(pixel, prevPixel);
}

void RenderArea::onShapeChanged()
{
    switch (mShape)
    {
        case Astroid:
            mScale = 90;
            mIntervalLength = 2 * M_PI;
            mBackgroundColor = Qt::red;
            mStepCount = 256;
            break;
        case Cycloid:
            mScale = 10;
            mIntervalLength = 4 * M_PI;
            mStepCount = 128;
            mBackgroundColor = Qt::green;
            break;
        case HuygensCycloid:
            mScale = 12;
            mIntervalLength = 4 * M_PI;
            mStepCount = 256;
            mBackgroundColor = Qt::blue;
            break;
        case HypoCycloid:
            mScale = 40;
            mIntervalLength = 2 * M_PI;
            mStepCount = 256;
            mBackgroundColor = Qt::yellow;
            break;
        case Line:
            mIntervalLength = 2;
            mScale = 100;
            mStepCount = 128;
            mBackgroundColor = Qt::gray;
            break;
        case Circle:
            mScale = 90;
            mIntervalLength = 2 * M_PI;
            mStepCount = 128;
            mBackgroundColor = Qt::magenta;
            break;
        case Ellipse:
            mScale = 75;
            mIntervalLength = 2 * M_PI;
            mStepCount = 128;
            mBackgroundColor = Qt::cyan;
            break;
        case Starfish:
            mScale = 25;
            mIntervalLength = 6 * M_PI;
            mStepCount = 256;
            mBackgroundColor = Qt::darkYellow;
            break;
        default:
            break;
    }
}

QPointF RenderArea::computeAstroid(float t)
{
    float sin_t = sin(t);
    float cos_t = cos(t);
    float x = 2 * pow(sin_t, 3);
    float y = 2 * pow(cos_t, 3);

    return QPointF(x, y);
}
QPointF RenderArea::computeCycloid(float t)
{
    return QPointF(
                1.5 * (1 - cos(t)),
                1.5 * (t - sin(t))
                );
}
QPointF RenderArea::computeHuygensCycloid(float t)
{
    return QPointF (
                4 * (3 * cos(t) - cos(3 * t)),
                4 * (3 * sin(t) - sin(3 * t))
                );
}
QPointF RenderArea::computeHypoCycloid(float t)
{
    return QPointF(
                1.5 * (2 * cos(t) + cos(2 * t)),
                1.5 * (2 * sin(t) - sin(2 * t))
                );
}
QPointF RenderArea::computeLine(float t)
{
    return QPointF(1 - t, 1 - t);
}
QPointF RenderArea::computeCircle(float t)
{
    return QPointF (
                cos(t),
                sin(t)
                );
}
QPointF RenderArea::computeEllipse(float t)
{
    float a = 2;
    float b = 1;
    return QPointF (
                a * cos(t),
                b * sin(t)
                );
}
QPointF RenderArea::computeStarfish(float t)
{
    float R = 5;
    float r = 3;
    float d = 5;
    float x = (R - r) * cos(t) + d * cos( t * ( R -r ) / r );
    float y = (R - r) * sin(t) - d * sin( t * ( R -r ) / r );

    return QPointF(x, y);
}
