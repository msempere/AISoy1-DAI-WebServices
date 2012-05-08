#include "system.h"


System::System(const Config &c)
{
    host=c.host;
    maxDevices=c.maxNumDevices;
}

System::~System()
{
}

bool System::LoadDevices()
{
    devices.clear();

    string url=host+"home/all/home-devices";
    //string url="/home/miguel/workspace/RestWS/home-devices.xml";
    xmlDocPtr doc;
    doc = xmlParseFile(url.c_str());


    if (doc == NULL){
        std:cerr<<"Error: imposible parsear "+url<<std::endl;
        return false;
    }

    xmlNode *root = NULL;
    root = xmlDocGetRootElement(doc);
    int count=0;

    if( !root || !root->name || xmlStrcmp(root->name,(const xmlChar *)"devices") )
    {
        xmlFreeDoc(doc);
        xmlCleanupParser();
        std::cerr<<"Error: No existe elemento root o problemas con las etiquetas de los devices."<<std::endl;
        return false;
    }

    xmlNode *cur_node, *child_node, *child_func;

    for(cur_node = root->children; cur_node != NULL && count<maxDevices; cur_node = cur_node->next){
        if ( cur_node->type == XML_ELEMENT_NODE  && !xmlStrcmp(cur_node->name, (const xmlChar *) "device" )){

            Device dev;
            dev.setHost(host);

            //para cada propiedad de device
            for(child_node = cur_node->children; child_node != NULL; child_node = child_node->next){
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"id") )
                    dev.setId((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"name") )
                    dev.setName((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"services") )
                    dev.setServices(StringToService((char *)xmlNodeGetContent(child_node)));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"room") )
                    dev.setRoom((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"type") )
                    dev.setType((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"techno") )
                    dev.setTechno((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"locationCoor") )
                    dev.setLocationCoor((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"description") )
                    dev.setDescription((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"typeOfCompo") )
                    dev.setTypeOfCompo((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"functionality") ){


                    Funcionality func;
                    func.setHost(host);

                    //para cada propiedad de un funcionality
                    for(child_func = child_node->children; child_func != NULL; child_func = child_func->next){

                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"name") )
                            func.setName((char *)xmlNodeGetContent(child_func));
                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"description") )
                            func.setDescription((char *)xmlNodeGetContent(child_func));
                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"range") )
                            func.setRange((char *)xmlNodeGetContent(child_func));
                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"inputValue") )
                            func.setInputValue((char *)xmlNodeGetContent(child_func));
                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"returnValue") )
                            func.setReturnValue((char *)xmlNodeGetContent(child_func));

                    }

                    dev.AddFuncionality(func);

                }
            }
            devices.push_back(boost::make_shared<Device>(dev));
        }
        count++;
    }

    //xmlFreeNode(cur_node);
    //xmlFreeNode(child_node);
    //xmlFreeNode(child_func);
    //xmlFreeDoc(doc);
    xmlCleanupParser();

    loaded_devices=true;
    return true;
}

void System::PrintDevices(){

    if(devices.size()==0)
        std::cout<<"Devices vacio. No existen dispositivos o no han sido cargados previamente."<<std::endl;
    else
        for(unsigned int i=0;i<devices.size();i++)
            devices.at(i)->Print();
}

vector<boost::shared_ptr<Device> > System::getDevicesByService(SERVICE service){

    vector<Device_ptr> ret;
    std::vector<Device_ptr>::iterator iter;

    for(iter=devices.begin();iter!=devices.end();++iter)
        if((*iter)->getServices()==service)
            ret.push_back(*iter);
    return ret;
}

int System::atoi(string n){

    const char * str=n.c_str();

	int num = 0;
	unsigned int val = 1, base = 10;

	for (int i = n.size()-1; i >= 0; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			num += (str[i] - '0') * val;
			val *= base;
		}
	}

	return num;
}

Device_ptr System::getDeviceById(int id){

    std::vector<Device_ptr>::iterator iter;

    for(iter=devices.begin();iter!=devices.end();++iter)
        if(atoi((*iter)->getId())==id)
            return (*iter);
}



vector<Device_ptr> System::getDevicesFromRoom(string room){

    vector<Device_ptr> ret;
    std::vector<Device_ptr>::iterator iter;

    for(iter=devices.begin();iter!=devices.end();++iter)
        if((*iter)->getRoom()==room)
            ret.push_back(*iter);

    return ret;
}

bool System::ActivateScene(SCENE scene){
    return activateScene(host,scene);
}
