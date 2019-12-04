#include "shape.h"
#include<iostream>
#include <GL/glu.h>

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

void Shape::draw(boolean mode3D)
{

    if(mode3D){
    if(this->side == 60){

    double r = 1; int lats = 500; int longs=500;

    int i, j;
        for(i = 0; i <= lats; i++) {
            double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
            double z0  = sin(lat0);
            double zr0 =  cos(lat0);

            double lat1 = M_PI * (-0.5 + (double) i / lats);
            double z1 = sin(lat1);
            double zr1 = cos(lat1);

            glBegin(GL_QUAD_STRIP);
            for(j = 0; j <= longs; j++) {
                double lng = 2 * M_PI * (double) (j - 1) / longs;
                double x = cos(lng);
                double y = sin(lng);
               glColor3f(this->color.redF(),this->color.greenF(),this->color.blueF());
               glNormal3f(x * zr0, y * zr0, z0);
                glVertex3f(r * x * zr0, r * y * zr0, r * z0);
                glNormal3f(x * zr1, y * zr1, z1);
                glVertex3f(r * x * zr1, r * y * zr1, r * z1);
            }
            glEnd();
        }
    }
    else if(this->side == 3){


        glBegin(GL_TRIANGLES);
             glColor3f(1.0f, 0.0f, 0.0f);
             glVertex3f( 0.0f, 1.0f, 0.0f);
             glColor3f(1.0f, 0.0f, 0.0f);
             glVertex3f(-1.0f, -1.0f, 1.0f);
             glColor3f(1.0f, 0.0f, 0.0f);
             glVertex3f(1.0f, -1.0f, 1.0f);

             glColor3f(1.0f, 0.0f, 0.0f);
             glVertex3f(0.0f, 1.0f, 0.0f);
             glColor3f(0.0f, 0.0f, 1.0f);
             glVertex3f(1.0f, -1.0f, 1.0f);
             glColor3f(1.0f, 0.5f, 0.0f);
             glVertex3f(1.0f, -1.0f, -1.0f);

             glColor3f(1.0f, 0.0f, 0.0f);
             glVertex3f(0.0f, 1.0f, 0.0f);
             glColor3f(0.0f, 1.0f, 0.0f);
             glVertex3f(1.0f, -1.0f, -1.0f);
             glColor3f(1.0f, 0.5f, 0.0f);
             glVertex3f(-1.0f, -1.0f, -1.0f);

             glColor3f(1.0f,0.0f,0.0f);
             glVertex3f( 0.0f, 1.0f, 0.0f);
             glColor3f(0.0f,0.0f,1.0f);
             glVertex3f(-1.0f,-1.0f,-1.0f);
             glColor3f(0.0f,1.0f,0.0f);
             glVertex3f(-1.0f,-1.0f, 1.0f);
          glEnd();
    }

     else if(this->side == 4){
        glBegin(GL_QUADS);
             glColor3f(0.0f, 1.0f, 0.0f);
             glVertex3f( 1.0f, 1.0f, -1.0f);
             glVertex3f(-1.0f, 1.0f, -1.0f);
             glVertex3f(-1.0f, 1.0f,  1.0f);
             glVertex3f( 1.0f, 1.0f,  1.0f);

             glColor3f(1.0f, 0.5f, 0.0f);
             glVertex3f( 1.0f, -1.0f,  1.0f);
             glVertex3f(-1.0f, -1.0f,  1.0f);
             glVertex3f(-1.0f, -1.0f, -1.0f);
             glVertex3f( 1.0f, -1.0f, -1.0f);

             glColor3f(1.0f, 0.0f, 0.0f);
             glVertex3f( 1.0f,  1.0f, 1.0f);
             glVertex3f(-1.0f,  1.0f, 1.0f);
             glVertex3f(-1.0f, -1.0f, 1.0f);
             glVertex3f( 1.0f, -1.0f, 1.0f);

             glColor3f(0.0f, 1.0f, 0.0f);
             glVertex3f( 1.0f, -1.0f, -1.0f);
             glVertex3f(-1.0f, -1.0f, -1.0f);
             glVertex3f(-1.0f,  1.0f, -1.0f);
             glVertex3f( 1.0f,  1.0f, -1.0f);

             glColor3f(0.0f, 0.0f, 1.0f);
             glVertex3f(-1.0f,  1.0f,  1.0f);
             glVertex3f(-1.0f,  1.0f, -1.0f);
             glVertex3f(-1.0f, -1.0f, -1.0f);
             glVertex3f(-1.0f, -1.0f,  1.0f);

             glColor3f(1.0f, 0.0f, 1.0f);
             glVertex3f(1.0f,  1.0f, -1.0f);
             glVertex3f(1.0f,  1.0f,  1.0f);
             glVertex3f(1.0f, -1.0f,  1.0f);
             glVertex3f(1.0f, -1.0f, -1.0f);
          glEnd();
    }
    }

   else{
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

