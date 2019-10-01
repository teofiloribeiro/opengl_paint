#ifndef MEUPAINELOPENGL_H
#define MEUPAINELOPENGL_H

#include <QGLWidget>
#include <GL/glu.h>

class MeuPainelOpenGL : public QGLWidget
{
Q_OBJECT
public:
    explicit MeuPainelOpenGL(QWidget *parent = 0);
    void drawMesh();
signals:

public slots:
    void alterarLados(int l);
    void alterarRaio(double r);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    int lados;
    double raio;
    double menorX = 0, maiorX = 10, menorY = 0, maiorY = 10;
};

#endif // MEUPAINELOPENGL_H
