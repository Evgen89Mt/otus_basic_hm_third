#ifndef SCORES_HPP
#define SCORES_HPP

#include <string>
#include <vector>


class Scores{
    private:
        std::string m_name{"noname"};
        int m_count{-1};

        std::string m_name_file{"high_scores.txt"};

        std::vector<std::string> m_read_line;               // строки
        std::vector<std::string> m_words;                   // слова
        std::vector<std::pair<std::string, int>> m_result;  // контейнер
    
    public:
        bool set_name(const std::string& name);
        bool set_count(const int count);

    private:
        bool save_scores();
        bool read_scores();
        bool read_lines(std::vector<std::string>& lines);
        void view_result();
        void view_scores();

};

#endif