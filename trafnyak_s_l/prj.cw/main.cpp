#include <fstream>
#include <string>
#include <iostream>
#include <set>

#include <nlohmann/json.hpp>

int pins[11] = {23, 22, 21, 19, 18, 5, 17, 16, 4, 2, 15};
int count_used_pins = 0;

int main () {
	//OPEN FILES//
	std::ofstream esp_code;
	esp_code.open ("smart_house_mqtt.ino");

	std::ifstream start_file;
	start_file.open("src/start_of_code.txt");

	std::ifstream functions;
	functions.open("src/function.txt");

	std::ifstream config_file("src/config.json");
	nlohmann::json config = nlohmann::json::parse(config_file);

	//WRITE COMMENTS AND NOTES IN TOP OF CODE FILE//
	if (esp_code.is_open() && start_file.is_open()){
		//std::cout << "start_file is opened\n";
		std::string line;
		while ( std::getline (start_file,line) ){
			// std::cout << line << "\n";
			esp_code << line << '\n';
		}
	}
	esp_code << "\n";


	//PARCING FROM CONFIG AND WRITE DEFINES//

    esp_code << "#define WIFI_SSID\t" << config["wifi"]["ssid"] << std::endl;
	esp_code << "#define WIFI_PW\t" << config["wifi"]["pasword"] << std::endl;
    esp_code << "#define MQTT_BROKER\t" << config["mqtt_broker"]["MQTT_BROKER"] << std::endl;
    esp_code << "#define MQTT_PORT\t" << config["mqtt_broker"]["MQTT_PORT"] << std::endl;
    esp_code << "#define MQTT_NAME_OF_DEVICE\t" << config["mqtt_broker"]["MQTT_NAME_OF_DEVICE"] << std::endl;
    esp_code << "#define MQTT_LOGIN\t" << config["mqtt_broker"]["MQTT_LOGIN"] << std::endl;
    esp_code << "#define MQTT_PW\t" << config["mqtt_broker"]["MQTT_PW"] << "\n" << std::endl;

    std::set<std::string> topics;
	for(int i = 0; i < config["button"].size(); i++){
		std::string s = config["button"].at(i)["name"];
		std::string trimmed = s.substr(1, s.length()-1);
		esp_code << "#define " << s << "\t" << pins[i] << "\n";
		count_used_pins++;
		std::string temp = config["button"].at(i)["topic"];
		topics.insert(temp);
	}

	for(int i = 0; i < config["relay"].size(); i++){
		std::string s = config["relay"].at(i)["name"];
		std::string trimmed = s.substr(1, s.length()-1);
		esp_code << "#define " << s << "\t" << pins[i + count_used_pins] << "\n";
		std::string temp = config["relay"].at(i)["topic"];
		topics.insert(temp);
	}

	esp_code << "\nWiFiClient espClient;\n";
	esp_code << "PubSubClient client(espClient);\n\n";

	std::set <std::string> :: iterator it = topics.begin();
	for (int i = 1; it != topics.end(); i++, it++) {
		esp_code << "bool state_topic_" << *it << " = 0;\n";
    }

	///WRITE SETUP////
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
	esp_code << "\n\tconnect2WIFI();\n";
	esp_code << "\tconnect2mqtt();\n";

	esp_code << "}\n";
	///END SETUP//////

	///WRITE LOOP/////
	esp_code << "\nvoid loop(){\n";
	esp_code << "\tif (!client.connected())\n\t\tconnect2mqtt();\n\telse\n\t\tclient.loop();\n";

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
	// if(digitalRead(but1)){
    //   while(digitalRead(but1));
    //   char out[1] = {!state_topic_kitchen + 48};
    //   client.publish("kitchen1", out);
    //   delay(10);
    // }
	// for (int i = 1; it != topics.end(); i++, it++) {
	// 	esp_code << "if(digitalRead(" <<
	// 	// esp_code << "bool state_topic_" << *it << " = 0;\n";
    // }
	///END LOOP///////

	////WRITE FUNCTIONS/////
	esp_code << "\n";
	if (esp_code.is_open() && functions.is_open()){
		//std::cout << "start_file is opened\n";
		std::string line;
		while ( std::getline (functions,line) ){
			// std::cout << line << "\n";
			esp_code << line << '\n';
		}
	}

	it = topics.begin();
	for (int i = 1; it != topics.end(); i++, it++) {
		esp_code << "\tclient.subscribe(\"" << *it << "\");\n";
    }

	esp_code << "}\n\n";
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

	esp_code << "}";
	///END FUNCTIONS///////


	//CLOSE FILES//
	// config.close();
	config_file.close();
    functions.close();
	start_file.close();
	esp_code.close();
	return 0;
}
