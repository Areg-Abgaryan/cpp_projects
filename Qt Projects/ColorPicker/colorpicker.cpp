#include "colorpicker.hpp"
#include <QVBoxLayout>
#include <QPushButton>

ColorPicker::ColorPicker(QWidget *parent) : QWidget(parent)
{
    gLayout = new QGridLayout();
    populateColors();
    setupUi();
}

QColor ColorPicker::getColor() const
{
    return current;
}

void ColorPicker::setColor(const QColor& value)
{
    current = value;
}

void ColorPicker::populateColors()
{
    colorList <<
                 Qt::red << Qt::darkGreen << Qt::blue <<
                 Qt::white << Qt::darkMagenta << Qt::gray <<
                 Qt::cyan << Qt::yellow << Qt::green;
}

void ColorPicker::button1Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(0).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[0]);
}
void ColorPicker::button2Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(1).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[1]);
}
void ColorPicker::button3Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(2).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[2]);
}
void ColorPicker::button4Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(3).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[3]);
}
void ColorPicker::button5Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(4).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[4]);
}
void ColorPicker::button6Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(5).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[5]);
}
void ColorPicker::button7Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(6).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[6]);
}
void ColorPicker::button8Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(7).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[7]);
}
void ColorPicker::button9Clicked()
{
    QString css = QString("background-color : %1").arg(colorList.at(8).name());
    label->setStyleSheet(css);
    emit colorChanged(colorList[8]);
}

void ColorPicker::createPushButton1(const QSizePolicy& policy)
{
        QPushButton* button1 = new QPushButton("one", this);
        button1->setSizePolicy(policy);
        QString css = QString("background-color : %1").arg(colorList.at(0).name());
        button1->setStyleSheet(css);
        connect(button1, &QPushButton::clicked, this, &ColorPicker::button1Clicked);
        gLayout->addWidget(button1, 0, 0);
}
void ColorPicker::createPushButton2(const QSizePolicy& policy)
{
    QPushButton* button2 = new QPushButton("two", this);
    button2->setSizePolicy(policy);
    QString css = QString("background-color : %1").arg(colorList.at(1).name());
    button2->setStyleSheet(css);
    connect(button2, &QPushButton::clicked, this, &ColorPicker::button2Clicked);
    gLayout->addWidget(button2, 0, 1);
}
void ColorPicker::createPushButton3(const QSizePolicy& policy)
{
       QPushButton* button3 = new QPushButton("three", this);
       button3->setSizePolicy(policy);
       QString css = QString("background-color : %1").arg(colorList.at(2).name());
       button3->setStyleSheet(css);
       connect(button3, &QPushButton::clicked, this, &ColorPicker::button3Clicked);
       gLayout->addWidget(button3, 0, 2);
}
void ColorPicker::createPushButton4(const QSizePolicy& policy)
{
    QPushButton* button4 = new QPushButton("four", this);
    button4->setSizePolicy(policy);
    QString css = QString("background-color : %1").arg(colorList.at(3).name());
    button4->setStyleSheet(css);
    connect(button4, &QPushButton::clicked, this, &ColorPicker::button4Clicked);
    gLayout->addWidget(button4, 1, 0);
}
void ColorPicker::createPushButton5(const QSizePolicy& policy)
{
    QPushButton* button5 = new QPushButton("five", this);
    button5->setSizePolicy(policy);
    QString css = QString("background-color : %1").arg(colorList.at(4).name());
    button5->setStyleSheet(css);
    connect(button5, &QPushButton::clicked, this, &ColorPicker::button5Clicked);
    gLayout->addWidget(button5, 1, 1);
}
void ColorPicker::createPushButton6(const QSizePolicy& policy)
{
    QPushButton* button6 = new QPushButton("six", this);
    button6->setSizePolicy(policy);
    QString css = QString("background-color : %1").arg(colorList.at(5).name());
    button6->setStyleSheet(css);
    connect(button6, &QPushButton::clicked, this, &ColorPicker::button6Clicked);
    gLayout->addWidget(button6, 1, 2);
}
void ColorPicker::createPushButton7(const QSizePolicy& policy)
{
    QPushButton* button7 = new QPushButton("seven", this);
    button7->setSizePolicy(policy);
    QString css = QString("background-color : %1").arg(colorList.at(6).name());
    button7->setStyleSheet(css);
    connect(button7, &QPushButton::clicked, this, &ColorPicker::button7Clicked);
    gLayout->addWidget(button7, 2, 0);
}
void ColorPicker::createPushButton8(const QSizePolicy& policy)
{
    QPushButton* button8 = new QPushButton("eight", this);
    button8->setSizePolicy(policy);
    QString css = QString("background-color : %1").arg(colorList.at(7).name());
    button8->setStyleSheet(css);
    connect(button8, &QPushButton::clicked, this, &ColorPicker::button8Clicked);
    gLayout->addWidget(button8, 2, 1);
}
void ColorPicker::createPushButton9(const QSizePolicy& policy)
{
    QPushButton* button9 = new QPushButton("nine", this);
    button9->setSizePolicy(policy);
    QString css = QString("background-color : %1").arg(colorList.at(8).name());
    button9->setStyleSheet(css);
    connect(button9, &QPushButton::clicked, this, &ColorPicker::button9Clicked);
    gLayout->addWidget(button9, 2, 2);
}
void ColorPicker::setupUi()
{
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QSizePolicy policy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    createPushButton1(policy);
    createPushButton2(policy);
    createPushButton3(policy);
    createPushButton4(policy);
    createPushButton5(policy);
    createPushButton6(policy);
    createPushButton7(policy);
    createPushButton8(policy);
    createPushButton9(policy);

    label = new QLabel("Chosen color");
    QString css = QString("background-color : #eeeab6");
    label->setFixedHeight(50);
    label->setStyleSheet(css);

    vLayout->addWidget(label);
    vLayout->addLayout(gLayout);
}
