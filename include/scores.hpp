#ifndef SCORES_HPP
#define SCORES_HPP

#include <string>
#include <vector>

#include "parsing.hpp"
#include "wr_file.h"


class Scores{
    private:
        Parsing m_parsing;
        WriteReadFile m_wr;

        std::string m_name{"noname"};
        int m_count{-1};
        std::string m_name_file{"high_scores.txt"};

        std::vector<std::string> m_read_line;               
        std::vector<std::pair<std::string, int>> m_result;
        std::vector<std::pair<std::string, int>> m_result_top;  
    
    public:
        bool set_name(const std::string& name);
        bool set_count(const int count);

        bool save_scores();
        bool read_scores();
        
        void view_result();

        void view_scores();

        void view_scores_top();

    private:
        bool read_results_to_container();
        bool sort_container_top();
};

#endif