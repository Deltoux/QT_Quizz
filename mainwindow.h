#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <fstream>
#include <string>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMainWindow>
#include <QGridLayout>
#include <QSlider>
#include <QString>
#include <QTabWidget>
#include <QApplication>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    
public:
    explicit MainWindow(QWidget *parent = 0);
    void lire() const;
    ~MainWindow();
    
private:
    //QLineEdit *nameEd  = new QLineEdit(this);
    Ui::MainWindow *ui;
    QGridLayout *layout = new QGridLayout;
    QLabel *m_LabQuest;
    QPushButton *m_PushResp1,*m_PushResp2,*m_PushResp3,*m_PushResp4;
    QLineEdit *m_LineResp1, *m_LineResp2, *m_LineResp3, *m_LineResp4;
    QGridLayout *m_GridQuest;
};



class MaFenetre : public QWidget
{
    Q_OBJECT

    public:
    MaFenetre();
    void lire() const;

    public slots:

    void Reponse1();
    void Reponse2();
    void Reponse3();
    void Reponse4();

    signals:

    private:

    protected:

    QWidget *m_page1,*m_page2,*m_page3;
    QLabel *m_page4,*m_page5;

    QTabWidget *m_onglets;

    QSlider *m_sliderVer,*m_sliderHor;
    QGridLayout *layout = new QGridLayout;
    QLabel *m_LabQuest,*m_LabVrai,*m_LabFaux;
    QPushButton *m_PushResp1,*m_PushResp2,*m_PushResp3,*m_PushResp4;
    QLineEdit *m_LineResp1, *m_LineResp2, *m_LineResp3, *m_LineResp4;
    QGridLayout *m_GridQuest;
    QString *m_string,
            *m_strBonneRep,
            *m_strMauvaiseRep;
    QVBoxLayout *vbox3,
                *vbox4,
                *vbox5;

};

#endif // MAINWINDOW_H

class MonClasseur: public QWidget
{
    Q_OBJECT

    public:

    MonClasseur();

    public slots:
    //void reception();
    //void SL_Reponse(int 1);

    signals:

    //void SI_BonneReponse();
    //void SI_MauvaiseReponse();



    private:

    protected:

};
