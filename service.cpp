#include "service.h"

std::string ServiceToString(SERVICE s){
    switch (s) {
        case Alarm: return "Alarm";
        case Blinds: return "Blinds";
        case Lighting: return "Lighting";
        case Meters: return "Meters";
        case Sensing: return "Sensing";
        case Weather: return "Weather";
    }
    return "";
}

SERVICE StringToService(std::string s){
    if(s=="Alarm") return Alarm;
    if(s=="Blinds") return Blinds;
    if(s=="Lighting") return Lighting;
    if(s=="Meters") return Meters;
    if(s=="Sensing") return Sensing;
    if(s=="Weather") return Weather;
    if(s=="Null") return Null;
}

std::ostream& operator<<(std::ostream& os, SERVICE x)
{
    os<<ServiceToString(x);
    return os;
}
