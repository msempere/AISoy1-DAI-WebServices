#include "scene.h"

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

bool activateScene(string host,SCENE scene){

    string url=host+activate_scene_url+to_string<int>(scene);
    bool dev=false;

    xmlDocPtr doc;
    doc = xmlParseFile(url.c_str());


    if (doc == NULL)
    {
std:
        cerr<<"Error: imposible parsear "+url<<std::endl;
        exit(-1);
    }

    xmlNode *root = NULL;
    root = xmlDocGetRootElement(doc);
    string string_temp="";

    if( !root || !root->name || xmlStrcmp(root->name,(const xmlChar *)"response") )
    {
        xmlFreeDoc(doc);
        std::cerr<<"Error: No existe elemento root o problemas con la etiqueta de respuesta de scenes."<<std::endl;
        exit(-1);
    }

    xmlNode *cur_node, *child_node, *child_func;
    bool encontrado=false;

    for(cur_node = root->children; cur_node != NULL; cur_node = cur_node->next)
    {
        if ( cur_node->type == XML_ELEMENT_NODE  && !xmlStrcmp(cur_node->name, (const xmlChar *) "value" ))
        {

            if(xmlHasProp(cur_node,(const xmlChar *) "type"))
            {
                if(strcmp((char *)xmlGetProp(cur_node,(xmlChar *)"type"),"error")==0)
                {
                }
                else
                {
                    string_temp=(char *)xmlNodeGetContent(cur_node);

                    if(string_temp=="true")
                        dev=true;
                }

            }

        }
    }

    //xmlFreeNode(cur_node);
    //xmlFreeNode(child_node);
    //xmlFreeNode(root);
    //xmlFreeNode(child_func);
    xmlFreeDoc(doc);
    xmlCleanupParser();


    return dev;
}