#include "shape.h"

#include<iostream>
Shape::Shape()
{

}

Shape::Shape(int side, double radius)
{
    this->side = side;
    this->radius = radius;
    this->xTranslated = 5.0;
    this->yTranslated = 5.0;
    this->xScale = 1.0;
    this->yScale = 1.0;
    this->angle = 0;
    this->isFocused = true;
    this->setXShear(0);
    this->setYShear(0);
    this->lineColor = Qt::black;
    this->isReflexX = false;
    this->isReflexY = false;
}

void Shape::draw()
{
    if(this->color.isValid()){
        glLineWidth(1);
        glColor3f(this->color.redF(),this->color.greenF(),this->color.blueF());
        glBegin(GL_POLYGON);
        for (int i = 0; i < this->side; ++i){
            glVertex2f(this->radius*cos(i*2*3.14159265/this->side), this->radius*sin(i*2*3.14159265/this->side));
        }
        glEnd();
     }

    if(this->lineColor.isValid()){
        glLineWidth(2);
        glColor3f(this->lineColor.redF(),this->lineColor.greenF(),this->lineColor.blueF());
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < this->side; ++i){
            glVertex2f(this->radius*cos(i*2*3.14159265/this->side), this->radius*sin(i*2*3.14159265/this->side));
        }
        glEnd();
    }

    if(this->isFocused){
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0xAAAA);
        glLineWidth(2);
        glPointSize(6);
        glColor3f(0,0,0);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < this->side; ++i)
            glVertex2f((this->radius+0.2)*cos(i*2*3.14159265/this->side),
                       (this->radius+0.2)*sin(i*2*3.14159265/this->side));
        glEnd();
        glDisable(GL_LINE_STIPPLE);
    }
    glLoadIdentity();
}


int Shape::getSide() const
{
    return side;
}

void Shape::setSide(int value)
{
    side = value;
}

double Shape::getRadius() const
{
    return radius;
}

void Shape::setRadius(double value)
{
    radius = value;
}

double Shape::getXTranslated() const
{
    return xTranslated;
}

void Shape::setXTranslated(double value)
{
    xTranslated = value;
}

double Shape::getYTranslated() const
{
    return yTranslated;
}

void Shape::setYTranslated(double value)
{
    yTranslated = value;
}

double Shape::getXScale() const
{
    return xScale;
}

void Shape::setXScale(double value)
{
    xScale = value;
}

double Shape::getYScale() const
{
    return yScale;
}

void Shape::setYScale(double value)
{
    yScale = value;
}

double Shape::getAngle() const
{
    return angle;
}

void Shape::setAngle(double value)
{
    angle = value;
}

boolean Shape::getIsFocused() const
{
    return isFocused;
}

void Shape::setIsFocused(const boolean &value)
{
    isFocused = value;
}

QColor Shape::getColor() const
{
    return color;
}

void Shape::setColor(const QColor &value)
{
    color = value;
}

QColor Shape::getLineColor() const
{
    return lineColor;
}

void Shape::setLineColor(const QColor &value)
{
    lineColor = value;
}

double Shape::getXShear() const
{
    return xShear;
}

void Shape::setXShear(double value)
{
    xShear = value;
}

double Shape::getYShear() const
{
    return yShear;
}

void Shape::setYShear(double value)
{
    yShear = value;
}

bool Shape::getIsReflexX() const
{
    return isReflexX;
}

void Shape::setIsReflexX(bool value)
{
    isReflexX = value;
}

bool Shape::getIsReflexY() const
{
    return isReflexY;
}

void Shape::setIsReflexY(bool value)
{
    isReflexY = value;
}

