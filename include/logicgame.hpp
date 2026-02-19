#ifndef LOGICGAME_HPP
#define LOGICGAME_HPP

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <cctype>

enum difficulty{
     ZERO
    ,LEVEL1
    ,LEVEL2
    ,LEVEL3
};

class LogicGame{
    private:
        std::string m_name{""};
        int m_count{-1};
        int m_kf_diffuctly{100};
        int m_value_random{-1};

    public:
        void start(const int kf);

        const std::string get_name() const;
        int get_count() const;
        void set_name_user();
        bool set_difficulty_user();
        bool set_difficulty(const int dif);

    private:
        bool random();
        bool game();

};

#endif