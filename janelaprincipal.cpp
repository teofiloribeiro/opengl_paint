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
    ui->painelGL->setShapeFocus(ui->painelGL->shapesList.size()-1);
    if(ui->painelGL->shapesList.size() > 1){
        ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()-1).setIsFocused(false);
    }
    ui->painelGL->updateGL();
}


void JanelaPrincipal::on_upBtn_clicked()
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->translated(UP);
        ui->painelGL->updateGL();
    }
}



void JanelaPrincipal::on_leftBtn_clicked()
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->translated(LEFT);
        ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_rightBtn_clicked()
{
    if(ui->painelGL->shapesList.size() > 0){
       ui->painelGL->translated(RIGHT);
       ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_downBtn_clicked()
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->translated(DOWN);
        ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_xScaleSpinBox_valueChanged(double arg1)
{
    if(ui->painelGL->shapesList.size() > 0){
        if(ui->proportionalScaleCb->checkState()){
        ui->yScaleSpinBox->setValue(ui->xScaleSpinBox->value());
        }
        ui->painelGL->scale(ui->xScaleSpinBox->value(), ui->yScaleSpinBox->value());
        ui->painelGL->updateGL();
    }
}


void JanelaPrincipal::on_yScaleSpinBox_valueChanged(double arg1)
{
    if(ui->painelGL->shapesList.size() > 0){
        if(ui->proportionalScaleCb->checkState()){
        ui->xScaleSpinBox->setValue(ui->yScaleSpinBox->value());
        }
        ui->painelGL->scale(ui->xScaleSpinBox->value(), ui->yScaleSpinBox->value());
        ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_rotationDial_sliderMoved(int position)
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->rotate(position);
        ui->painelGL->updateGL();
    }
}


void JanelaPrincipal::on_rotationDial_sliderPressed()
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->rotate(ui->rotationDial->value());
        ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_focusPreviousBtn_clicked()
{
    if(ui->painelGL->getShapeFocus() == 0 && ui->painelGL->shapesList.size() > 0){
       ui->painelGL->setShapeFocus(ui->painelGL->shapesList.size()-1);
       ui->painelGL->shapesList.at(ui->painelGL->shapesList.size()-1).setIsFocused(true);
       if(ui->painelGL->shapesList.size() > 1)
          ui->painelGL->shapesList.at(0).setIsFocused(false);
     }
    else if(ui->painelGL->shapesList.size() > 1){
       ui->painelGL->setShapeFocus(ui->painelGL->getShapeFocus()-1);
       ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()).setIsFocused(true);
       ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()+1).setIsFocused(false);
    }
    ui->painelGL->updateGL();

}

void JanelaPrincipal::on_focusNextBtn_clicked()
{
    if(ui->painelGL->getShapeFocus() >= ui->painelGL->shapesList.size()-1){
       ui->painelGL->setShapeFocus(0);
       ui->painelGL->shapesList.at(0).setIsFocused(true);
       if(ui->painelGL->shapesList.size() > 1)
          ui->painelGL->shapesList.at(ui->painelGL->shapesList.size()-1).setIsFocused(false);
     }
    else if(ui->painelGL->shapesList.size() > 1){
       ui->painelGL->setShapeFocus(ui->painelGL->getShapeFocus()+1);
       ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()).setIsFocused(true);
       ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()-1).setIsFocused(false);
    }
     ui->painelGL->updateGL();

}


void JanelaPrincipal::on_eraseBtn_clicked()
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->shapesList.erase(ui->painelGL->shapesList.begin()+ui->painelGL->getShapeFocus());
        on_focusNextBtn_clicked();
        ui->painelGL->updateGL();
    }
}
