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

typedef enum{
    Bienvenida=1,
    Salida,
    Cine,
    Lectura,
    Noche,
    Despertar,
    Iluminacion_media,
    Iluminacion_maxima
} SCENE;

const string activate_scene_url="scenes/enable/";

bool activateScene(string host,SCENE scene);

#endif // SCENE_H
