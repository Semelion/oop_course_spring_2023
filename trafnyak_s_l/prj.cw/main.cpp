#include "lib/course_work.hpp"

int main(int argc, char *argv[]) {
//    for(int i = 0; i < argc; i++){
//        std::cout << argv[i] << std::endl;
//        std::string str(argv[i]);
//
//    }
    std::string type = "ESP32";
    std::string config = "src/config.json";
    std::string out = "smart_house_mqtt.ino";

    if (argc == 1) {
        generator gen(config, type, out, "src/start_of_code.txt", "src/function.txt");
        gen.check_pins();
        gen.generate_notes();
        gen.generate_defines();
        gen.generate_setup();
        gen.generate_loop();
        gen.generate_functions();
        gen.close_files();
    } else {
        std::string str(argv[1]);
        if ("--help" == str) {
            std::cout << "For generate use flags:" << std::endl;
            std::cout << "--config path_to_config/name_of_config_file.json\t: with flag for find config with params\n"
                      << std::endl;
            std::cout
                    << "--type 'type_of_esp'\t: type of chip or board (one of: ESP32, ESP8266, ESP-12S, WeMos_D1_mini, ESP-12E, ESP-12F, Mini-S1)\n"
                    << std::endl;
            std::cout << "--out file\t: in wich file the code will be generated\n" << std::endl;
            std::cout << "default: --config src/config.json --type ESP32 --out smart_house_mqtt.ino" << std::endl;
            return 0;
        }

        for (int i = 1; i < argc; i += 2) {
            std::string str(argv[i]);
//        std::cout << str << std::endl;
            if ("--type" == str) {
                type = argv[i + 1];
            } else if ("--config" == str) {
                config = argv[i + 1];
            } else if ("--out" == str) {
                out = argv[i + 1];
            } else {
                std::cerr << "Wrong flag" << std::endl;
                return -1;
            }
        }
//    std::cout << config << "\t" << type << "\t" << out << "\t" << std::endl;
        generator gen(config, type, out, "src/start_of_code.txt", "src/function.txt");
        gen.check_pins();
        gen.generate_notes();
        gen.generate_defines();
        gen.generate_setup();
        gen.generate_loop();
        gen.generate_functions();
        gen.close_files();
    }
    return 0;
}