#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QVector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MaFenetre::lire() const
{
}


MaFenetre::MaFenetre() : QWidget()
{
    this->setMinimumSize(500,500);

    int i=0;
    QString ligne;
    QString fileName = "C:/Users/Bertrand/Documents/QTiizz/Question/Q001.txt";
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QVector <QString> texte(100);
    while(! flux.atEnd())
            {
                texte[i] = flux.readLine();
                i++;
                cout<<i<<endl;
                //traitement de la ligne
            }

    m_LabQuest = new QLabel(this);
    m_string = new QString();
    m_strBonneRep= new QString();
    m_strMauvaiseRep= new QString();

    m_PushResp1=new QPushButton("&ligne",this);
    m_PushResp2=new QPushButton("Plip",this);
    m_PushResp3=new QPushButton("Plup",this);
    m_PushResp4=new QPushButton("Plep",this);

    m_PushResp1->setText(texte[1]);
    m_PushResp2->setText(texte[2]);
    m_PushResp3->setText(texte[3]);
    m_PushResp4->setText(texte[4]);

    m_strBonneRep->append(texte[5]);

    m_onglets= new QTabWidget(this);
    m_onglets->setGeometry(30, 20, 400, 300);

    m_page1= new QWidget();
    m_page2= new QWidget();
    m_page3= new QWidget();
    m_page4= new QLabel();
    m_page5= new QLabel();

    vbox3 = new QVBoxLayout;
    vbox3->addWidget(m_LabQuest);
    vbox3->addWidget(m_PushResp1);
    vbox3->addWidget(m_PushResp2);
    vbox3->addWidget(m_PushResp3);
    vbox3->addWidget(m_PushResp4);
    m_page3->setLayout(vbox3);

    m_page4->setPixmap(QPixmap("faux2.gif"));

    m_page5->setPixmap(QPixmap("vrai.png"));


    m_onglets->addTab(m_page1, "Présentation");
    m_onglets->addTab(m_page2, "Choix Question");
    m_onglets->addTab(m_page3, "Question");
    m_onglets->addTab(m_page4, "Faux");
    m_onglets->addTab(m_page5, "Vrai");

    //m_onglets->setTabPosition(Tabposition);




    //*QObject::connect(m_sliderHor, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));
    //QObject::connect(m_sliderVer, SIGNAL(valueChanged(int)), this, SLOT(changerLongueur(int)));
    //QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(quit()));
    QObject::connect(m_PushResp1, SIGNAL(clicked()), this, SLOT(Reponse1()));
    QObject::connect(m_PushResp2, SIGNAL(clicked()), this, SLOT(Reponse2()));
    QObject::connect(m_PushResp3, SIGNAL(clicked()), this, SLOT(Reponse3()));
    QObject::connect(m_PushResp4, SIGNAL(clicked()), this, SLOT(Reponse4()));

}

void MaFenetre::Reponse1()
{
    string str1 = m_strBonneRep->toStdString();
    string str2 = "1";

    if (str1.compare(str2) != 0)
    {
        cout <<"baaaaaaaaaaaaaaaah"<< endl;
        //m_onglets->setTabPosition(4);
    }
    else
    {
        cout <<"Nice!!!!!!!!"<< endl;
        //m_onglets->setTabPosition(5);
    }

}

void MaFenetre::Reponse2()
{
    string str1 = m_strBonneRep->toStdString();
    string str2 = "2";

    if (str1.compare(str2) != 0)
    {
        cout <<"baaaaaaaaaaaaaaaah"<< endl;
    }
    else
    {
        cout <<"Nice!!!!!!!!"<< endl;
    }
}

void MaFenetre::Reponse3()
{
    string str1 = m_strBonneRep->toStdString();
    string str2 = "3";

    if (str1.compare(str2) != 0)
    {
        cout <<"baaaaaaaaaaaaaaaah"<< endl;
    }
    else
    {
        cout <<"Nice!!!!!!!!"<< endl;
    }
}

void MaFenetre::Reponse4()
{
    string str1 = m_strBonneRep->toStdString();
    string str2 = "4";

    if (str1.compare(str2) != 0)
    {
        cout <<"baaaaaaaaaaaaaaaah"<< endl;
    }
    else
    {
        cout <<"Nice!!!!!!!!"<< endl;
    }
}



MonClasseur::MonClasseur(): QWidget()
{

}
