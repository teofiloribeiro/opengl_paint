#include "shape.h"

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
    /*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // limpa todas as transforma��es*/
    glTranslated(5.0, 5.0, 0.0);

    glLineWidth(1);
    glColor3f(0,0.7f,0.7f);
    glBegin(GL_POLYGON);
        for (int i = 0; i < this->side; ++i)
            glVertex2f(this->radius*cos(i*2*3.14159265/this->side),
                       this->radius*sin(i*2*3.14159265/this->side));
    glEnd();

    glLineWidth(2);
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < this->side; ++i)
            glVertex2f(this->radius*cos(i*2*3.14159265/this->side),
                       this->radius*sin(i*2*3.14159265/this->side));
    glEnd();
}
