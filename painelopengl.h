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
    void iluminacao();

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

    double getCamUp() const;
    void setCamUp(double value);

    double getCamDown() const;
    void setCamDown(double value);

    boolean getMode3D() const;
    void setMode3D(const boolean &value);

    boolean getEnableLighting() const;
    void setEnableLighting(const boolean &value);

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
    double camUp;
    double camDown;
    boolean mode3D;
    boolean enableLighting;

};

#endif // PAINELOPENGL_H
