#include <iostream>

#include "system.h"

using namespace std;


int main (int argc, const char* argv[])
{
    System s;
    s.LoadDevices();
    //std::cout<<s.GetDeviceById(33)->GetName()<<std::endl;
    //std::cout<<s.GetDeviceById(33)->GetFuncionalityValue("dataKwh")<<std::endl;
    //std::cout<<s.GetDeviceById(33)->GetFuncionality("dataKwh")->GetValue()<<std::endl;
    //std::cout<<s.GetDeviceById(32)->SetFuncionalityValue("moveBlind",0)<<std::endl;
    //std::cout<<s.GetDeviceById(32)->GetFuncionality("moveBlind")->GetValue()<<std::endl;
    //s.PrintDevices();

    //std::cout<<s.GetDeviceById(28)->GetFuncionality("dataTemp")->GetName()<<std::endl;
    //std::cout<<s.GetDeviceById(28)->GetFuncionality("dataTemp")->GetRange().first<<std::endl;
    //std::cout<<s.GetDeviceById(1)->GetFuncionality("dimmer")->GetValue()<<std::endl;
    //std::cout<<s.GetDeviceById(1)->GetFuncionality("dimmer")->SetValue(5)<<std::endl;
    //std::cout<<s.GetDeviceById(1)->GetFuncionality("dimmer")->GetValue()<<std::endl;


    //std::cout<<s.GetDeviceById(33)->GetName()<<std::endl;

    vector<Device_ptr> v=s.GetDevicesByService(Blinds);

    for(unsigned int i=0;i<v.size();i++)
        std::cout<<v.at(i)->GetName()<<std::endl;


    /*
    SERVICES:
    ---------
    Meters
    Blinds
    Lighting
    Weather
    Sensing



    TYPES:
    ------
    Energymeter
    Blind
    BinaryLighting
    TempSensor
    MotionSensor
    WeatherStation
    DimmingLighting
    */

    return 0;
}


