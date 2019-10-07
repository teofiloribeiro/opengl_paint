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

    Shape *shape = new Shape (3,1);
    shape->setColor(this->color);
    shape->setLineColor(this->lineColor);
    ui->painelGL->shapesList.push_back(*shape);
    ui->painelGL->setShapeFocus(ui->painelGL->shapesList.size()-1);
    if(ui->painelGL->shapesList.size() > 1){
        ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()-1).setIsFocused(false);
    }
    ui->painelGL->updateGL();
    ui->spinBox->setValue(3);
    if(ui->painelGL->shapesList.size() > 0)
        ui->objectNumberLabel->setText("Quantidade de objetos: " + QString::number(ui->painelGL->shapesList.size()));
}

void JanelaPrincipal::on_drawCircleBtn_clicked()
{
    Shape *shape = new Shape (60,1);
    shape->setColor(this->color);
    shape->setLineColor(this->lineColor);
    ui->painelGL->shapesList.push_back(*shape);
    ui->painelGL->setShapeFocus(ui->painelGL->shapesList.size()-1);
    if(ui->painelGL->shapesList.size() > 1){
        ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()-1).setIsFocused(false);
    }
    ui->painelGL->updateGL();
    ui->spinBox->setValue(60);
    if(ui->painelGL->shapesList.size() > 0)
        ui->objectNumberLabel->setText("Quantidade de objetos: " + QString::number(ui->painelGL->shapesList.size()));

}

void JanelaPrincipal::on_drawSquareBtn_clicked()
{
    Shape *shape = new Shape (4,1);
    shape->setColor(this->color);
    shape->setLineColor(this->lineColor);
    ui->painelGL->shapesList.push_back(*shape);
    ui->painelGL->setShapeFocus(ui->painelGL->shapesList.size()-1);
    if(ui->painelGL->shapesList.size() > 1){
        ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()-1).setIsFocused(false);
    }
    ui->painelGL->updateGL();
    ui->spinBox->setValue(4);
    if(ui->painelGL->shapesList.size() > 0)
        ui->objectNumberLabel->setText("Quantidade de objetos: " + QString::number(ui->painelGL->shapesList.size()));
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
        ui->objectNumberLabel->setText("Quantidade de objetos: " + QString::number(ui->painelGL->shapesList.size()));
    }
}

void JanelaPrincipal::on_colorBtn_clicked()
{
    this->color = QColorDialog::getColor(Qt::white,this);
    if(ui->painelGL->shapesList.size() > 0){
       glColor4f(color.redF(), color.greenF(), color.blueF(), color.alphaF());
       ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()).setColor(color);
    }
    if(color.isValid())
        ui->colorBtn->setStyleSheet("background-color: " + color.name());

}

void JanelaPrincipal::on_lineColorBtn_clicked()
{
    this->lineColor = QColorDialog::getColor(Qt::white,this);
    if(ui->painelGL->shapesList.size() > 0){
       glColor4f(lineColor.redF(), lineColor.greenF(), lineColor.blueF(), lineColor.alphaF());
       ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()).setLineColor(lineColor);
    }
    if(color.isValid())
        ui->lineColorBtn->setStyleSheet("background-color: " + lineColor.name());
}

QColor JanelaPrincipal::getLineColor() const
{
    return lineColor;
}

void JanelaPrincipal::setLineColor(const QColor &value)
{
    lineColor = value;
}


QColor JanelaPrincipal::getColor() const
{
    return color;
}

void JanelaPrincipal::setColor(const QColor &value)
{
    color = value;
}


void JanelaPrincipal::on_openAction_triggered()
{
    QString filter = "Arquivos paintGl (*.ptgl)";
    QString openFile = QFileDialog::getOpenFileName(this, "Abrir Arquivos", QDir::homePath(), filter);
    QFile file(openFile);
    QTextStream in(&file);
    QColor loadColor;
    QColor loadLineColor;
    QString data;

    if(!file.open(QFile::ReadOnly|QFile::Text)){
       QMessageBox::warning(this,"Erro", "Erro Open File");
    }


    while((data = in.readLine()) != NULL){
        if(data != "shape"){
           Shape *shape = new Shape ();
           shape->setSide(data.toInt());
           if((data = in.readLine()) != NULL)
           shape->setRadius(data.toDouble());
           if((data = in.readLine()) != NULL)
           shape->setXTranslated(data.toDouble());
           if((data = in.readLine()) != NULL)
           shape->setYTranslated(data.toDouble());
           if((data = in.readLine()) != NULL)
           shape->setXScale(data.toDouble());
           if((data = in.readLine()) != NULL)
           shape->setYScale(data.toDouble());
           if((data = in.readLine()) != NULL)
           shape->setAngle(data.toDouble());
           if((data = in.readLine()) != NULL)
           shape->setIsFocused(false);
           if((data = in.readLine()) != NULL)
           loadColor.setRedF(data.toDouble());
           if((data = in.readLine()) != NULL)
           loadColor.setGreenF(data.toDouble());
           if((data = in.readLine()) != NULL)
           loadColor.setBlueF(data.toDouble());
           if((data = in.readLine()) != NULL)
           loadColor.setAlphaF(data.toDouble());
           if((data = in.readLine()) != NULL)
           loadLineColor.setRedF(data.toDouble());
           if((data = in.readLine()) != NULL)
           loadLineColor.setGreenF(data.toDouble());
           if((data = in.readLine()) != NULL)
           loadLineColor.setBlueF(data.toDouble());
           if((data = in.readLine()) != NULL)
           loadLineColor.setAlphaF(data.toDouble());
           if(loadColor.isValid())
           shape->setColor(loadColor);
           if(loadLineColor.isValid())
           shape->setLineColor(loadLineColor);
           if((data = in.readLine()) != NULL)
           shape->setXShear(data.toDouble());
           if((data = in.readLine()) != NULL)
           shape->setYShear(data.toDouble());
           if((data = in.readLine()) != NULL)
           shape->setIsReflexX(data.toInt());
           if((data = in.readLine()) != NULL)
           shape->setIsReflexX(data.toInt());

           ui->painelGL->shapesList.push_back(*shape);
        }

    }
    ui->painelGL->updateGL();
    if(ui->painelGL->shapesList.size() > 0)
        ui->objectNumberLabel->setText("Quantidade de objetos: " + QString::number(ui->painelGL->shapesList.size()));
}


