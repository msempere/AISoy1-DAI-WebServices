#include "system.h"


System::System()
{
}

System::~System()
{
}

void System::LoadDevices()
{
    string url=baseUrl+"all/home-devices";
    //string url="/home/miguel/workspace/RestWS/home-devices.xml";
    xmlDocPtr doc;
    doc = xmlParseFile(url.c_str());


    if (doc == NULL){
        std:cerr<<"Error: imposible parsear "+url<<std::endl;
        exit(-1);
    }

    xmlNode *root = NULL;
    root = xmlDocGetRootElement(doc);

    if( !root || !root->name || xmlStrcmp(root->name,(const xmlChar *)"devices") )
    {
        xmlFreeDoc(doc);
        xmlCleanupParser();
        std::cerr<<"Error: No existe elemento root o problemas con las etiquetas de los devices."<<std::endl;
        exit(-1);
    }

    xmlNode *cur_node, *child_node, *child_func;

    for(cur_node = root->children; cur_node != NULL; cur_node = cur_node->next){
        if ( cur_node->type == XML_ELEMENT_NODE  && !xmlStrcmp(cur_node->name, (const xmlChar *) "device" )){

            Device dev;

            //para cada propiedad de device
            for(child_node = cur_node->children; child_node != NULL; child_node = child_node->next){
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"id") )
                    dev.SetId((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"name") )
                    dev.SetName((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"services") )
                    dev.SetServices(StringToService((char *)xmlNodeGetContent(child_node)));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"room") )
                    dev.SetRoom((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"type") )
                    dev.SetType((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"techno") )
                    dev.SetTechno((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"locationCoor") )
                    dev.SetLocationCoor((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"description") )
                    dev.SetDescription((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"typeOfCompo") )
                    dev.SetTypeOfCompo((char *)xmlNodeGetContent(child_node));
                if(cur_node->type == XML_ELEMENT_NODE && !xmlStrcmp(child_node->name, (const xmlChar *)"functionality") ){


                    Funcionality func;

                    //para cada propiedad de un funcionality
                    for(child_func = child_node->children; child_func != NULL; child_func = child_func->next){

                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"name") )
                            func.SetName((char *)xmlNodeGetContent(child_func));
                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"description") )
                            func.SetDescription((char *)xmlNodeGetContent(child_func));
                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"range") )
                            func.SetRange((char *)xmlNodeGetContent(child_func));
                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"inputValue") )
                            func.SetInputValue((char *)xmlNodeGetContent(child_func));
                        if(child_func->type == XML_ELEMENT_NODE && !xmlStrcmp(child_func->name, (const xmlChar *)"returnValue") )
                            func.SetReturnValue((char *)xmlNodeGetContent(child_func));

                    }

                    dev.AddFuncionality(func);

                }
            }
            devices.push_back(boost::make_shared<Device>(dev));
        }
    }

    xmlFreeNode(cur_node);
    xmlFreeNode(child_node);
    xmlFreeNode(child_func);
    xmlFreeDoc(doc);
    xmlCleanupParser();

}

void System::PrintDevices(){

    if(devices.size()==0)
        std::cout<<"Devices vacio. No existen dispositivos o no han sido cargados previamente."<<std::endl;
    else
        for(unsigned int i=0;i<devices.size();i++)
            devices.at(i)->Print();
}

vector<boost::shared_ptr<Device> > System::GetDevicesByService(SERVICE service){

    vector<Device_ptr> ret;
    std::vector<Device_ptr>::iterator iter;

    for(iter=devices.begin();iter!=devices.end();++iter)
        if((*iter)->GetServices()==service)
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

Device_ptr System::GetDeviceById(int id){

    std::vector<Device_ptr>::iterator iter;

    for(iter=devices.begin();iter!=devices.end();++iter)
        if(atoi((*iter)->GetId())==id)
            return (*iter);
}



vector<Device_ptr> System::GetDevicesFromRoom(string room){

    vector<Device_ptr> ret;
    std::vector<Device_ptr>::iterator iter;

    for(iter=devices.begin();iter!=devices.end();++iter)
        if((*iter)->GetRoom()==room)
            ret.push_back(*iter);

    return ret;
}

