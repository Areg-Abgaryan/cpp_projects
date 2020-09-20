#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPen>

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line, Circle, Ellipse, Fancy, Starfish };

    void setBackgroundColor(QColor color) { mBackgroundColor = color; }
    QColor backgroundColor () const  { return  mBackgroundColor; }

    void setShapeColor(QColor color) { mPen.setColor(color); }
    QColor shapeColor() const { return mPen.color(); }


    ShapeType shape() const { return mShape; }

    void setShape(ShapeType shape)
    {
        mShape = shape;
        onShapeChanged();
    }

    void setScale(float scale)
    {
        mScale = scale;
        repaint();
    }

    float scale() const { return mScale; }

    void setIntervalLength(float length)
    {
        mIntervalLength = length;
        repaint();
    }

    float intervalLength() const { return mIntervalLength; }

    void setStepCount (int count)
    {
        mStepCount = count;
        repaint();
    }

    int stepCount() const { return mStepCount; }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QColor mBackgroundColor{};
    ShapeType mShape{};
    QPen mPen{};

    float mScale{};
    float mIntervalLength{};
    int mStepCount{};

    void onShapeChanged();
    QPointF compute(float t);

    QPointF computeAstroid(float t);
    QPointF computeCycloid(float t);
    QPointF computeHuygensCycloid(float t);
    QPointF computeHypoCycloid(float t);
    QPointF computeLine(float t);
    QPointF computeCircle(float t);
    QPointF computeEllipse(float t);
    QPointF computeStarfish(float t);

signals:

};

#endif // RENDERAREA_H
