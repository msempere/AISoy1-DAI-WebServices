#ifndef FUNCTIONALITY_H_INCLUDED
#define FUNCTIONALITY_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <utility>

#include <libxml2/libxml/xmlexports.h>
#include <libxml2/libxml/xmlversion.h>
#include <libxml2/libxml/xmlreader.h>

using namespace std;

//const string baseUrl="http://shanon.iuii.ua.es/test/home/";

class Funcionality
{
private:
    string host;
    string devicesURL;
    int id_padre;
    string name;
    string description;
    string range;
    string inputValue;
    string returnValue;
    int min_range;
    int max_range;
    std::vector<std::string> & split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);
    bool getResponse(string url);

public:
    Funcionality();
    ~Funcionality();
    Funcionality(string _name,string _description, string _range, string _inputValue, string _returnValue);
    void setName(string _name){name=_name;};
    void setDescription(string _description){description=_description;};
    void setRange(string _range);
    void setInputValue(string _inputValue){inputValue=_inputValue;};
    void setReturnValue(string _returnValue){returnValue=_returnValue;};
    void setIdPadre(int id){id_padre=id;};
    void setHost(string h){host=h;};
    void setDevicesURL(string h){devicesURL=h;};

    string getName(){return name;};
    string getDescription(){return description;};
    string getInputValue(){return inputValue;};
    string getReturnValue(){return returnValue;};
    pair<int,int> getRange();

    string getValue();
    bool setValue(int new_value);
    bool toggle();

    void Print();
};


#endif // FUNCTIONALITY_H_INCLUDED

