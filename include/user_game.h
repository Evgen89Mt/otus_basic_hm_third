/*
Домашнее задание 3.
Делаем игру "Угадай число"
1. Представиться (записать имя пользователя в переменную) в вести имя, далее в цикле зпровашивать число 
(ранее число загодал компьтер тоже переменная необходимо инициализировать рандомом, но до ввода чисел угадывания
необходимо ввести коэфициент сложности угадывания числа (коэф деления на загаданное число)),
игра заключается в угадывании числа, если загаданное число меньше в консоль выводится "less than" иначе,
 когда больше "greater than" в итоге когда угадываем выводится "you win", количество попыток быдет зписано 
 в переменную и игра заканчивается.
 2. После окончании игры данные дописываются в файл high_scores.txt (если его нет создать).
 (отдельно класс библиотека)
 3. Нужно выполнить парсинг строки на начало игры.
(думаю тоже реализовать отдельно классом)
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>

#include "wr_file.h"

class User_game{
    private:
        std::string command{""};                            // строка команда в начало игры или или
        std::string m_name{"noname"};                       // имя
        std::string m_name_file{"high_scores.txt"};         // имя файла
        int m_count{-1};                                    // количество попыток
        int m_kf{100};                                      // коэф сложности
        int m_value_ramdom;                                 // число для угадывания

        std::vector<std::string> m_high_scores_file;        // результат, все игроки и их попытки
        std::vector<std::pair<std::string, int>> m_result;  // подготовленный контейнер с результатами

    public:
        void start();

    private:
        bool set_random_number();
        bool set_random();
        void set_name_user();
        bool game();
        bool save_scores();
        bool read_scores();
        void view_result();
        void view_scores();

        std::pair<std::string, std::string> parsingString(
            std::string& string
            , char split_token
        );

        // В итоге разбить работу на три части
        //1. Складываем строки в вектор
        //2. Разбиваем на слова
        //3. Проверяем на число слова конвертируем в int 
        //4. Формируем pair
        std::vector<std::string> parsingLine(
            std::string line
            , char split_token
        );

        std::vector<std::pair<std::string, int>> set_high_scores_container(std::string& word);
        int isDigit(std::string& word);

        
};