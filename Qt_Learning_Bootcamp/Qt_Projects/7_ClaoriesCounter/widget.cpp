#include "widget.h"
#include "./ui_widget.h"
#include <cmath> // make sure this is included
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // initialization of values

    m_person.set_weight(ui->WeightSpinBox->value());
    m_time = ui->TimeSpinBox->value();
    m_speed = ui->SpeedSpinBox->value();

    //connect spinbox
    connect(ui->WeightSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Widget::weight_changed);
    connect(ui->TimeSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Widget::time_changed);
    connect(ui->SpeedSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &Widget::speed_changed);


    // update the calory count
    connect(this,&Widget::calory_count_changed,[=](){
        ui->CaloryCountLabel->setText(QString::number(m_calory_count));
    });

    calculate_calories();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculate_calories()
{
    double speed = m_person.get_speed();
    m_calory_count = ((0.0215 * std::pow(speed, 3)) -
                      (0.1765 * std::pow(speed, 2)) +
                      (0.8710 * speed) + 1.4577) *
                     m_person.get_weight() * m_person.get_time();

    emit calory_count_changed();

}

void Widget::weight_changed(double weight)
{
    m_person.set_weight(weight);
    calculate_calories();
}

void Widget::time_changed(double time)
{
    m_person.set_time(time);
    calculate_calories();
}

void Widget::speed_changed(double speed)
{
    m_person.set_speed(speed);
    calculate_calories();
}
