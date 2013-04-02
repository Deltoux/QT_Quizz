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
#include <QThread>

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
    void initialiseJoueur();
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}

    public slots:

    void unJoueur();
    void deuxJoueur();
    void troisJoueur();

    void Reponse1();
    void Reponse2();
    void Reponse3();
    void Reponse4();
    void BackQuestion();



    signals:

    private:

    protected:

    static int nombreDeJoueur;

    int m_nombreDeJoueur;

    QWidget *m_page1,
            *m_page2,
            *m_page3,
            *m_page5;

    QLabel  *m_page4,
            *m_LabNombre,
            *m_etVosNoms;

    QTabWidget *m_onglets;

    QSlider *m_sliderVer,*m_sliderHor;
    //QGridLayout *layout;
    QLabel *m_LabQuest,*m_LabVrai,*m_LabFaux;
    QPushButton *m_PushResp1,
                *m_PushResp2,
                *m_PushResp3,
                *m_PushResp4,
                *m_PushChoix1,
                *m_PushChoix2,
                *m_PushChoix3,
                *m_PushJoueur1,
                *m_PushJoueur2,
                *m_PushJoueur3;

    QLineEdit   *m_LineResp1,
                *m_LineResp2,
                *m_LineResp3,
                *m_LineResp4,
                *m_LineNomJoueur;

    QGridLayout *m_GridQuest;

    QString     *m_string,
                *m_strBonneRep,
                *m_strMauvaiseRep;

    QGridLayout *vbox1,
                *vbox2,
                *vbox3,
                *vbox4,
                *vbox5;
};

class Joueur
{
    public:
    Joueur();

    void changerScore(int argent);

    protected:
    QString *m_vie;
    int m_score;
    bool m_bonusUn,m_bonusDeux;

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
