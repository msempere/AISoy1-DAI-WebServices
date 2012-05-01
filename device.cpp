#include "device.h"



template <class T>
bool from_string(T& t, const std::string& s, std::ios_base&(*f)(std::ios_base&))
{
    std::istringstream iss(s);
    return !(iss >> f >> t).fail();
}

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

Device::Device(){
    services=Null;
    id=name=room=type=techno=locationCoor=description=typeOfCompo="";
}

Device::~Device(){
}

void Device::Print(){
    std::cout<<"------START DEVICE------"<<std::endl;
    std::cout<<"ID: "<<id<<std::endl;
    std::cout<<"NAME: "<<name<<std::endl;
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
    f.SetIdPadre(t);
    functionalities.push_back(f);
}

Funcionality* Device::GetFuncionality(string name){
    for(int i=0;i<functionalities.size();i++){
        if(functionalities.at(i).GetName()==name){
            return &functionalities.at(i);
        }
    }
}

string Device::GetFuncionalityValue(string f){

    for(int i=0;i<functionalities.size();i++){
        if(functionalities.at(i).GetName()==f){
            return functionalities.at(i).GetValue();
        }
    }
}

bool Device::SetFuncionalityValue(string f, int v){

    for(int i=0;i<functionalities.size();i++){
        if(functionalities.at(i).GetName()==f){
            return functionalities.at(i).SetValue(v);
        }
    }
}

