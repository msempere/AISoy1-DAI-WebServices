#ifndef DEVICE_H_INCLUDED
#define DEVICE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "functionality.h"
#include "service.h"

using namespace std;



class Device
{
private:
    string id;
    string name;
    SERVICE services;
    string room;
    string type;
    string techno;
    string locationCoor;
    string description;
    string typeOfCompo;
    vector<Funcionality> functionalities;
    SERVICE GetServiceFromString(string s);
public:
    Device();
    ~Device();
    Device(string _id,string _name, string _service, string _room, string _type, string _techno, string _locationCoor, string _description, string _typeOfCompo);
    void SetId(string _id){id=_id;};
    void SetName(string _name){name=_name;};
    void SetServices(SERVICE _services){services=_services;};
    void SetRoom(string _room){room=_room;};
    void SetType(string _type){type=_type;};
    void SetTechno(string _techno){techno=_techno;};
    void SetLocationCoor(string _locationCoor){locationCoor=_locationCoor;};
    void SetDescription(string _description){description=_description;};
    void SetTypeOfCompo(string _typeOfCompo){typeOfCompo=_typeOfCompo;};


    string GetId(){return id;};
    SERVICE GetServices(){return services;};
    string GetName(){return name;};
    string GetRoom(){return room;};
    string GetFuncionalityValue(string f);
    Funcionality* GetFuncionality(string name);

    bool SetFuncionalityValue(string f, int v);

    void AddFuncionality(Funcionality f);
    void Print();
};

#endif // DEVICE_H_INCLUDED
