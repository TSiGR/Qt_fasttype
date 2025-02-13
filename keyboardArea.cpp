#include "keyboardArea.h"


KeyboardArea::KeyboardArea(QWidget *parent) : QWidget(parent)
{
    rectangle = QRect(50, 50, 600, 200);
    pattern = QVector<QVector<QString>>({{ "`", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "="},
                                         { "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "\\"},
                                         { "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "", ""},
                                         { "Shift", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "Shift", ""},
                                         {" ", "", "", "", "", "", "", "", "", "", "", "", ""}});
    keys = QVector<QVector<QRect>>(5, QVector<QRect>(13));
    drawoneRect = false;
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    setFocusPolicy(Qt::StrongFocus);
    setMinimumSize(500, 100);
    adjustSize();
}

void KeyboardArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawRect(rectangle);
    painter.setBrush(Qt::white);
    painter.setRenderHint(QPainter::Antialiasing);

    const int key_width = 30;
    const int key_height = 30;

    for (int i = 0; i < 5; i++)
    {
        int offset_x;
        if (i == 1 || i == 2)
            offset_x = rectangle.x() + i * 15 + 50;
        else if (i == 4)
            offset_x = rectangle.x() + 150;
        else
            offset_x = rectangle.x() + 10;
        for (int j = 0; j < 13; j++)
        {
            if (pattern[i][j] == "")
            { break; }
            else if (pattern[i][j] == "Shift")
            {
                keys[i][j] = QRect(offset_x + j * (key_width + 10),
                                   rectangle.y() + 10 + i * (key_height + 7),
                                   key_width + 50, key_height);
                offset_x = rectangle.x() + key_width + 30;
            }
            else if (pattern[i][j] == " ")
            {
                keys[i][j] = QRect(offset_x + j * (key_width + 10),
                                   rectangle.y() + 10 + i * (key_height + 7),
                                   key_width + 250, key_height);
            }
            else
            {
                keys[i][j] = QRect(offset_x + j * (key_width + 10),
                                   rectangle.y() + 10 + i * (key_height + 7),
                                   key_width, key_height);
            }
            painter.drawRect(keys[i][j]);
            painter.drawText(keys[i][j].x(), keys[i][j].y(), keys[i][j].width(), keys[i][j].height(),
                             Qt::AlignCenter, pattern[i][j]);
        }
    }
    qDebug() << "Called template\n";

    QRect rectpaint = findRect(keytext);
    painter.setBrush(Qt::red);
    painter.drawRect(rectpaint);
    painter.drawText(rectpaint.x(), rectpaint.y(), rectpaint.width(), rectpaint.height(),
                     Qt::AlignCenter, keytext);
}

void KeyboardArea::resizeEvent(QResizeEvent *event)
{
    QSize newsize = event->size();

    int newX = (newsize.width() - rectangle.width()) / 2;
    int newY = (newsize.height() - rectangle.height()) / 2;
    rectangle.moveTo(newX, newY);
    QWidget::resizeEvent(event);
    update();
}

void KeyboardArea::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Called pressevent\n";
    keytext = event->text();
    update();
}

QRect& KeyboardArea::findRect(QString& keytext)
{
    int lettercoordx = 0;
    int lettercoordy = 0;
    for (auto &items : pattern)
    {
        for (auto &letter : items)
        {
            if (keytext == letter)
            {
                forRepaint = keys[lettercoordx][lettercoordy];
                break;
            }
            ++lettercoordy;
        }
        lettercoordy = 0;
        ++lettercoordx;
    }
    qDebug() << "Called keybrush\n";
    return forRepaint;
}

QSize KeyboardArea::sizeHint() const
{
    return QSize(600, 400);
}

QSize KeyboardArea::minimumSizeHint() const
{
    return QSize(rectangle.width() + 50, rectangle.height() + 50);
}
