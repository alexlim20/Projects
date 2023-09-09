#ifndef FAHRSTUHL_H_INCLUDED
#define FAHRSTUHL_H_INCLUDED


class Fahrstuhl
{
public:

    bool X_sensor_zero, X_sensor_end, Y_sensor_zero, Y_sensor_end, Gabel_sensor;
    //bool active;


    Fahrstuhl(); //Konstruktor

    void Beweg_X(int zeile, int direction);
    void Beweg_Y(int spalte, int direction);
    void ReturnToZero(bool &X_sensor_zero, bool &Y_sensor_zero);
    //void Stop(bool active);
    void Get_Produkt();
    void Drop_Produkt();
    //int step_counter(int X_min, int X_max, int Y_min, int Y_max, bool X_sensor_min, bool X_sensor_max, bool Y_sensor_min, bool Y_sensor_max);
    //int step_calculator(int X_min, int X_max, int Y_min, int Y_max, int X_temp, int Y_temp, bool steps_X, bool steps_Y, bool dir_X, bool dir_Y );
};

#endif // FAHRSTUHL_H_INCLUDED
