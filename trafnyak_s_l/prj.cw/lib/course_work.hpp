//
// Created by semelion on 6/2/23.
//

#ifndef OOP_COURSE_SPRING_2023_COURSE_WORK_HPP
#define OOP_COURSE_SPRING_2023_COURSE_WORK_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <nlohmann/json.hpp>


class generator{
public:
    generator() = default;
    generator(std::string json_src_file, std::string out_code_file, std::string start_of_code_src_file, std::string functions_src_file);
    generator& operator=(const generator& rhs) = default;
    ~generator() = default;

    bool generate_notes();
    bool generate_defines();
    bool generate_setup();
    bool generate_loop();
    bool generate_functions();
    void close_files();

private:
    int pins[11] = {23, 22, 21, 19, 18, 5, 17, 16, 4, 2, 15};// конфиг под плату
    int count_used_pins = 0;
    std::ofstream esp_code;
    std::ifstream start_file;
    std::ifstream functions;
    std::ifstream config_file;
    nlohmann::json config;
    std::set<std::string>::iterator it;
    std::set<std::string> topics;
};

#endif //OOP_COURSE_SPRING_2023_COURSE_WORK_HPP
