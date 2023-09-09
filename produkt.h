#ifndef PRODUKT_H
#define PRODUKT_H
#include <iostream>
#include <string>

using namespace std;

class Produkt
{
private:
    string Name;
    int ID;


public:
    Produkt();//Defaultkonstruktor
    Produkt(const Produkt& p);//Copy Konstruktor
    Produkt(string Name, int ID):Name(Name), ID(ID){} //ParameterKonstruktor
    string gibName() const;
    int gibID() const;
    bool isEqual(const Produkt &p1) const;//bestimmt ob die Produkten gleich sind
};

#endif // PRODUKT_H

