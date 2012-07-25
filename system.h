#ifndef SYSTEM_INCLUDED
#define SYSTEM_INCLUDED

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include <libxml2/libxml/xmlexports.h>
#include <libxml2/libxml/xmlversion.h>
#include <libxml2/libxml/xmlreader.h>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <curl/curl.h>
#include <curl/easy.h>

#include "device.h"
#include "scene.h"
#include "accion.h"




using namespace std;

//const string baseUrl="http://shanon.iuii.ua.es/test/home/";
typedef boost::shared_ptr<Device> Device_ptr;
typedef boost::shared_ptr<Scene> Scene_ptr;

class Config;

class System
{
private:
    vector<Device_ptr> devices;
    vector<Scene_ptr> scenes;
    int atoi(string n);
    int maxDevices;
    string host;
    string devicesURL;
    string scenesURL;
    string ttsURL;
    bool loaded_devices;
    bool loaded_scenes;

public:
    System(const Config &c);
    ~System();
    bool LoadDevices();
    bool LoadScenes();
    void PrintDevices();
    void PrintSceneces();
    vector<Device_ptr> getDevicesByService(SERVICE service);
    vector<Device_ptr> getDevicesFromRoom(string room);
    Device_ptr getDeviceById(int id);
    bool ActivateScene(string scene);
    void RealizarAccion(string accion,string funcionalidad, string habitacion);
};

class Config
{
    private:
        friend class System;
        string host;
        string devicesURL;
        string scenesURL;
        string ttsURL;
        int maxNumDevices;

    public:
        Config(string _host){host=_host; maxNumDevices=INT_MAX;};
        Config &MaxDevices(int max){maxNumDevices=max; return *this;}
        Config &DevicesURL(string url){devicesURL=url; return *this;}
        Config &ScenesURL(string url){scenesURL=url; return *this;}
        Config &TtsURL(string url){ttsURL=url; return *this;}



};


#endif // SYSTEM_INCLUDED
