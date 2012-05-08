#ifndef SERVICE_H
#define SERVICE_H



#include <iostream>
#include <string>

typedef enum{
    Alarm=1,
    Blinds,
    Lighting,
    Meters,
    Sensing,
    Weather,
    Null
} SERVICE;

std::string ServiceToString(SERVICE s);
SERVICE StringToService(std::string s);
std::ostream& operator<<(std::ostream& os, SERVICE x);


#endif // SERVICE_H
