#ifndef PAINELOPENGL_H
#define PAINELOPENGL_H

#include "shape.h"
#include<QColor>
#include<QColorDialog>
#include <QGLWidget>
#include <QtOpenGL>
#include <iostream>
#include <GL/glu.h>


enum {
    UP, LEFT, RIGHT , DOWN
};

enum {
    REFLEX_X, REFLEX_Y, REFLEX_Z
};

using namespace std;
class PainelOpenGl : public QGLWidget
{
Q_OBJECT
public:
    explicit PainelOpenGl(QWidget *parent = 0);
    Shape shape;
    void drawMesh();
    void drawShape();
    vector<Shape> shapesList;
    void translated(int direction);
    void scale(double x, double y);
    void rotate(double angle);
    void zoomScale(double zoom);
    double mouseCoordinate(int width, int height, double mouseX, double mouseY);

    void mousePressEvent(QMouseEvent * event);

    void  keyPressEvent(QKeyEvent * event);

    double getZoom() const;
    void setZoom(double value);

    int getShapeFocus() const;
    void setShapeFocus(int value);

    boolean getIsDrawMesh() const;
    void setIsDrawMesh(const boolean &value);

    void glShear (double x, double y);
    void glReflexX();
    void glReflexY();
    void reflex(int reflex);

    double getMeshSize() const;
    void setMeshSize(double value);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

public slots:

private:
    int lados;
    double raio;
    double menorX, maiorX, menorY, maiorY;
    double zoom;
    int shapeFocus;
    boolean isDrawMesh;
    double meshSize;

};

#endif // PAINELOPENGL_H
