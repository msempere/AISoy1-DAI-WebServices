#ifndef SYSTEM_INCLUDED
#define SYSTEM_INCLUDED

#include <iostream>
#include <string.h>
#include <stdio.h>

#include <libxml2/libxml/xmlexports.h>
#include <libxml2/libxml/xmlversion.h>
#include <libxml2/libxml/xmlreader.h>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <curl/curl.h>
#include <curl/easy.h>

#include "device.h"




using namespace std;

//const string baseUrl="http://shanon.iuii.ua.es/test/home/";
typedef boost::shared_ptr<Device> Device_ptr;


class System
{
private:
    vector<Device_ptr> devices;
    int atoi(string n);

public:
    System();
    ~System();
    void LoadDevices();
    void PrintDevices();
    vector<Device_ptr> GetDevicesByService(SERVICE service);
    vector<Device_ptr> GetDevicesFromRoom(string room);
    Device_ptr GetDeviceById(int id);
};


#endif // SYSTEM_INCLUDED
