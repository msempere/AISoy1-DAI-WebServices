#ifndef UTILS
#define UTILS


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


namespace Util{

    static std::string getGeneratedGrammar(){

        std::string dev(" ");

        dev.append("exterior").append(" | ");

        return dev;
    }

    static std::string getSpanishName(std::string name){

        //HABITACIONES
        if(name.compare("Exterior")==0)
            return "exterior";
        if(name.compare("LightsPanel")==0)
            return "panel de luces";
        if(name.compare("Maletin")==0)
            return "maletin";
        if(name.compare("Sittingroom")==0)
            return "salon";
        if(name.compare("Workplace")==0)
            return "estudio";

        //SERVICIOS
        if(name.compare("Alarm")==0)
            return "alarma";
        if(name.compare("Blinds")==0)
            return "persianas";
        if(name.compare("Lighting")==0)
            return "iluminacion";
        if(name.compare("Meters")==0)
            return "medicion";
        if(name.compare("Sensing")==0)
            return "sensorizacion";
        if(name.compare("Weather")==0)
            return "tiempo";

        //DEVICES
        if(name.compare("Panel 1")==0)
            return "panel uno";
        if(name.compare("Panel 2")==0)
            return "panel dos";
        if(name.compare("Panel 3")==0)
            return "panel tres";
        if(name.compare("Panel 4")==0)
            return "panel cuatro";
        if(name.compare("Panel Todos")==0)
            return "panel todos";
        if(name.compare("Tubo led")==0)
            return "tubo led";
        if(name.compare("Tubo bajo consumo")==0)
            return "tubo bajo consumo";
        if(name.compare("Tubo normal")==0)
            return "tubo normal";
        if(name.compare("Downlight 13w")==0)
            return "luz baja";
        if(name.compare("Downlight led")==0)
            return "luz baja led";
        if(name.compare("Dicroica led")==0)
            return "dicroica led";
        if(name.compare("Dicroica bajo consumo")==0)
            return "dicroica bajo consumo";
        if(name.compare("Dicroica")==0)
            return "dicroica";
        if(name.compare("Incandescente spot bajo consumo")==0)
            return "incandescente bajo consumo";
        if(name.compare("Incandescente spot")==0)
            return "incandescente";
        if(name.compare("Energymeter1")==0)
            return "medidor energia uno";
        if(name.compare("Luz 1")==0)
            return "luz uno";
        if(name.compare("Luz 2")==0)
            return "luz dos";
        if(name.compare("Luz 3")==0)
            return "luz tres";
        if(name.compare("Luz 4")==0)
            return "luz cuatro";
        if(name.compare("Luz 5")==0)
            return "luz cinco";
        if(name.compare("HumiditySensorIndoor")==0)
            return "sensor humedad interior";
        if(name.compare("HumiditySensorOutdoor")==0)
            return "sensor humedad exterior";
        if(name.compare("PresenceSensor2")==0)
            return "sensor presencia dos";
        if(name.compare("PresenceSensor3")==0)
            return "sensor presencia tres";
        if(name.compare("TemperatureSensorIndoor")==0)
            return "sensor temperatura interior";
        if(name.compare("Luminaria1")==0)
            return "luminaria uno";
        if(name.compare("Luminaria2")==0)
            return "luminaria dos";
        if(name.compare("Blind1")==0)
            return "persiana uno";
        if(name.compare("Blind2")==0)
            return "persiana dos";
        if(name.compare("Lampara 1")==0)
            return "lampara uno";
        if(name.compare("Lampara 2")==0)
            return "lampara dos";
        if(name.compare("Tira Led RGB")==0)
            return "tira led";
        if(name.compare("LuxesPresencia2")==0)
            return "sensor presencia lux dos";
        if(name.compare("Manubrio")==0)
            return "manubrio";
        if(name.compare("TemperatureSensorWallIndoor")==0)
            return "sensor temperatura suelo interior";

        //FUNCIONALIDADES
        if(name.compare("dataDimmerBlue")==0)
            return "lector regulador azul";
        if(name.compare("dataDimmerGreen")==0)
            return "lector regulador verde";
        if(name.compare("dataDimmerRed")==0)
            return "lector regulador rojo";
        if(name.compare("dimmer")==0)
            return "regulador";
        if(name.compare("dimmerBlue")==0)
            return "regulador azul";
        if(name.compare("dimmerGreen")==0)
            return "regulador verde";
        if(name.compare("dimmerRed")==0)
            return "regulador rojo";
        if(name.compare("switch")==0)
            return "interruptor";
        if(name.compare("dataSwitch")==0)
            return "lector interruptor";
        if(name.compare("dataActivePower")==0)
            return "lector potencia activa";
        if(name.compare("dataApparentPower")==0)
            return "lector potencia aparente";
        if(name.compare("dataIntensity")==0)
            return "lector intensidad";
        if(name.compare("dataKwh")==0)
            return "lector de vatios";
        if(name.compare("dataVoltage")==0)
            return "lector voltage";
        if(name.compare("dataHumidity")==0)
            return "lector humedad";
        if(name.compare("dataSensor")==0)
            return "lector sensor";
        if(name.compare("dataTemp")==0)
            return "lector temperatura";
        if(name.compare("moveBlind")==0)
            return "mover persiana";

        //ESCENAS
        if(name.compare("bienvenida")==0)
            return "bienvenida";
        if(name.compare("intensidad-maxima")==0)
            return "intensidad maxima";
        if(name.compare("noche")==0)
            return "noche";
        if(name.compare("intensidad-media")==0)
            return "intensidad media";
        if(name.compare("salir")==0)
            return "salir";
        if(name.compare("despertar")==0)
            return "despertar";
        if(name.compare("subir-persianas")==0)
            return "subir persianas";
        else
            return "no reconocido";
    }
}

#endif


