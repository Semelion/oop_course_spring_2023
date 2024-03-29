//
// Created by semelion on 6/2/23.
//

#ifndef OOP_COURSE_SPRING_2023_COURSE_WORK_HPP
#define OOP_COURSE_SPRING_2023_COURSE_WORK_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <nlohmann/json.hpp>

/**
* @brief Класс для генерации кода в файл по параметрам
*/
class generator{
public:
    generator() = default;

    /**
    * @brief перегруженый оператор присвоения
    * @param json_src_file файл конфигурации в формате json
    * @param type_of_mk вариация микроконтроллера семейства ESP
    * @param out_code_file файл в который запишется сгенерированный код
    * @param start_of_code_src_file фацйл в котором содержится начальный комментарий и библиотеки
    * @param functions_src_file фацйл в котором содержтся функции для копирования
    */

    generator(const std::string &json_src_file, const std::string &type_of_mk, const std::string &out_code_file,
              const std::string &start_of_code_src_file, const std::string &functions_src_file);
    generator& operator=(const generator& rhs) = default;
    ~generator() = default;

    ///\brief Метод проверки соответсвия количества пинов на плате и количества кнопок и реле
    bool check_pins();

    ///\brief Метод генерирует и записывает комментарии в заголовке
    bool generate_notes();

    ///\brief Метод генерирует и записывает все необходимые дефайны и переменные
    bool generate_defines();

    ///\brief Метод генерирует и записывает  функцию setup
    bool generate_setup();

    ///\brief Метод генерирует и записывает функцию loop
    bool generate_loop();

    ///\brief Метод генерирует и записывает функции используемые для подключения к WIFI и MQTT брокеру и callback
    bool generate_functions();

    ///\brief Метод закрывает открытые файлы
    void close_files();

private:
    std::vector<int> pins; ///Динамический массив пинов в удобном порядке
//    int pins[11] = {23, 22, 21, 19, 18, 5, 17, 16, 4, 2, 15};// конфиг под плату
    int count_used_pins = 0; ///Количество использованных пинов
    std::string tupe_of_esp = "esp32"; ///Тип платы

    std::ofstream esp_code;
    std::ifstream start_file;
    std::ifstream functions;
    std::ifstream config_file;
    nlohmann::json config; ////Конфиг в формате JSON считтаный из файла
    std::set<std::string>::iterator it; ////Итератор для списка топиков
    std::set<std::string> topics; ////Список топиков
};

#endif //OOP_COURSE_SPRING_2023_COURSE_WORK_HPP
