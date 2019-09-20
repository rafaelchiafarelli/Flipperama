#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    S = new sequence(parent);


/*IMAGE IN BACKGROUND*/
    QPixmap pix("C:\\Users\\rafae\\Documents\\GitHub\\Flipperama\\ScreenMaker\\quadro_teste_cortado.jpeg");
    ui->label->setPixmap(pix);

/*LOCAL LED*/

    off.setRgb(0,0,0,255);
    on.setRgb(ui->R_Color->value(),
              ui->G_Color->value(),
              ui->B_Color->value(),
              ui->A_slider->value());
    ui->LED->setLedSize(15);
    ui->LED->setOffColor(off);
    ui->LED->setOnColor(on);
    ui->LED->setState(true);

/*CONFIGURATION SHALL BE COMMENTED LATER*/
    connect(ui->label, SIGNAL(Mouse_Pressed()),this,SLOT(PositionSelected()));
    QFile file("C:\\Users\\rafae\\Documents\\GitHub\\Flipperama\\ScreenMaker\\text.txt");
    QString content;
    if (file.open(QIODevice::Text | QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        for(int i =0; i<NUMPIXELS; i++)
        {
        QString line = QString(file.readLine());
        QStringList data(line.split(';'));
        this->pix[i].g= data[1].toInt();
        this->pix[i].x=data[2].toInt();
        this->pix[i].y=data[3].toInt();
        content+=line;
        }

        ui->textEdit->setText(content);
        file.close();
    }

/*GAME LED*/

    ui->selectLED->setChecked(false);
    ui->selectGroup->setChecked(true);

/*timer related functions*/
    T = new QTimer(this);
    connect(T, SIGNAL(timeout()),
              this, SLOT(TimeFrame()));

}

MainWindow::~MainWindow()
{
    delete ui;


    T->stop();
    while(T->isActive());
    delete T;
    disconnect(ui->label, SIGNAL(Mouse_Pressed()),this,SLOT(PositionSelected()));

}
/*RED CONTOLLER*/


void MainWindow::changeColorLED()
{

}

void MainWindow::on_R_Color_sliderMoved(int position)
{

}

void MainWindow::on_G_Color_sliderMoved(int position)
{

}

void MainWindow::on_B_Color_sliderMoved(int position)
{

}

void MainWindow::on_A_slider_sliderMoved(int position)
{

}

void MainWindow::PositionSelected()
{
ui->textEdit->append(QString("%1;%2;%3;%4").arg(ui->textEdit->document()->blockCount()+1).arg(ui->group->value()).arg(ui->label->x).arg(ui->label->y));
}


void MainWindow::on_pushButton_clicked()
{
    QFile file("C:\\Users\\rafae\\Documents\\ScreenMaker\\ScreenMaker\\text.txt");
    while(ui->textEdit->document()->blockCount() < NUMPIXELS)
    {
        ui->textEdit->append(QString("%1;0;0;0").arg(ui->textEdit->document()->blockCount()+1));
    }
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
        file.flush();
        file.close();
    }
}


void MainWindow::on_playButton_clicked()
{
    if(ui->playButton->text() == "Play")
    {
        ui->playButton->setText(QString("Stop"));
        if(ui->speed->value()>0)
        {
         this->T->start(ui->speed->maximum()-ui->speed->value());
        }
    } else if (ui->playButton->text() == "Stop") {
        ui->playButton->setText(QString("Play"));
        this->T->stop();
    }
}
void MainWindow::on_speed_sliderMoved(int position)
{
    if(ui->playButton->text() == "Stop")
    {
    T->stop();
    T->start(ui->speed->maximum()-position);
    }
}

void MainWindow::TimeFrame()
{

    S->handler();
}


void MainWindow::on_RecordButton_clicked()
{
/*function to create the bin.h file that will be used by the embedded software*/

    //lets generate...

    //

}





















