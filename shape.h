#ifndef SHAPE_H
#define SHAPE_H

#include <GL/gl.h>
#include <cmath>

class point {
public:
    GLfloat x;
    GLfloat y;
};

class Cor{
public:
     GLfloat r, g, b;
};

class Shape
{
public:
   Shape();
   Shape(int side, double radius);
   void draw();


   int getSide() const;
   void setSide(int value);

   double getRadius() const;
   void setRadius(double value);

private:
   int side;
   double radius;
};

#endif // SHAPE_H
