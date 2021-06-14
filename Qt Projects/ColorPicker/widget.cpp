#include "widget.hpp"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ColorPicker* colorpicker = new ColorPicker(this);
    QVBoxLayout* vbl = new QVBoxLayout(this);
    connect(colorpicker, &ColorPicker::colorChanged, this, &Widget::colorChanged);
    vbl->addWidget(colorpicker);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::colorChanged(QColor color)
{
    qDebug() << "Color changed to: " << color.name();
}
