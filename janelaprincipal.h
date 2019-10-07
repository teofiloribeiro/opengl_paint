#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QGLWidget>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class JanelaPrincipal;
}

class JanelaPrincipal : public QWidget
{
    Q_OBJECT

public:
    explicit JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();

    QColor getColor() const;
    void setColor(const QColor &value);

    QColor getLineColor() const;
    void setLineColor(const QColor &value);

private slots:
    void on_drawBtn_clicked();


    void on_upBtn_clicked();

    void on_leftBtn_clicked();

    void on_rightBtn_clicked();

    void on_downBtn_clicked();

    void on_xScaleSpinBox_valueChanged(double arg1);

    void on_yScaleSpinBox_valueChanged(double arg1);

    void on_rotationDial_sliderMoved(int position);

    void on_rotationDial_sliderPressed();

    void on_focusPreviousBtn_clicked();

    void on_focusNextBtn_clicked();

    void on_eraseBtn_clicked();

    void on_colorBtn_clicked();

    void on_lineColorBtn_clicked();

    void on_openAction_triggered();

    void on_saveAction_triggered();

    void on_drawCircleBtn_clicked();

    void on_drawSquareBtn_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_actionNovo_triggered();

    void on_meshCheckBox_stateChanged(int arg1);

    void on_zoomInBtn_clicked();

    void on_zoomOutBtn_clicked();

    void on_shXDoubleSpinBox_valueChanged(double arg1);

    void on_shYDoubleSpinBox_valueChanged(double arg1);

    void on_reflexXBtn_clicked();

    void on_reflexYBtn_clicked();

    void on_meshSizeSpin_valueChanged(double arg1);

private:
    Ui::JanelaPrincipal *ui;
    QColor color;
    QColor lineColor;
};

#endif // JANELAPRINCIPAL_H
