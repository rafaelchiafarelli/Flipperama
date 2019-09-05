/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_qlabel.h>
#include "ledindicator.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_qlabel *label;
    QSlider *R_Color;
    QSlider *G_Color;
    QSlider *B_Color;
    QDial *speed;
    QComboBox *effectSelector;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *RecordButton;
    QSpinBox *screen_line;
    QLabel *label_5;
    LedIndicator *LED;
    QSlider *A_slider;
    QPushButton *playButton;
    QSpinBox *group;
    QLabel *label_7;
    QRadioButton *selectLED;
    QRadioButton *selectGroup;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QSpinBox *led_number;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1478, 766);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new my_qlabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 1280, 720));
        label->setMouseTracking(true);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        R_Color = new QSlider(centralWidget);
        R_Color->setObjectName(QString::fromUtf8("R_Color"));
        R_Color->setGeometry(QRect(1310, 460, 22, 160));
        R_Color->setMaximum(255);
        R_Color->setSliderPosition(255);
        R_Color->setOrientation(Qt::Vertical);
        G_Color = new QSlider(centralWidget);
        G_Color->setObjectName(QString::fromUtf8("G_Color"));
        G_Color->setGeometry(QRect(1340, 460, 22, 160));
        G_Color->setMaximum(255);
        G_Color->setSliderPosition(255);
        G_Color->setOrientation(Qt::Vertical);
        B_Color = new QSlider(centralWidget);
        B_Color->setObjectName(QString::fromUtf8("B_Color"));
        B_Color->setGeometry(QRect(1370, 460, 22, 160));
        B_Color->setMaximum(255);
        B_Color->setSliderPosition(255);
        B_Color->setOrientation(Qt::Vertical);
        speed = new QDial(centralWidget);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setGeometry(QRect(1420, 660, 51, 61));
        speed->setMinimum(10);
        speed->setMaximum(100);
        effectSelector = new QComboBox(centralWidget);
        effectSelector->addItem(QString());
        effectSelector->addItem(QString());
        effectSelector->addItem(QString());
        effectSelector->addItem(QString());
        effectSelector->addItem(QString());
        effectSelector->addItem(QString());
        effectSelector->setObjectName(QString::fromUtf8("effectSelector"));
        effectSelector->setGeometry(QRect(1300, 660, 111, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1320, 430, 131, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1420, 650, 51, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1300, 640, 111, 16));
        RecordButton = new QPushButton(centralWidget);
        RecordButton->setObjectName(QString::fromUtf8("RecordButton"));
        RecordButton->setGeometry(QRect(1300, 320, 161, 23));
        screen_line = new QSpinBox(centralWidget);
        screen_line->setObjectName(QString::fromUtf8("screen_line"));
        screen_line->setGeometry(QRect(1300, 280, 71, 22));
        screen_line->setMaximum(59);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1380, 280, 101, 16));
        LED = new LedIndicator(centralWidget);
        LED->setObjectName(QString::fromUtf8("LED"));
        LED->setGeometry(QRect(1430, 450, 21, 20));
        A_slider = new QSlider(centralWidget);
        A_slider->setObjectName(QString::fromUtf8("A_slider"));
        A_slider->setGeometry(QRect(1400, 460, 21, 161));
        A_slider->setMaximum(255);
        A_slider->setSliderPosition(255);
        A_slider->setOrientation(Qt::Vertical);
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(1300, 250, 75, 23));
        group = new QSpinBox(centralWidget);
        group->setObjectName(QString::fromUtf8("group"));
        group->setGeometry(QRect(1390, 380, 61, 22));
        group->setMaximum(60);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1320, 410, 101, 16));
        selectLED = new QRadioButton(centralWidget);
        selectLED->setObjectName(QString::fromUtf8("selectLED"));
        selectLED->setGeometry(QRect(1300, 350, 82, 17));
        selectGroup = new QRadioButton(centralWidget);
        selectGroup->setObjectName(QString::fromUtf8("selectGroup"));
        selectGroup->setGeometry(QRect(1300, 380, 82, 17));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(1300, 10, 171, 231));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1380, 250, 75, 23));
        led_number = new QSpinBox(centralWidget);
        led_number->setObjectName(QString::fromUtf8("led_number"));
        led_number->setGeometry(QRect(1390, 350, 61, 22));
        led_number->setMaximum(116);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Configurtador", nullptr));
        label->setText(QString());
        effectSelector->setItemText(0, QApplication::translate("MainWindow", "SELECT EFFECT", nullptr));
        effectSelector->setItemText(1, QApplication::translate("MainWindow", "TRAIN_BACK", nullptr));
        effectSelector->setItemText(2, QApplication::translate("MainWindow", "TRAIN_FWRD", nullptr));
        effectSelector->setItemText(3, QApplication::translate("MainWindow", "FLASH", nullptr));
        effectSelector->setItemText(4, QApplication::translate("MainWindow", "SMOTH_BLINK", nullptr));
        effectSelector->setItemText(5, QApplication::translate("MainWindow", "NONE", nullptr));

        label_2->setText(QApplication::translate("MainWindow", " R       G        B     A", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Velocidade", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Efeito do grupo", nullptr));
        RecordButton->setText(QApplication::translate("MainWindow", "Gravar", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "N\303\272mero da tela", nullptr));
        playButton->setText(QApplication::translate("MainWindow", "Play", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Cor Predominante", nullptr));
        selectLED->setText(QApplication::translate("MainWindow", "LED", nullptr));
        selectGroup->setText(QApplication::translate("MainWindow", "Grupo", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
