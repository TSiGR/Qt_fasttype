#ifndef KEYBOARDAREA_H
#define KEYBOARDAREA_H

#include <Qwidget>
#include <QEvent>
#include <QResizeEvent>
#include <QPainter>
#include <QVector>

class KeyboardArea : public QWidget
{
public:
    explicit KeyboardArea(QWidget *parent);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QRect rectangle;
    QVector<QVector<QRect>> keys;
};

#endif // KEYBOARDAREA_H

