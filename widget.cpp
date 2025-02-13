#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    area = new KeyboardArea();
    area->setFocus();

    QVBoxLayout *vbox = new QVBoxLayout(this);
    this->setMinimumSize(area->minimumSizeHint());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    this->adjustSize();

    vbox->addWidget(area, 0, Qt::AlignCenter);
    setLayout(vbox);

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
