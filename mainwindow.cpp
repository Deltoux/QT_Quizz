#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QTimer>


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

    m_PushResp1=new QPushButton(this);
    m_PushResp2=new QPushButton(this);
    m_PushResp3=new QPushButton(this);
    m_PushResp4=new QPushButton(this);

    m_PushResp1->setText(texte[1]);
    m_PushResp2->setText(texte[2]);
    m_PushResp3->setText(texte[3]);
    m_PushResp4->setText(texte[4]);

    m_PushChoix1=new QPushButton("Plep",this);
    m_PushChoix2=new QPushButton("Plep",this);
    m_PushChoix3=new QPushButton("Plep",this);

    m_LineNomJoueur =new QLineEdit();
        m_LineNomJoueur->hide();
    m_LabNombre = new QLabel("Combien de joueur?");
        m_LabNombre->hide();
    m_etVosNoms = new QLabel("Et ton petit nom joueur 1");
        m_etVosNoms->hide();
    m_PushValidNom =new QPushButton(this);
        m_PushValidNom->hide();
    m_PushJoueur1=new QPushButton("1",this);
    m_PushJoueur2=new QPushButton("2",this);
    m_PushJoueur3=new QPushButton("3",this);

    m_strBonneRep->append(texte[5]);

    m_onglets= new QTabWidget(this);
    m_onglets->setGeometry(30, 20, 400, 300);

    m_page1= new QWidget();
    m_page2= new QWidget();
    m_page3= new QWidget();
    m_page4= new QLabel();
    m_page5= new QWidget();


    vbox1 = new QGridLayout;
    vbox1->addWidget(m_LabNombre,1,0,1,3);
    vbox1->addWidget(m_PushJoueur1,2,0);
    vbox1->addWidget(m_PushJoueur2,2,1);
    vbox1->addWidget(m_PushJoueur3,2,2);
    vbox1->addWidget(m_LineNomJoueur,2,1,1,1);
    vbox1->addWidget(m_etVosNoms,2,0);
    vbox1->addWidget(m_PushValidNom,2,2);
    m_page1->setLayout(vbox1);

    vbox2 = new QGridLayout;
    vbox2->addWidget(m_PushChoix1,1,0);
    vbox2->addWidget(m_PushChoix2,2,0);
    vbox2->addWidget(m_PushChoix3,3,0);
    m_page2->setLayout(vbox2);

    vbox3 = new QGridLayout;
    vbox3->addWidget(m_LabQuest);
    vbox3->addWidget(m_PushResp1,1,0);
    vbox3->addWidget(m_PushResp2,2,0);
    vbox3->addWidget(m_PushResp3,3,0);
    vbox3->addWidget(m_PushResp4,4,0);
    m_page3->setLayout(vbox3);

    m_LabVrai= new QLabel;
    m_LabVrai->setText("faux");
    vbox4 = new QGridLayout;
    vbox4->addWidget(m_LabVrai);
    m_page4->setLayout(vbox4);

    m_LabVrai= new QLabel;
    m_LabVrai->setText("vrai");
    vbox5 = new QGridLayout;
    vbox5->addWidget(m_LabVrai);
    m_page5->setLayout(vbox5);


    m_onglets->addTab(m_page1, "Présentation");
    m_onglets->addTab(m_page2, "Choix Question");
    m_onglets->addTab(m_page3, "Question");
    m_onglets->addTab(m_page4, "Faux");
    m_onglets->addTab(m_page5, "Vrai");

    QObject::connect(m_PushResp1, SIGNAL(clicked()), this, SLOT(Reponse1()));
    QObject::connect(m_PushResp2, SIGNAL(clicked()), this, SLOT(Reponse2()));
    QObject::connect(m_PushResp3, SIGNAL(clicked()), this, SLOT(Reponse3()));
    QObject::connect(m_PushResp4, SIGNAL(clicked()), this, SLOT(Reponse4()));

    QObject::connect(m_PushJoueur1, SIGNAL(clicked()), this, SLOT(unJoueur()));
    QObject::connect(m_PushJoueur2, SIGNAL(clicked()), this, SLOT(deuxJoueur()));
    QObject::connect(m_PushJoueur3, SIGNAL(clicked()), this, SLOT(troisJoueur()));

    QObject::connect(m_PushValidNom, SIGNAL(clicked()), this, SLOT(troisJoueur()));

    //string Joueur
}

