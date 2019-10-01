#include "MeuPainelOpenGL.h"
#include <cmath>

MeuPainelOpenGL::MeuPainelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
    lados = 3;
    raio = 1.0;
}

void MeuPainelOpenGL::alterarLados(int l)
{
    if (l != lados && lados >= 3 && lados <= 60)
        lados = l;
    updateGL();
}

void MeuPainelOpenGL::alterarRaio(double r)
{
    if (r != raio && r >= 1.0 && r <= 10.0)
        raio = r;
    updateGL();
}


void MeuPainelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void MeuPainelOpenGL::resizeGL(int width, int height)
{
//    double menorX = 0, maiorX = 10, menorY = 0, maiorY = 10;
    glViewport( 0, 0, (GLint)width, (GLint)height );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,1,-1);
    if (width > height)
    {
        height = height?height:1;
        double novaLargura = (maiorX - menorX) * width / height;
        double difLargura = novaLargura - (maiorX - menorX);
        menorX = 0.0 - difLargura / 2.0;
        maiorX = 10 + difLargura / 2.0;
    }
    else
    {
        width = width?width:1;
        double novaAltura = (maiorY - menorY) * height / width;
        double difAltura = novaAltura - (maiorY - menorY);
        menorY = 0.0 - difAltura / 2.0;
        maiorY = 10 + difAltura / 2.0;
    }
    glOrtho(menorX, maiorX, menorY, maiorY,1,-1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MeuPainelOpenGL::paintGL()
{
    // Limpa a janela de visualização com a cor branca
    // e Limpa o buffer de teste de profundidade
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // limpa todas as transformações
    drawMesh();
    //glTranslated(5.0, 5.0, 0.0);

    // Desenha um polígono com N lados informado pelo usuário
    glLineWidth(1);
    glColor3f(0,0.7f,0.7f); // Define a cor de desenho: vermelho
    glBegin(GL_POLYGON);
        for (int i = 0; i < lados; ++i)
            glVertex2f(raio*cos(i*2*3.14159265/lados),
                       raio*sin(i*2*3.14159265/lados));
    glEnd();

    // Desenha as areastas de polígono com N lados informado pelo usuário
    glLineWidth(2);
    glColor3f(0,1,0);   // Define a cor de desenho: verde
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < lados; ++i)
            glVertex2f(raio*cos(i*2*3.14159265/lados),
                       raio*sin(i*2*3.14159265/lados));
    glEnd();
}
void MeuPainelOpenGL::drawMesh(){
    glLineWidth(10);
    glColor3f(0,0,0);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    for(int i = menorX; i<=maiorX; i++){
        for(int j = menorY; j<=maiorY; j++){
            glVertex2f(i,j);
        }
    }
    glEnd();
}
