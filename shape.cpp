#include "shape.h"

#include<iostream>
Shape::Shape()
{

}

Shape::Shape(int side, double radius)
{
   this->side = side;
   this->radius = radius;
}

void Shape::draw()
{
    std::cout<<this->side << "\n";
    std::cout<<this->radius << "\n";
    ///glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // glLoadIdentity(); // limpa todas as transforma��es*/


    glLineWidth(1);
    glColor3f(0,0.7f,0.7f);
    glBegin(GL_POLYGON);
        for (int i = 0; i < this->side; ++i)
            glVertex2f(this->radius*cos(i*2*3.14159265/this->side),
                       this->radius*sin(i*2*3.14159265/this->side));
    glEnd();

    glLineWidth(2);
    glColor3f(1,1,0);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < this->side; ++i)
            glVertex2f(this->radius*cos(i*2*3.14159265/this->side),
                       this->radius*sin(i*2*3.14159265/this->side));
    glEnd();
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

