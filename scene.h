#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <sstream>
#include <string.h>
#include <string>

#include <libxml2/libxml/xmlexports.h>
#include <libxml2/libxml/xmlversion.h>
#include <libxml2/libxml/xmlreader.h>

using namespace std;

struct SceneElement{
    string name;
    string description;
};

class Scene{
    public:
        Scene();
        bool activate();
        string getDescription(){return scene.description;};
        string getName(){return scene.name;};
        void setName(string name){scene.name=name;};
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
