#ifndef KEYBOARDAREA_H
#define KEYBOARDAREA_H

#include <Qwidget>
#include <QEvent>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QPainter>
#include <QVector>

class KeyboardArea : public QWidget
{
public:
    explicit KeyboardArea(QWidget *parent = nullptr);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    QRect& findRect(QString&);

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:

    QRect rectangle, forRepaint, prevRepaint;
    QVector<QVector<QRect>> keys;
    QVector<QVector<QString>> pattern;
    QString keytext, prevkeytext;
    bool drawoneRect;
};

#endif // KEYBOARDAREA_H

