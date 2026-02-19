#ifndef PARSING_HPP
#define PARSING_HPP

#include <iostream>
#include <string>
#include <vector>

#include "wr_file.h"

class Parsing{
    private:
        std::vector<std::string> m_read_line;               // строки
        std::vector<std::string> m_words;                   // слова
        std::vector<std::pair<std::string, int>> m_result;  // подготовленный контейнер с результатами

    public:

        std::vector<std::pair<std::string, int>> get_scores_container() const;

        // В итоге разбить работу на три части
        // 1. Складываем строки в вектор (все строки)
        // 2. Разбиваем на слова (делим слова разделителем пробел)
        // 3. Проверяем на число слова конвертируем в int (-1 это слово)
        // 4. Формируем pair
        std::vector<std::string> parsingLine(std::string& line
            , char split_token = ' '
        );

        // Доработать обработку имение с цифрами
        bool set_high_scores_container(std::vector<std::string>& word);

    private:
        int isDigit(std::string& word);

};


#endif