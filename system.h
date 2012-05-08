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




using namespace std;

//const string baseUrl="http://shanon.iuii.ua.es/test/home/";
typedef boost::shared_ptr<Device> Device_ptr;

class Config;

class System
{
private:
    vector<Device_ptr> devices;
    int atoi(string n);
    int maxDevices;
    string host;
    bool loaded_devices;

public:
    System(const Config &c);
    ~System();
    bool LoadDevices();
    void PrintDevices();
    vector<Device_ptr> getDevicesByService(SERVICE service);
    vector<Device_ptr> getDevicesFromRoom(string room);
    Device_ptr getDeviceById(int id);
    bool ActivateScene(SCENE scene);
};

class Config
{
    private:
        friend class System;
        string host;
        int maxNumDevices;

    public:
        Config(string _host){host=_host; maxNumDevices=INT_MAX;};
        Config &maxDevices(int max){maxNumDevices=max; return *this;}



};


#endif // SYSTEM_INCLUDED
