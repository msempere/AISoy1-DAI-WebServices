#include <iostream>

#include "system.h"

using namespace std;


int main (int argc, const char* argv[])
{
    //System s=Config("http://shanon.iuii.ua.es/test/").maxDevices(1);
    //std::cout<<s.ActivateScene(Bienvenida)<<std::endl;

    System s=Config("http://shanon.iuii.ua.es/test").DevicesURL("/rest/home").ScenesURL("/rest/scenes").TtsURL("/rest/tts");
    s.LoadDevices();
    //s.LoadScenes();
    //s.PrintSceneces();
    //std::cout<<s.ActivateScene("bienvenida")<<std::endl;
    //s.PrintDevices();
    s.RealizarAccion(std::string("subir"),std::string("regulador"),std::string("salon"));


    //std::cout<<s.getDeviceById(33)->getName()<<std::endl;
    //std::cout<<s.getDeviceById(33)->getFuncionality("dataKwh")->getValue()<<std::endl;
    //std::cout<<(*s.getDeviceById(33)).getFuncionality("dataKwh")->getValue()<<std::endl;
    //std::cout<<s.getDeviceById(33)->getFuncionality("dataKwh")->getValue()<<std::endl;
    //std::cout<<s.getDeviceById(32)->setFuncionalityValue("moveBlind",0)<<std::endl;
    //std::cout<<s.getDeviceById(32)->getFuncionality("moveBlind")->setValue(0)<<std::endl;
    //std::cout<<s.getDeviceById(32)->getFuncionality("moveBlind")->toggle()<<std::endl;
    //std::cout<<s.getDeviceById(32)->getFuncionality("moveBlind")->getValue()<<std::endl;
    //s.PrintDevices();

    //std::cout<<s.getDeviceById(28)->getFuncionality("dataTemp")->getName()<<std::endl;
    //std::cout<<s.getDeviceById(28)->getFuncionality("dataTemp")->getRange().first<<std::endl;
    //std::cout<<s.getDeviceById(1)->getFuncionality("dimmer")->getValue()<<std::endl;
    //std::cout<<s.getDeviceById(1)->getFuncionality("dimmer")->setValue(5)<<std::endl;
    //std::cout<<s.getDeviceById(1)->getFuncionality("dimmer")->getValue()<<std::endl;


    //std::cout<<s.getDeviceById(33)->getName()<<std::endl;

    /*
    vector<Device_ptr> ret=s.getDevicesFromRoom("Sittingroom");
    std::vector<Device_ptr>::iterator iter;

    for(iter=ret.begin();iter!=ret.end();++iter)
        cout<<(*iter)->getName()<<endl;
    */


    /*
    vector<Device_ptr> v=s.getDevicesByService(Blinds);

    for(unsigned int i=0;i<v.size();i++)
        std::cout<<v.at(i)->getName()<<std::endl;
    */

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


