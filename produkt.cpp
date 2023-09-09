#include "produkt.h"

Produkt::Produkt()
{
    Name = '\0';
    ID = 0;
}

Produkt::Produkt(const Produkt& p)
{
    Name = p.gibID();
    ID = p.gibID();
}

string Produkt::gibName() const
{
    return Name;
}

int Produkt::gibID() const
{
    return ID;
}

bool Produkt::isEqual(const Produkt& p2) const
{
    if(ID == p2.gibID())
    {
        return true;
    }else
    {
        return false;
    }
}