void MaFenetre::Reponse1()
{
    string str1 = m_strBonneRep->toStdString();
    string str2 = "1";

    if (str1.compare(str2) != 0)
    {
        cout <<"baaaaaaaaaaaaaaaah"<< endl;
        this->m_onglets->setCurrentIndex(3);
        this->m_PushResp1->hide();
    }
    else
    {
        cout <<"Nice!!!!!!!!"<< endl;
        m_onglets->setCurrentIndex(4);

    }

    QTimer::singleShot(1000, this, SLOT(BackQuestion()));
}

void MaFenetre::Reponse2()
{
    string str1 = m_strBonneRep->toStdString();
    string str2 = "2";

    if (str1.compare(str2) != 0)
    {
        cout <<"baaaaaaaaaaaaaaaah"<< endl;
        this->m_onglets->setCurrentIndex(3);
        this->m_PushResp2->hide();
    }
    else
    {
        cout <<"Nice!!!!!!!!"<< endl;
        m_onglets->setCurrentIndex(4);

    }


    QTimer::singleShot(1000, this, SLOT(BackQuestion()));
}

void MaFenetre::Reponse3()
{
    string str1 = m_strBonneRep->toStdString();
    string str2 = "3";

    if (str1.compare(str2) != 0)
    {
        cout <<"baaaaaaaaaaaaaaaah"<< endl;
        this->m_onglets->setCurrentIndex(3);
        this->m_PushResp3->hide();
    }
    else
    {
        cout <<"Nice!!!!!!!!"<< endl;
        m_onglets->setCurrentIndex(4);

    }


    QTimer::singleShot(1000, this, SLOT(BackQuestion()));
}

void MaFenetre::Reponse4()
{
    string str1 = m_strBonneRep->toStdString();
    string str2 = "4";

    if (str1.compare(str2) != 0)
    {
        cout <<"baaaaaaaaaaaaaaaah"<< endl;
        this->m_onglets->setCurrentIndex(3);
        this->m_PushResp4->hide();
    }
    else
    {
        cout <<"Nice!!!!!!!!"<< endl;
        m_onglets->setCurrentIndex(4);

    }


    QTimer::singleShot(1000, this, SLOT(BackQuestion()));
}

void MaFenetre::BackQuestion()
{
    m_onglets->setCurrentIndex(2);
}

void MaFenetre::unJoueur()
{
    m_nombreDeJoueur=1;

    MaFenetre::initialiseJoueur();
    //joueurUn.changerNom(joueurUn,"Albert");

}

void MaFenetre::deuxJoueur()
{
    m_nombreDeJoueur=2;
    //Joueur joueurUn,joueurDeux;
    MaFenetre::initialiseJoueur();

}

void MaFenetre::troisJoueur()
{
    m_nombreDeJoueur=3;
    //Joueur joueurUn,joueurDeux,joueurTrois;
    MaFenetre::initialiseJoueur();

}

void MaFenetre::initialiseJoueur()
{
    int i=0;
    m_PushJoueur1->hide();
    m_PushJoueur2->hide();
    m_PushJoueur3->hide();
    m_LabNombre->hide();
    for(i=0;i<m_nombreDeJoueur;i++);
    {
        m_LineNomJoueur->show();
        m_LineNomJoueur->clear();
        m_etVosNoms->show();
        m_PushValidNom->show();

    }
}

void MaFenetre::nommerJoueur()
{

}

MonClasseur::MonClasseur(): QWidget()
{

}

//MaFenetre::MaFenetre() : QWidget()


  Joueur::Joueur()
{
    m_nom = new QString;
    m_score=0;
    m_bonusUn=TRUE;
    m_bonusDeux=TRUE;
}

  void Joueur::changerScore(int argent)
  {
      this->m_score =+ argent;
  }

  void Joueur::changerNom(Joueur &cible,QString nom)
  {
      cible.m_nom->clear();
      cible.m_nom->append(nom);
      cout<<m_nom<<endl;
  }
