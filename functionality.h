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

const string baseUrl="http://shanon.iuii.ua.es/test/home/";

class Funcionality
{
private:
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
public:
    Funcionality();
    ~Funcionality();
    Funcionality(string _name,string _description, string _range, string _inputValue, string _returnValue);
    void SetName(string _name){name=_name;};
    void SetDescription(string _description){description=_description;};
    void SetRange(string _range);
    void SetInputValue(string _inputValue){inputValue=_inputValue;};
    void SetReturnValue(string _returnValue){returnValue=_returnValue;};
    void SetIdPadre(int id){id_padre=id;};

    string GetName(){return name;};
    string GetDescription(){return description;};
    string GetInputValue(){return inputValue;};
    string GetReturnValue(){return returnValue;};
    pair<int,int> GetRange();

    string GetValue();
    bool SetValue(int new_value);

    void Print();
};


#endif // FUNCTIONALITY_H_INCLUDED

