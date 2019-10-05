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
   // ui->painelGL->drawShape();
    ui->painelGL->updateGL();
}


void JanelaPrincipal::on_upBtn_clicked()
{
    ui->painelGL->translated(UP);
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}



void JanelaPrincipal::on_leftBtn_clicked()
{
    ui->painelGL->translated(LEFT);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}

void JanelaPrincipal::on_rightBtn_clicked()
{
    ui->painelGL->translated(RIGHT);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}

void JanelaPrincipal::on_downBtn_clicked()
{
    ui->painelGL->translated(DOWN);
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}

void JanelaPrincipal::on_xScaleSpinBox_valueChanged(double arg1)
{
    if(ui->proportionalScaleCb->checkState()){
        ui->yScaleSpinBox->setValue(ui->xScaleSpinBox->value());
    }
    ui->painelGL->scale(ui->xScaleSpinBox->value(), ui->yScaleSpinBox->value());
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}


void JanelaPrincipal::on_yScaleSpinBox_valueChanged(double arg1)
{
    if(ui->proportionalScaleCb->checkState()){
        ui->xScaleSpinBox->setValue(ui->yScaleSpinBox->value());
    }
    ui->painelGL->scale(ui->xScaleSpinBox->value(), ui->yScaleSpinBox->value());
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}

void JanelaPrincipal::on_rotationDial_sliderMoved(int position)
{
    ui->painelGL->rotate(position);
    ui->painelGL->updateGL();
}


void JanelaPrincipal::on_rotationDial_sliderPressed()
{
    ui->painelGL->rotate(ui->rotationDial->value());
    ui->painelGL->updateGL();
}
