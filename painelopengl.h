#ifndef PAINELOPENGL_H
#define PAINELOPENGL_H

#include "shape.h"
#include <QGLWidget>
#include <QtOpenGL>
#include <iostream>



enum {
    UP, LEFT, RIGHT , DOWN
};
using namespace std;
class PainelOpenGl : public QGLWidget
{
Q_OBJECT
public:
    //PainelOpenGl();
    explicit PainelOpenGl(QWidget *parent = 0);
    Shape shape;
    void drawMesh();
    void drawShape();
    vector<Shape> shapesList;
    void translated(int direction);
    void scale();

    double mouseCoordinate(int width, int height, double mouseX, double mouseY);

    void mousePressEvent(QMouseEvent * event);

    double getZoom() const;
    void setZoom(double value);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

public slots:
    void alterarLados(int l);
    void alterarRaio(double r);

private:
    int lados;
    double raio;
    double menorX, maiorX, menorY, maiorY;
    double zoom;
};

#endif // PAINELOPENGL_H