void JanelaPrincipal::on_saveAction_triggered()
{

    QString filter = "Arquivos paintGL (*.ptgl)";
    QString path = QFileDialog::getSaveFileName(this, "Salvar Arquivos", QDir::homePath(), filter);
    QFile file (path);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"Erro", "Erro Save File");
    }
    QTextStream out(&file);

    if(ui->painelGL->shapesList.size() > 0){
        for(int i = 0; i <ui->painelGL->shapesList.size(); i++){
            out << "shape" <<endl;
            out << ui->painelGL->shapesList.at(i).getSide() <<endl;
            out << ui->painelGL->shapesList.at(i).getRadius() <<endl;
            out << ui->painelGL->shapesList.at(i).getXTranslated() <<endl;
            out << ui->painelGL->shapesList.at(i).getYTranslated() <<endl;
            out << ui->painelGL->shapesList.at(i).getXScale() <<endl;
            out << ui->painelGL->shapesList.at(i).getYScale() <<endl;
            out << ui->painelGL->shapesList.at(i).getAngle() <<endl;
            out << ui->painelGL->shapesList.at(i).getIsFocused() <<endl;
            out << ui->painelGL->shapesList.at(i).getColor().redF() <<endl;
            out << ui->painelGL->shapesList.at(i).getColor().greenF() <<endl;
            out << ui->painelGL->shapesList.at(i).getColor().blueF() <<endl;
            out << ui->painelGL->shapesList.at(i).getColor().alphaF() <<endl;
            out << ui->painelGL->shapesList.at(i).getLineColor().redF() <<endl;
            out << ui->painelGL->shapesList.at(i).getLineColor().greenF() <<endl;
            out << ui->painelGL->shapesList.at(i).getLineColor().blueF() <<endl;
            out << ui->painelGL->shapesList.at(i).getLineColor().alphaF() <<endl;
            out << ui->painelGL->shapesList.at(i).getXShear() <<endl;
            out << ui->painelGL->shapesList.at(i).getYShear() <<endl;
            out << ui->painelGL->shapesList.at(i).getIsReflexX() <<endl;
            out << ui->painelGL->shapesList.at(i).getIsReflexY() <<endl;
        }
        file.flush();
        file.close();
    }

}

void JanelaPrincipal::on_spinBox_valueChanged(int arg1)
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()).setSide(ui->spinBox->value());
       ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_actionNovo_triggered()
{
   ui->painelGL->shapesList.clear();
   ui->painelGL->updateGL();
   ui->objectNumberLabel->clear();
}



void JanelaPrincipal::on_meshCheckBox_stateChanged(int arg1)
{

     ui->painelGL->setIsDrawMesh(arg1);
     ui->painelGL->updateGL();
}

void JanelaPrincipal::on_zoomInBtn_clicked()
{
    ui->painelGL->setZoom(ui->painelGL->getZoom()+1);
    ui->painelGL->zoomScale(ui->painelGL->getZoom());
}

void JanelaPrincipal::on_zoomOutBtn_clicked()
{
    ui->painelGL->setZoom(ui->painelGL->getZoom()-1);
    ui->painelGL->zoomScale(ui->painelGL->getZoom());
}

void JanelaPrincipal::on_shXDoubleSpinBox_valueChanged(double arg1)
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()).setXShear(ui->shXDoubleSpinBox->value());
       ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_shYDoubleSpinBox_valueChanged(double arg1)
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->shapesList.at(ui->painelGL->getShapeFocus()).setYShear(ui->shYDoubleSpinBox->value());
        ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_reflexXBtn_clicked()
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->reflex(0);
        ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_reflexYBtn_clicked()
{
    if(ui->painelGL->shapesList.size() > 0){
        ui->painelGL->reflex(1);
        ui->painelGL->updateGL();
    }
}

void JanelaPrincipal::on_meshSizeSpin_valueChanged(double arg1)
{
   ui->painelGL->setMeshSize(ui->meshSizeSpin->value());
   ui->painelGL->updateGL();
}
