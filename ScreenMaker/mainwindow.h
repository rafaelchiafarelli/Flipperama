#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define NUMPIXELS 116
#include <QMainWindow>
#include "ledindicator.h"
#include <QTimer>

#include "sequence.h"

namespace Ui {
class MainWindow;
}

class PosAndGroup
{
public:
    int g,x,y;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    QTimer *T;
    void changeColorLED();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_R_Color_sliderMoved(int position);

    void on_G_Color_sliderMoved(int position);

    void on_B_Color_sliderMoved(int position);

    void on_A_slider_sliderMoved(int position);

    void PositionSelected();

    void on_pushButton_clicked();

    void TimeFrame();

    void on_playButton_clicked();

    void on_speed_sliderMoved(int position);

    void on_RecordButton_clicked();

private:
    sequence *S;


    PosAndGroup pix[NUMPIXELS];
    QColor off;
    QColor on;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
