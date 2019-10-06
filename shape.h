#ifndef SHAPE_H
#define SHAPE_H

#include <GL/gl.h>
#include <cmath>
#include<QColor>

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

   double getXTranslated() const;
   void setXTranslated(double value);

   double getYTranslated() const;
   void setYTranslated(double value);

   double getXScale() const;
   void setXScale(double value);

   double getYScale() const;
   void setYScale(double value);

   double getAngle() const;
   void setAngle(double value);

   boolean getIsFocused() const;
   void setIsFocused(const boolean &value);

   QColor getColor() const;
   void setColor(const QColor &value);

   QColor getLineColor() const;
   void setLineColor(const QColor &value);

private:
   int side;
   double radius;
   double xTranslated, yTranslated;
   double xScale, yScale;
   double angle;
   boolean isFocused;
   QColor color;
   QColor lineColor;
};

#endif // SHAPE_H
