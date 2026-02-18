#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <cctype>

#include "wr_file.h"

class User_game;

struct Command{
    std::string name;
    bool (User_game::*method)(std::vector<std::string>& args_vec);
};

class User_game{
    private:
        std::string command{""};                            // строка команда в начало игры или или
        std::string m_name{"noname"};                       // имя
        std::string m_name_file{"high_scores.txt"};         // имя файла
        int m_count{-1};                                    // количество попыток
        int m_kf{100};                                      // коэф сложности
        int m_value_ramdom;                                 // число для угадывания

        std::vector<std::string> m_read_line;               // строки
        std::vector<std::string> m_words;                   // слова
        std::vector<std::pair<std::string, int>> m_result;  // подготовленный контейнер с результатами

        std::vector<Command> m_commnds;                     // команды (для работы с ком строки)
        std::vector<std::string> m_vec_commands;            // вектор команд из ком строки

    public:
        void start();
        void start(std::vector<std::string>& commands);

    private:
        bool set_difficulty_game();
        bool set_random();
        void set_name_user();
        bool game();
        bool save_scores();
        bool read_scores();
        bool read_lines(std::vector<std::string>& lines);
        void view_result();
        void view_scores();

        bool init_command();
        Command* findCommand(std::string& command_name);

        bool executeTableCommand(std::vector<std::string>&);            //д2,3   
        bool executeDifficultyGameCommand(std::vector<std::string>&);   //д.1
        bool executeDifficultyLevelCommand(std::vector<std::string>&);  //д.5
        //д.4 нужно логику прорабатывать в методе save_scores
        //bool executeCommand(std::vector<std::string>&);


        // В итоге разбить работу на три части
        // 1. Складываем строки в вектор (все строки)
        // 2. Разбиваем на слова (делим слова разделителем пробел)
        // 3. Проверяем на число слова конвертируем в int (-1 это слово)
        // 4. Формируем pair
        std::vector<std::string> parsingLine(
            std::string& line
            , char split_token = ' '
        );

        std::vector<std::pair<std::string, int>> set_high_scores_container(std::vector<std::string>& word);

        int isDigit(std::string& word);

};