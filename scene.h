#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <sstream>
#include <string.h>
#include <string>

#include <libxml2/libxml/xmlexports.h>
#include <libxml2/libxml/xmlversion.h>
#include <libxml2/libxml/xmlreader.h>

#include <boost/algorithm/string/replace.hpp>

#include "utils.h"

using namespace std;

struct SceneElement{
    string name;
    string spanishName;
    string parsedName;
    string description;
};

class Scene{
    public:
        Scene();
        bool activate();
        string getDescription(){return scene.description;};
        string getName(){return scene.name;};
        string getSpanishName(){return scene.spanishName;};
        string getParsedName(){return scene.parsedName;};
        void setName(string name){scene.name=name; scene.spanishName=Util::getSpanishName(name); scene.parsedName=boost::replace_all_copy(name, "-", " ");};
        void setDescription(string description){scene.description=description;};
        void setScenesURL(string url){scenesURL=url;};
        void setHost(string url){host=url;};
        void Print();

    private:
        SceneElement scene;
        string host;
        string scenesURL;
        bool getResponse(string url);
};
#endif // SCENE_H
