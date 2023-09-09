#include <iostream>
#include <string>
#include <wiringPi.h>
#include "regal.h"
#include "fahrstuhl.h"


using namespace std;

#define ZEILE 3
#define SPALTE 3


/*#define STEP_PIN 1

#define EN_1 0                                                          //ENABLE PIN
#define EN_2 2
#define EN_3 3

#define DIR_1 21                                                        //DIR PIN
#define DIR_2 22
#define DIR_3 23

#define Button_1 8 //X_ZERO                                                      //ENDSCHALTER
#define Button_2 9 //Y_ZERO
#define Button_3 //X_ENDE
#define Button_4 //Y_ENDE
#define Button_5 //????*/

int main()
{
/*
    //DIGITAL PINS
    pinMode (EN_1, OUTPUT);
    pinMode (EN_2, OUTPUT);
    pinMode (EN_3, OUTPUT);
    pinMode (DIR_1, OUTPUT);
    pinMode (DIR_2, OUTPUT);
    pinMode (DIR_3, OUTPUT);

    pinMode (Button_1, INPUT);
    pinMode (Button_2, INPUT);
    pinMode (Button_3, INPUT);
    pinMode (Button_4, INPUT);
    pinMode (Button_5, INPUT);

    pullUpDnControl (Button_1, PUD_DOWN);
    pullUpDnControl (Button_2, PUD_DOWN);
    pullUpDnControl (Button_3, PUD_DOWN);
    pullUpDnControl (Button_4, PUD_DOWN);
    pullUpDnControl (Button_5, PUD_DOWN);


    //PWM SIGNAL
    pinMode (STEP_PIN, PWM_OUTPUT);

    pwmSetMode(PWM_MODE_BAL);
    pwmSetClock(384);//192                  500Hz
    pwmSetRange(100);//100
*/






    Regal exp = Regal(ZEILE, SPALTE);

    //Fahrstuhl fhrstl = Fahrstuhl;

    int eingabe;
    do
    {
        cout<<"1:add a new product       2:find a product's Position      3:check current products shelf        4:remove a product"<<endl;
        cin>>eingabe;

        switch(eingabe)
        {
        case 1:
        {
            int inputID,Zeile, Spalte;
            string inputName;
            cout << "Zeile?" << endl;
            cin>>Zeile;
            cout << "Spalte?" << endl;
            cin>>Spalte;
            cout<<"ID: ";
            cin>>inputID;
            cout<<"Name: ";
            cin.ignore();
            getline(cin, inputName);
            exp.addPdkt(Produkt(inputName, inputID), Zeile, Spalte);

            /*Fahrstuhl.Greif_Produkt();
            Fahrstuhl.Beweg_X(Zeile);
            Fahrstuhl.Beweg_Y(Spalte);
            Fahrstuhl.Drop_Produkt();
            Fahrstuhl.ReturnToZero(X_sensor_zero, Y_sensor_zero);*/
            break;
        }
        case 2:
        {
            int inputID1;
            cout<<"ID?"<<endl;
            cin>>inputID1;
            exp.gibPosition(inputID1);
            break;
        }
        case 3:
        {
            exp.aktuellPdktStand();
            break;
        }
        case 4:
        {
            int inputID2;
            cout<<"ID?"<<endl;
            cin>>inputID2;
            exp.removePdkt(inputID2);

            /*Fahrstuhl.Beweg_X();
            Fahrstuhl.Beweg_Y();
            Fahrstuhl.Greif_Produkt();
            Fahrstuhl.Beweg_X(KOORDINATEN VON ABLAGEPUNKT);

            digitalWrite (EN_1, LOW);
            digitalWrite (DIR_1, HIGH);                               //RUNTER
            delayMicroseconds ((100*ZEILEFACH-HOEHEABLAGEPUNKT)*MM*STEP);

            digitalWrite (EN_1, HIGH);

            Fahrstuhl.Drop_Produkt();
            Fahrstuhl.ReturnToZero(X_sensor_zero, Y_sensor_zero);*/
        }
        }
    }
    while(eingabe!=404);
    cout << "Programm beendet" << endl;
    return 0;
}
