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

    void on_zoomInBtn_clicked();

    void on_zoomOutBtn_clicked();

    void on_upBtn_clicked();

private:
    Ui::JanelaPrincipal *ui;
};

#endif // JANELAPRINCIPAL_H
