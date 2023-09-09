#include "fahrstuhl.h"
#include "math.h"
#include <wiringPi.h>

#define RANGE 1000                                                      //RANGE: Anzahl der steps f�r ein und ausfahren der Gabel
#define RANGE_Y 1000                                                     //RANGE_Y: Anzahl der steps zum anheben in y-Richtung

#define MM 5                                                            //KOEFIZIENTEN
#define STEP 2010

#define STEP_PIN 1

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
#define Button_5 //????


Fahrstuhl::Fahrstuhl()
{
    X_sensor_zero = false;                                   //SENSOR NICHT AKTIV
    X_sensor_end = false;
    Y_sensor_zero = false;
    Y_sensor_end = false;
    Gabel_sensor = false;
    //active = false;

    if (wiringPiSetup () == -1)
    {
        exit (1) ;
    }else
    {
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
    }
}


void Fahrstuhl::Beweg_X(int spalte, int direction)
{
/* IN MAIN
    pinMode (EN_2, OUTPUT);
    pinMode (DIR_2, OUTPUT);
*/
/* IN MAIN
    pinMode (STEP_PIN, PWM_OUTPUT);

    pwmSetMode(PWM_MODE_BAL);
    pwmSetClock(384);//192                  500Hz
    pwmSetRange(100);//100
*/
 //   pwmWrite (STEP_PIN, 99);

    digitalWrite (EN_2, LOW);
    digitalWrite (DIR_2, direction);                          //RECHTS
    delayMicroseconds (100*MM*STEP*(spalte+1));

    digitalWrite (EN_2, HIGH);
}


void Fahrstuhl::Beweg_Y(int zeile,int direction)
{
/* IN MAIN
    pinMode (EN_1, OUTPUT);
    pinMode (DIR_1, OUTPUT);

    pinMode (STEP_PIN, PWM_OUTPUT);

    pwmSetMode(PWM_MODE_BAL);
    pwmSetClock(384);//192                  500Hz
    pwmSetRange(100);//100
*/
 //   pwmWrite(STEP_PIN, 99);

    digitalWrite (EN_1, LOW);
    digitalWrite (DIR_1, direction);                          //HOCH
    delayMicroseconds (100*MM*STEP*(zeile));

    digitalWrite (EN_1, HIGH);
}


void Fahrstuhl::ReturnToZero(bool &X_sensor_zero, bool &Y_sensor_zero)
{
/* IN MAIN
    pinMode (EN_1, OUTPUT);
    pinMode (EN_2, OUTPUT);
    pinMode (DIR_1, OUTPUT);
    pinMode (DIR_2, OUTPUT);

    pinMode (Button_1, INPUT);
    pinMode (Button_2, INPUT);
    //pullUpDnControl (Button_1, PUD_DOWN);
    //pullUpDnControl (Button_2, PUD_DOWN);

    pinMode (STEP_PIN, PWM_OUTPUT);

    pwmSetMode (PWM_MODE_BAL);
    pwmSetClock (384);//192                  500Hz
    pwmSetRange (100);//100
*/

    while((x_sensor_zero == false) && (y_sensor_zero == false))
    {
        digitalWrite (EN_1, LOW);
        digitalWrite (EN_2, LOW);
        digitalWrite (DIR_1, HIGH);                       //RUNTER
        digitalWrite (DIR_2, LOW);                        //LINKS
        //pwmWrite (STEP_PIN, 99);
    }
    digitalWrite (EN_1, HIGH);
    digitalWrite (EN_2, HIGH);

    while(x_sensor_zero == false)
    {
        digitalWrite (EN_2, LOW);
        digitalWrite (DIR_2, LOW);                          //LINKS
        //pwmWrite (STEP_PIN, 99);
    }

    digitalWrite (EN_2, HIGH);


    while(y_sensor_zero == false)
    {
        digitalWrite (EN_1, LOW);
        digitalWrite (DIR_1, HIGH);                          //LINKS
        //pwmWrite (STEP_PIN, 99);
    }

    digitalWrite (EN_1, HIGH);

}

//UNVOLLSTAENDIG
void Fahrstuhl::Get_Produkt()
{
/* IN MAIN
    pinMode(EN_3, OUTPUT);
    pinMode(DIR_3, OUTPUT);

    pwmSetMode (PWM_MODE_BAL);
    pwmSetClock (384);//192                  500Hz
    pwmSetRange (100);//100
*/
    //pwmWrite (STEP_PIN,99);

    digitalWrite (EN_3, LOW);
    digitalWrite (DIR_3, );//WERT FUER AUSFAHREN
    delayMicroseconds(RANGE*MM*STEP);

    digitalWrite(EN_3, HIGH);


    Beweg_Y(0.1,LOW);                                               //Anheben 1cm


    digitalWrite (EN_3, LOW);
    digitalWrite (DIR_3, );//WERT FUER EINFAHREN
    delayMicroseconds(RANGE*MM*STEP);

    digitalWrite(EN_3,HIGH);
}

