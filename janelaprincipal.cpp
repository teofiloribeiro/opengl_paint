#include "janelaprincipal.h"
#include "ui_janelaprincipal.h"

JanelaPrincipal::JanelaPrincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JanelaPrincipal)
{
    ui->setupUi(this);
}

JanelaPrincipal::~JanelaPrincipal()
{
    delete ui;
}



void JanelaPrincipal::on_drawBtn_clicked()
{
    Shape *shape = new Shape (ui->spinBox->value(),ui->doubleSpinBox->value());
    ui->painelGL->shapesList.push_back(*shape);
    ui->painelGL->drawShape();
}
