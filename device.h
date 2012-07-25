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
    string host;
    string id;
    string name;
    string spanishName;
    SERVICE services;
    string room;
    string type;
    string techno;
    string locationCoor;
    string description;
    string typeOfCompo;
    vector<Funcionality> functionalities;
    SERVICE getServiceFromString(string s);
public:
    Device();
    ~Device();
    Device(string _id,string _name, string _service, string _room, string _type, string _techno, string _locationCoor, string _description, string _typeOfCompo);
    void setId(string _id){id=_id;};
    void setName(string _name){name=_name; spanishName=Util::getSpanishName(_name);};
    void setServices(SERVICE _services){services=_services;};
    void setRoom(string _room){room=_room;};
    void setType(string _type){type=_type;};
    void setTechno(string _techno){techno=_techno;};
    void setLocationCoor(string _locationCoor){locationCoor=_locationCoor;};
    void setDescription(string _description){description=_description;};
    void setTypeOfCompo(string _typeOfCompo){typeOfCompo=_typeOfCompo;};
    void setHost(string h){host=h;};


    string getId(){return id;};
    SERVICE getServices(){return services;};
    string getName(){return name;};
    string getRoom(){return room;};
    string getRoom_ES(){return Util::getSpanishName(room);};
    string getFuncionalityValue(string f);
    Funcionality* getFuncionality(string name);
    Funcionality* getFuncionality_ES(string name);

    bool setFuncionalityValue(string f, int v);

    void AddFuncionality(Funcionality f);
    void Print();
};

#endif // DEVICE_H_INCLUDED