//UNVOLLSTAENDIG
void Fahrstuhl::Drop_Produkt()
{
/* IN MAIN
    pinMode(EN_3, OUTPUT);
    pinMode(DIR_3, OUTPUT);

pwmSetMode (PWM_MODE_BAL);
    pwmSetClock (384);//192                  500Hz
    pwmSetRange (100);//100
*/
    //pwmWrite (STEP_PIN,99);

    digitalWrite (EN_3, LOW);
    digitalWrite (DIR_3, );//WERT FUER AUSFAHREN
    delayMicroseconds (RANGE*MM*STEP);

    digitalWrite(EN_3, HIGH);


    //_______RUNTERFAHREN______________
/*
    pinMode (EN_1, OUTPUT);
    pinMode (DIR_1, OUTPUT);
*/

    digitalWrite (EN_1, LOW);
    digitalWrite (DIR_1, HIGH);                               //RUNTER
    delayMicroseconds (100*MM*STEP*(zeile));

    digitalWrite (EN_1, HIGH);

    //_________________________________


    digitalWrite (EN_3, LOW);
    digitalWrite (DIR_3, );//WERT FUER EINFAHREN
    delayMicroseconds(RANGE*MM*STEP);

    digitalWrite(EN_3,HIGH);

}

/*
//UNVOLLSTAENDIGnar
Fahrstuhl::Stop(bool &active)
{
    // X-KOORDINATE
    for(;;)
    {
*/
/* IN MAIN
        pinMode (EN_1, OUTPUT);
        pinMode (EN_2, OUTPUT);
        pinMode (DIR_1, OUTPUT);
        pinMode (DIR_2, OUTPUT);
*/
/*
        if(active == false)
        {
            break;
        }

        digitalWrite (ENABLEMOTOR1, LOW);
        digitalWrite (DIRPINMOTOR1, HIGH);
        pwmWrite (MOTOR1PIN, 0);

    }
}


//Y-KOORDINATE
for(;;)
{
    if(active == false)
    {
        break;
    }
    digitalWrite (ENABLEMOTOR2, LOW);
    digitalWrite (DIRPINMOTOR2, HIGH);
    pwmWrite (MOTOR2PIN, 0);
}


}
*/


/*
int step_counter(int &x_min, int &x_max, int &y_min, int &y_max, bool &x_sensor_min, bool &x_sensor_max, bool &y_sensor_min, bool &y_sensor_max)
{

    int x_counter = 0;
    int y_counter = 0;
    int state_x = 0;
    int state_y = 0;

    // X-RICHTUNG 0-PUNKT
    if(state_x = 0)
    {
        while (x_sensor_min == 1)                                       //SENSOR NICHT GEDR�CKT
        {
            digitalWrite (ENABLEPINMOTOR1, LOW);
            digitalWrite (DIRPINMOTOR1, LOW);                               //RICHTUNG KOORDINATEN 0-PUNKT
            pwmWrite(MOTOR1PIN, 99);
        }
        if (x_sensor_min = true)                                        //SENSOR GEDRR�CKT
        {
            state_x = 1;
        }
    }

    // Y-RICHTUNG 0-PUNKT
    if(state_y = 0)
    {
        while (y_sensor_min == false)                                    //SENSOR NICHT GEDR�CKT
        {
            digitalWrite (ENABLEPINMOTOR2, LOW);
            digitalWrite (DIRPINMOTOR2, LOW);                                //RICHTUNG KOORDINATEN 0-PUNKT
            pwmWrite(MOTOR1PIN, 99);
        }
        if (y_sensor_min = true)                                         //SENSOR GEDRR�CKT
        {
            state_y = 1;
        }
    }

    // X-RICHTUNG ENDPUNKT
    if(state_x = 1)
    {
        while (x_sensor_max == false)                                        //SENSOR NICHT GEDR�CKT
        {
            digitalWrite (ENABLEPINMOTOR1, LOW);
            digitalWrite (DIRPINMOTOR1, HIGH);                               //RICHTUNG KOORDINATEN END-PUNKT
            pwmWrite(MOTOR1PIN, 99);

            x_counter = x_counter + 1;
        }

    }

    // Y-RICHTUNG ENDPUNKT
    if(state_y = 1)
    {
        while (y_sensor_max == false)                                        //SENSOR NICHT GEDR�CKT
        {
            digitalWrite (ENABLEPINMOTOR1, LOW);
            digitalWrite (DIRPINMOTOR1, HIGH);                               //RICHTUNG KOORDINATEN END-PUNKT
            pwmWrite(MOTOR1PIN, 99);

            y_counter = y_counter + 1;
        }

    }


    x_max = x_counter;                                                  //ZUWEISUNG DER ENDPUNKTE AUF ENDKOORDINATEN
    y_max = y_counter;

}
*/

/*
Fahrstuhl::step_calculator(int x_min, int x_max, int y_min, int y_max, int x_temp, int y_temp, int &steps_x, int &steps_y, int&dir_x, int &dir_y, int x_pos_fach, int y_pos_fach)
{

//X-KOORDINATE____________________________________________

    steps_x = abs(x_temp - x_pos_fach);


    if (x_temp > x_pos_fach)
    {
        dir_x = HIGH;                        //Richtung
    }

    if (x_temp < x_pos_fach)
    {
        dir_x = LOW                  //Richtung
    }


//Y-KOORDINATE __________________________________________

    steps_y = abs(y_temp - y_pos_fach);


    if (y_temp > y_pos_fach)
    {
        dir_y = HIGH;                        //Richtung
    }


    if (y_temp < y_pos_fach)
    {
        dir_y = Low                      //Richtung
    }

}*/
