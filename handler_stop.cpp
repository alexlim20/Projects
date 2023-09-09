#include "fahrstuhl.h"
#include <wiringPi.h>

//y_ZERO
void interruptHandlerButton1(bool &x_sensor_zero)
{
    //pinMode (EN_1, OUTPUT);
    digitalWrite (EN_1, HIGH);                  //AUSSCHALTEN
    x_sensor_zero = true;
}


//x_ZERO
void interruptHandlerButton2(bool &y_sensor_zero)
{
    //pinMode (EN_2, OUTPUT);
    digitalWrite (EN_2, OUTPUT);
    y_sensor_zero=true;
}

//Y_ENDE
void interruptHandlerButton3(bool &x_sensor_end)
{
    //pinMode (EN_1, OUTPUT);
    digitalWrite (EN_1, HIGH);
    x_sensor_end=true;
}


//X_ENDE
void interruptHandlerButton4(bool &y_sensor_end)
{
    pinMode (EN_2, OUTPUT);
    digitalWrite (EN_2, HIGH);
    y_sensor_end=true;
}

//?????
/*void interruptHandlerButton5(void)
{

}*/
