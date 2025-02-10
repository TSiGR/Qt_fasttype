#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    area = new KeyboardArea(this);
    this->setMinimumSize(area->minimumSizeHint());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addWidget(area, 0, Qt::AlignCenter);
    setLayout(vbox);
    this->adjustSize();

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
