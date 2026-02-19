#ifndef LOGICGAME_HPP
#define LOGICGAME_HPP

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <cctype>

class LogicGame{
    private:
        std::string m_name{"noname"};
        int m_count{-1};
        int m_kf_diffuctly{100};
        int m_value_random{-1};

    public:
        // void start();
        void start(std::vector<std::string>& argv);

        const std::string get_name() const;
        int get_count() const;
        bool set_name_user();
        bool set_diffuctly_user();
        bool set_diffuctly(const int dif);

    private:
        bool random();
        bool game();

};

#endif