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

void JanelaPrincipal::on_zoomInBtn_clicked()
{
    ui->painelGL->setZoom(ui->painelGL->getZoom()+1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->scale();
    ui->painelGL->updateGL();
}

void JanelaPrincipal::on_zoomOutBtn_clicked()
{
    if(ui->painelGL->getZoom() > 1){
         ui->painelGL->setZoom(ui->painelGL->getZoom()-1);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         ui->painelGL->scale();
         ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_upBtn_clicked()
{
    ui->painelGL->translated(UP);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}



void JanelaPrincipal::on_leftBtn_clicked()
{
    ui->painelGL->translated(LEFT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}

void JanelaPrincipal::on_rightBtn_clicked()
{
    ui->painelGL->translated(RIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}

void JanelaPrincipal::on_downBtn_clicked()
{
    ui->painelGL->translated(DOWN);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ui->painelGL->updateGL();
}
