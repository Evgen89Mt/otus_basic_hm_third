#ifndef PARSING_HPP
#define PARSING_HPP

#include <iostream>
#include <string>
#include <vector>

#include "wr_file.h"

class Parsing{
    private:
        std::vector<std::string> m_read_line;               
        std::vector<std::pair<std::string, int>> m_result;

    public:
        std::vector<std::pair<std::string, int>> get_scores_container() const;
        bool set_high_scores_container(std::vector<std::string>& lines);

    private:
        std::vector<std::string> parsingLine(std::string& line, char split_token = ' ');
        bool isDijit(std::string& word);
};


#endif