#ifndef REGAL_H
#define REGAL_H
#include <iostream>
#include <string>
#include "fahrstuhl.h"
#include "produkt.h"


class Fach
{
    bool Istbesetzt;
    Produkt pdkt;
    public:
        Fach()
        {
            Istbesetzt = false;
            pdkt = Produkt();
        }
        void setzZustand(bool state)
        {
            Istbesetzt = state;
        }
        Produkt gibPdkt() const
        {
            return pdkt;
        }
        void setzPdkt(const Produkt &p)
        {
            pdkt = p;
        }
        bool gibZustand()const
        {
            return Istbesetzt;
        }
        void entferntPdkt()
        {
            pdkt = Produkt();
        }
};

class Regal
{
private:
    int Zeile, Spalte;
    Fach* Anordnung;//Pointer auf eine Array von Faechern
    Fahrstuhl fhrstl;

public:
    Regal(int zeile=3, int spalte=3);//Konstruktor
    ~Regal();//Destruktor
    void addPdkt(const Produkt& neuPdkt, int gewuenschtZeile, int gewuenschtSpalte);//add Product at specified position
    void gibPosition(int ID);//sucht Product mit in Parameter angegebenem ID
    void aktuellPdktStand();
    void removePdkt(int ID);

};

#endif // REGAL_H
