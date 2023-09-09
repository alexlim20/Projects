#include "regal.h"
using namespace std;
#define RIGHT 1
#define LEFT 0
#define UP 0
#define DOWN 1

Regal::Regal(int zeile, int spalte)
{
    Zeile = zeile;
    Spalte = spalte;
    Anordnung = new Fach[Zeile*Spalte]();
    fhrstl = Fahrstuhl();
}

Regal::~Regal()
{
    delete Anordnung;
}

void Regal::addPdkt(const Produkt& neuPdkt,int gewuenschtZeile, int gewuenschtSpalte)//von 0 bis...
{
    for(int i = 0;i<Zeile;i++)
    {
        for(int j = 0; j<Spalte;j++)
        {
            if(gewuenschtSpalte==j && gewuenschtZeile==i && !((Anordnung + j + i*Spalte)->gibZustand()))
            {
                (Anordnung + j + i*Spalte)->setzZustand(true);
                (Anordnung + j + i*Spalte)->setzPdkt(neuPdkt);

                fhrstl.Get_Produkt();
                fhrstl.Beweg_X(j, RIGHT);
                fhrstl.Beweg_Y(i, UP);
                fhrstl.Drop_Produkt();
                fhrstl.ReturnToZero(X_sensor_zero, Y_sensor_zero);

                cout<<"Produkt erfolgreich hinzugefuegt"<<endl;
                break;
            }else if(gewuenschtSpalte==j && gewuenschtZeile==i && (Anordnung + j + i*Spalte)->gibZustand())
            {
                cout<<"Das angegebene Fach ist belegt"<<endl;
            }
        }
    }
}

void Regal::gibPosition(int ID)
{
    bool gefunden=false;
    for(int i = 0;i<Zeile;i++)
    {
        for(int j = 0; j<Spalte;j++)
        {
            if((Anordnung + j + i*Spalte)->gibPdkt().gibID()==ID)
            {
                gefunden = true;
                cout<<"Produkt ID: "<< (Anordnung + j + i*Spalte)->gibPdkt().gibID()<< " auf Zeile " << i << ", Spalte " << j <<endl;
            }
        }
    }
    if(!gefunden)
    {
        cout<<"Produkt ID: "<<ID<< " nicht gefunden"<<endl;
    }
}

void Regal::aktuellPdktStand()
{
    for(int i = 0;i<Zeile;i++)
    {
        for(int j = 0; j<Spalte;j++)
        {
            if((Anordnung + j + i*Spalte)->gibZustand())
            {
                cout<<"1 ";
            }else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

void Regal::removePdkt(int ID)
{
    bool isremoved=false;
    for(int i = 0;i<Zeile;i++)
    {
        for(int j = 0; j<Spalte;j++)
        {
            if((Anordnung + j + i*Spalte)->gibPdkt().gibID()==ID && (Anordnung + j + i*Spalte)->gibZustand())
            {
                isremoved = true;
                (Anordnung + j + i*Spalte)->setzZustand(false);
                (Anordnung + j + i*Spalte)->entferntPdkt();

                fhrstl.Beweg_X(j, RIGHT);
                fhrstl.Beweg_Y(i, UP);
                fhrstl.Get_Produkt();
                fhrstl.Beweg_X(KOORDINATEN VON ABLAGEPUNKT, RIGHT);

                fhrstl.Beweg_Y(KOORDINATEN VON ABLAGEPUNKT, DOWN);

                fhrstl.Drop_Produkt();
                fhrstl.ReturnToZero(X_sensor_zero, Y_sensor_zero);                

                cout<<"Produkt erfolgreich entfernt"<<endl;
                break;
            }
        }
    }
    if(!isremoved)
    {
        cout<<"Kein Produkt drin!"<<endl;
    }
}

