#include "device.h"


Device::Device(){
    services=Null;
    id=name=room=type=techno=locationCoor=description=typeOfCompo="";
}

Device::~Device(){
}

void Device::Print(){
    std::cout<<"------START DEVICE------"<<std::endl;
    std::cout<<"ID: "<<id<<std::endl;
    std::cout<<"NAME: "<<name<<" || "<<spanishName<<std::endl;
    std::cout<<"SERVICES: "<<services<<std::endl;
    std::cout<<"ROOM: "<<room<<std::endl;
    std::cout<<"TYPE: "<<type<<std::endl;
    std::cout<<"TECHNO: "<<techno<<std::endl;
    std::cout<<"LOCATIONCOOR: "<<locationCoor<<std::endl;
    std::cout<<"DESCRIPTION: "<<description<<std::endl;
    std::cout<<"TYPEOFCOMPO: "<<typeOfCompo<<std::endl;

    std::cout<<"\t------START FUNCIONALITIES------"<<std::endl
    ;
    for(unsigned int i=0;i<functionalities.size();i++)
        functionalities.at(i).Print();

    std::cout<<"\t------END FUNCIONALITIES------"<<std::endl;


    std::cout<<"------END DEVICE------"<<std::endl;
}

void Device::AddFuncionality(Funcionality  f){
    int t;
    from_string<int>(t,id,std::dec);
    f.setIdPadre(t);
    functionalities.push_back(f);
}

Funcionality* Device::getFuncionality(string name){
    for(int i=0;i<functionalities.size();i++){
        if(functionalities.at(i).getName()==name){
            return &functionalities.at(i);
        }
    }
}

Funcionality* Device::getFuncionality_ES(string name){
    for(int i=0;i<functionalities.size();i++){
        if(functionalities.at(i).getSpanishName()==name){
            return &functionalities.at(i);
        }
    }
}

string Device::getFuncionalityValue(string f){

    for(int i=0;i<functionalities.size();i++){
        if(functionalities.at(i).getName()==f){
            return functionalities.at(i).getValue();
        }
    }
}

bool Device::setFuncionalityValue(string f, int v){

    for(int i=0;i<functionalities.size();i++){
        if(functionalities.at(i).getName()==f){
            return functionalities.at(i).setValue(v);
        }
    }
}

