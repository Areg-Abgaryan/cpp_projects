#ifndef COLORPICKER_HPP
#define COLORPICKER_HPP

#include <QWidget>
#include <QColor>
#include <QList>
#include <QGridLayout>
#include <QLabel>

class ColorPicker : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPicker(QWidget *parent = nullptr);

    QColor getColor() const;
    void setColor(const QColor&);

    void populateColors();
    void setupUi();

signals:
    void colorChanged(QColor newColor);

public slots:
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();
    void button4Clicked();
    void button5Clicked();
    void button6Clicked();
    void button7Clicked();
    void button8Clicked();
    void button9Clicked();


private:
    QColor current;
    QList<QColor> colorList;
    QGridLayout* gLayout;
    QLabel* label;

    void createPushButton1(const QSizePolicy&);
    void createPushButton2(const QSizePolicy&);
    void createPushButton3(const QSizePolicy&);
    void createPushButton4(const QSizePolicy&);
    void createPushButton5(const QSizePolicy&);
    void createPushButton6(const QSizePolicy&);
    void createPushButton7(const QSizePolicy&);
    void createPushButton8(const QSizePolicy&);
    void createPushButton9(const QSizePolicy&);

};

#endif // COLORPICKER_HPP
