#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QGLWidget>

namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QWidget
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();

private slots:
    void on_drawBtn_clicked();


    void on_upBtn_clicked();

    void on_leftBtn_clicked();

    void on_rightBtn_clicked();

    void on_downBtn_clicked();

    void on_xScaleSpinBox_valueChanged(double arg1);

    void on_yScaleSpinBox_valueChanged(double arg1);

private:
    Ui::JanelaPrincipal *ui;
};

#endif // JANELAPRINCIPAL_H
