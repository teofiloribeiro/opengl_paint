#include "painelopengl.h"
#include <cmath>


PainelOpenGl::PainelOpenGl(QWidget *parent):
    QGLWidget(parent)
{
    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
    lados = 3;
    raio = 1.0;
    this->zoom = 0;
    this->shapeFocus = 0;
    isDrawMesh = true;
    this->meshSize = 1;
}

double PainelOpenGl::getZoom() const
{
    return zoom;
}

void PainelOpenGl::setZoom(double value)
{
    zoom = value;
}

int PainelOpenGl::getShapeFocus() const
{
    return shapeFocus;
}

void PainelOpenGl::setShapeFocus(int value)
{
    shapeFocus = value;
}

void PainelOpenGl::initializeGL(){
    glShadeModel(GL_SMOOTH);

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void PainelOpenGl::resizeGL(int width, int height){
    this->menorX = 0, this->maiorX = 10, this->menorY = 0, this->maiorY = 10;
    glViewport( 0, 0, (GLint)width, (GLint)height );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
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
    //gluOrtho2D(menorX, maiorX, menorY, maiorY);
    glOrtho(menorX, maiorX, menorY, maiorY,100,-100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

double PainelOpenGl::mouseCoordinate(int width, int height, double mouseX, double mouseY){
}

void PainelOpenGl::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    this->drawMesh();
    this->drawShape();
}

double PainelOpenGl::getMeshSize() const
{
    return meshSize;
}

void PainelOpenGl::setMeshSize(double value)
{
    meshSize = value;
}

boolean PainelOpenGl::getIsDrawMesh() const
{
    return isDrawMesh;
}

void PainelOpenGl::setIsDrawMesh(const boolean &value)
{
    isDrawMesh = value;
}


void PainelOpenGl::drawMesh(){
    if(this->isDrawMesh){
        glLineWidth(20);
        glColor3f(0,0,0);
        glPointSize(3.0f);
        glBegin(GL_POINTS);
        for(int i = this->menorX; i<= this->maiorX; i += this->meshSize){
            for(int j = this->menorY; j<= this->maiorY; j += this->meshSize){
                glVertex2f(i,j);
            }
        }
        glEnd();
    }

}

void PainelOpenGl::drawShape()
{
  if(this->shapesList.size() > 0){
     for(int i = 0; i <= shapesList.size()-1; i++){
        glTranslated(this->shapesList.at(i).getXTranslated()+this->zoom, this->shapesList.at(i).getYTranslated()+this->zoom, 0.0);
        this->glShear(this->shapesList.at(i).getXShear(),this->shapesList.at(i).getYShear());
        glScalef(this->shapesList.at(i).getXScale()+this->zoom,this->shapesList.at(i).getYScale()+this->zoom,0);
        glRotatef(this->shapesList.at(i).getAngle()+this->zoom,0,0,1);
        if(this->shapesList.at(i).getIsReflexX())
           this->glReflexX();
        if(this->shapesList.at(i).getIsReflexY())
           this->glReflexY();
        this->shapesList.at(i).draw();
        }
    }
}

void PainelOpenGl::scale(double x, double y)
{
   this->shapesList.at(this->shapeFocus).setXScale(x);
   this->shapesList.at(this->shapeFocus).setYScale(y);
}

void PainelOpenGl::rotate(double angle)
{
    this->shapesList.at(this->shapeFocus).setAngle(angle);
}

void PainelOpenGl::zoomScale(double zoom)
{
  glLoadIdentity();
  glScalef(zoom, zoom, 0);
  updateGL();
}


void PainelOpenGl::translated(int direction)
{

    switch (direction) {
    case UP: this->shapesList.at(this->shapeFocus).setYTranslated(this->shapesList.at(this->shapeFocus).getYTranslated()+0.5);
        break;
    case LEFT:this->shapesList.at(this->shapeFocus).setXTranslated(this->shapesList.at(this->shapeFocus).getXTranslated()-0.5);
        break;
    case RIGHT:this->shapesList.at(this->shapeFocus).setXTranslated(this->shapesList.at(this->shapeFocus).getXTranslated()+0.5);
        break;
    case DOWN: this->shapesList.at(this->shapeFocus).setYTranslated(this->shapesList.at(this->shapeFocus).getYTranslated()-0.5);
        break;
    }
}

void PainelOpenGl::mousePressEvent(QMouseEvent *event)
{
}

void PainelOpenGl::keyPressEvent(QKeyEvent *event)
{
}


void PainelOpenGl::glShear (double x, double y){
    GLfloat mX[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        x,   1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(mX);
    GLfloat mY[16] = {
        1.0f, y,    0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(mY);
}

void PainelOpenGl::glReflexX(){
    GLfloat mX[16] = {
        1.0f,  0.0f, 0.0f, 0.0f,
        0.0f, -1.0f, 0.0f, 0.0f,
        0.0f,  0.0f, 1.0f, 0.0f,
        0.0f,  0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(mX);
}
void PainelOpenGl::glReflexY(){
    GLfloat mY[16] = {
        -1.0f, 0.0f, 0.0f, 0.0f,
        0.0f,  1.0f, 0.0f, 0.0f,
        0.0f,  0.0f, 1.0f, 0.0f,
        0.0f,  0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(mY);
}

void PainelOpenGl::reflex(int reflex)
{
    switch (reflex)   {
        case REFLEX_X:
            if(this->shapesList.at(this->shapeFocus).getIsReflexX())
                this->shapesList.at(this->shapeFocus).setIsReflexX(false);
            else
                this->shapesList.at(this->shapeFocus).setIsReflexX(true);
        break;
        case REFLEX_Y:
            if(this->shapesList.at(this->shapeFocus).getIsReflexY())
                this->shapesList.at(this->shapeFocus).setIsReflexY(false);
            else
                this->shapesList.at(this->shapeFocus).setIsReflexY(true);
         break;
    }
}


