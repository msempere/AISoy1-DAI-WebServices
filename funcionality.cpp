#include "functionality.h"


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

Funcionality::Funcionality()
{
    name=description=range=inputValue=returnValue="";
}

Funcionality::~Funcionality()
{
}

void Funcionality::Print()
{

    std::cout<<"\tNAME: "+name<<std::endl;
    std::cout<<"\tDECRIPTION: "+description<<std::endl;
    std::cout<<"\tRANGE: "+range<<std::endl;
    std::cout<<"\tINPUTVALUE: "+inputValue<<std::endl;
    std::cout<<"\tRETURNVALUE: "+returnValue<<std::endl;

}


bool Funcionality::getResponse(string url){

    xmlDocPtr doc;
    bool dev=false;
    doc = xmlParseFile(url.c_str());


    if (doc == NULL)
    {
        std:cerr<<"Error: imposible parsear "+url<<std::endl;
        exit(-1);
    }

    xmlNode *root = NULL;
    root = xmlDocGetRootElement(doc);

    if( !root || !root->name || xmlStrcmp(root->name,(const xmlChar *)"response") )
    {
        xmlFreeDoc(doc);
        xmlCleanupParser();
        std::cerr<<"Error: No existe elemento root o problemas con la etiqueta de respuesta."<<std::endl;
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
                    dev=false;
                }
                else
                {
                    if(strcmp((char *)xmlGetProp(cur_node,(xmlChar *)"type"),"bool")==0)
                        if(strcmp((char *)xmlNodeGetContent(cur_node),"true")==0)
                            dev=true;

                }

            }

        }
    }
    return dev;
}

bool Funcionality::toggle(){

    string url=host+devicesURL+"/device/"+to_string<int>(id_padre)+"/toggle/"+getName();
    return getResponse(url);
}


bool Funcionality::setValue(int new_value)
{
    string url=host+devicesURL+"/device/"+to_string<int>(id_padre)+"/write/"+getName()+"/"+to_string<int>(new_value);
    return getResponse(url);
}

std::vector<std::string> & Funcionality::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> Funcionality::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    return split(s, delim, elems);
}


void Funcionality::setRange(string _range)
{
    range=_range;
    vector<std::string> x = split(_range, '#');

    if(x.size()==2)
    {

        if(!from_string<int>(min_range,x.at(0),std::dec))
            min_range=0;
        if(!from_string<int>(max_range,x.at(1),std::dec))
            max_range=0;

    }
    else
        min_range=max_range=0;
}


pair<int,int> Funcionality::getRange()
{
    pair<int,int> ret;
    ret.first=min_range;
    ret.second=max_range;
    return ret;
}


string Funcionality::getValue()
{

    string url=host+devicesURL+"/device/"+to_string<int>(id_padre)+"/read/"+getName();
    string dev="";

    xmlDocPtr doc;
    doc = xmlParseFile(url.c_str());


    if (doc == NULL)
    {
        std::cerr<<"Error: imposible parsear "+url<<std::endl;
        exit(-1);
    }

    xmlNode *root = NULL;
    root = xmlDocGetRootElement(doc);


    if( !root || !root->name || xmlStrcmp(root->name,(const xmlChar *)"response") )
    {
        xmlFreeDoc(doc);
        std::cerr<<"Error: No existe elemento root o problemas con la etiqueta de respuesta."<<std::endl;
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
                    dev="Error.";
                }
                else
                {
                    dev=(char *)xmlNodeGetContent(cur_node);
                }

            }

        }
    }

    //xmlFreeNode(cur_node);
    //xmlFreeNode(child_node);
    //xmlFreeNode(root);
    //xmlFreeNode(child_func);
    //xmlFreeDoc(doc);
    xmlCleanupParser();
    return dev;
}

