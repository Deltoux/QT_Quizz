#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MaFenetre wis;
    Joueur joueurUn, JoueurDeux,JoueurTrois;

    //w.lire();
    //return 0;
    wis.show();
    
    return a.exec();
}
