//
// Created by semelion on 6/2/23.
//
#include "course_work.hpp"

generator::generator(std::string json_src_file = "src/config.json", std::string type_of_mk = "ESP32", std::string out_code_file = "smart_house_mqtt.ino",
                     std::string start_of_code_src_file = "src/start_of_code.txt", std::string functions_src_file = "src/function.txt") {
    esp_code.open (out_code_file);
    start_file.open(start_of_code_src_file);
    functions.open(functions_src_file);
    config_file.open(json_src_file);
    config = nlohmann::json::parse(config_file);

    if(type_of_mk == "ESP32")
        pins = {23, 22, 21, 19, 18, 5, 17, 16, 4, 2, 15, 34, 35, 32,33, 25, 26, 27, 14, 12, 13};
    else if(type_of_mk == "ESP8266" || type_of_mk == "ESP-12S" || type_of_mk == "WeMos D1 mini" ||
            type_of_mk == "ESP-12E" || type_of_mk == "ESP-12F" || type_of_mk == "Mini-S1")
        pins = {16, 5, 4, 0, 2, 14, 12, 13, 15, 3, 1, 10, 9};
    else if(type_of_mk == "ESP-01")
        pins = {16, 5, 4, 0, 2, 14, 12, 13, 15, 3, 1, 10, 9};
    else if(type_of_mk == "ESP-07")
        pins = {5, 4, 0, 1, 15, 16, 14, 12, 13};
    else if(type_of_mk == "ESP-07")
        pins = {5, 4, 0, 1, 15, 16, 14, 12, 13};
    else{
        std::cerr << "Wrong count of pins, esp has fewer pins" << std::endl;
    }
}
///////////////////////////////////////////////////////////////
bool generator::check_pins(){
    if(pins.size() >= config["button"].size() + config["relay"].size())
        return true;
    else{
        std::cerr << "Wrong count of pins, esp has fewer pins" << std::endl;
        return false;
    }
}
///////////////////////////////////////////////////////////////
bool generator::generate_notes() {
    if (esp_code.is_open() && start_file.is_open()) {
        std::string line;
        while (std::getline(start_file, line)) {
            esp_code << line << '\n';
        }
        esp_code << "\n";
        return true;
    } else{
        std::cerr << "Exception opening/reading file" << std::endl;
        return false;
    }
}
///////////////////////////////////////////////////////////////
bool generator::generate_defines() {
    if (esp_code.is_open() && config_file.is_open()) {
        esp_code << "#define WIFI_SSID\t" << config["wifi"]["ssid"] << std::endl;
        esp_code << "#define WIFI_PW\t" << config["wifi"]["pasword"] << std::endl;
        esp_code << "#define MQTT_BROKER\t" << config["mqtt_broker"]["MQTT_BROKER"] << std::endl;

        esp_code << "#define MQTT_PORT\t";
        std::string s = config["mqtt_broker"]["MQTT_PORT"];
        esp_code << s << std::endl;
        std::string trimmed = s.substr(1, s.length()-1);
        esp_code << "#define MQTT_NAME_OF_DEVICE\t" << config["mqtt_broker"]["MQTT_NAME_OF_DEVICE"] << std::endl;
        esp_code << "#define MQTT_LOGIN\t" << config["mqtt_broker"]["MQTT_LOGIN"] << std::endl;
        esp_code << "#define MQTT_PW\t" << config["mqtt_broker"]["MQTT_PW"] << "\n" << std::endl;


        for (int i = 0; i < config["button"].size(); i++) {
            std::string s = config["button"].at(i)["name"];
            std::string trimmed = s.substr(1, s.length() - 1);
            esp_code << "#define " << s << "\t" << pins[i] << "\n";
            count_used_pins++;
            std::string temp = config["button"].at(i)["topic"];
            topics.insert(temp);
        }

        for (int i = 0; i < config["relay"].size(); i++) {
            std::string s = config["relay"].at(i)["name"];
            std::string trimmed = s.substr(1, s.length() - 1);
            esp_code << "#define " << s << "\t" << pins[i + count_used_pins] << "\n";
            std::string temp = config["relay"].at(i)["topic"];
            topics.insert(temp);
        }

        esp_code << "\nWiFiClient espClient;\n";
        esp_code << "PubSubClient client(espClient);\n\n";

        it = topics.begin();
        for (int i = 1; it != topics.end(); i++, it++) {
            esp_code << "bool state_topic_" << *it << " = 0;\n";
        }
        esp_code << std::endl;
        return true;
    } else{
        std::cerr << "Exception opening/reading file" << std::endl;
        return false;
    }
}
///////////////////////////////////////////////////////////////
bool generator::generate_setup() {
    if (esp_code.is_open() && config_file.is_open()) {
        esp_code << "void setup() {\n";
        esp_code << "\tSerial.begin(" << config["Serial_speed"] << ");\n\n";

        for(int i = 0; i < config["button"].size(); i++){
            std::string s = config["button"].at(i)["name"];
            std::string trimmed = s.substr(1, s.length()-1);
            esp_code << "\tpinMode(" << s << ", INPUT);\n";
        }

        for(int i = 0; i < config["relay"].size(); i++){
            std::string s = config["relay"].at(i)["name"];
            s.substr(1, s.length()-1);
            esp_code << "\tpinMode(" << s << ", OUTPUT);\n";
        }
        esp_code << "\n\tconnect();\n";

        esp_code << "}\n";
        return true;
    } else{
        std::cerr << "Exception opening/reading file" << std::endl;
        return false;
    }
}
///////////////////////////////////////////////////////////////
bool generator::generate_loop() {
    if (esp_code.is_open() && config_file.is_open()) {
        esp_code << "\nvoid loop(){\n";
        esp_code << "\tif (!client.connected())\n\t\tconnect();\n\telse\n\t\tclient.loop();\n";

        for(int i = 0; i < config["button"].size(); i++){
            std::string s = config["button"].at(i)["name"];
            s.substr(1, s.length()-1);
            esp_code << "\tif(digitalRead(" << s << ")){\n";
            esp_code << "\t\twhile(digitalRead(" << s << "));\n";
            s = config["button"].at(i)["topic"];
            s.substr(1, s.length()-1);
            esp_code << "\t\tchar pub[1] = {!state_topic_" << s << " + '0'};\n";
            esp_code << "\t\tclient.publish(" << config["button"].at(i)["topic"] <<", pub);\n";
            esp_code << "\t\tdelay(10);\n";
            esp_code << "\t}\n";
        }
        esp_code << "}\n";
        return true;
    } else{
        std::cerr << "Exception opening/reading file" << std::endl;
        return false;
    }
}
///////////////////////////////////////////////////////////////
bool generator::generate_functions() {
    if (esp_code.is_open() && functions.is_open() && config_file.is_open()) {
        esp_code << "\n";

        //callback
        esp_code << "void callback(String topic, byte* payload, unsigned int length) {\n";
        esp_code << "\tSerial.print(\"Message arrived in topic: \");\n";
        esp_code << "\tSerial.println(topic);\n";
        esp_code << "\tfor (int i = 0; i < length; i++)\n";
        esp_code << "\t\tSerial.print((char)payload[i]);\n";

        for(int i = 0; i < config["relay"].size(); i++){
            esp_code << "\tif(topic == " << config["relay"].at(i)["topic"] << "){\n";
            std::string s = config["relay"].at(i)["topic"];
            s.substr(1, s.length()-1);
            esp_code << "\t\tstate_topic_" << s << " = bool((char)payload[0] - '0');\n";

            s = config["relay"].at(i)["name"];
            s.substr(1, s.length()-1);
            esp_code << "\t\tdigitalWrite(" << s << ", " << "bool((char)payload[0] - '0') );\n";
            esp_code << "\t}\n";
        }

        esp_code << "}\n\n";

        //connect

        std::string line;
        while ( std::getline (functions,line) ){
            // std::cout << line << "\n";
            esp_code << line << '\n';
        }


        it = topics.begin();
        for (int i = 1; it != topics.end(); i++, it++) {
            esp_code << "\tclient.subscribe(\"" << *it << "\");\n";
        }

        esp_code << "}\n";

        return true;
    } else{
        std::cerr << "Exception opening/reading file" << std::endl;
        return false;
    }
}
///////////////////////////////////////////////////////////////
void generator::close_files() {
    config_file.close();
    functions.close();
    start_file.close();
    esp_code.close();
}

