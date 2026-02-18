#ifndef LOGICGAME_HPP
#define LOGICGAME_HPP

#include <string>
#include <vector>

class LogicGame{
    private:
        std::string m_name{"noname"};
        int m_count{-1};
        int m_kf_diffuctly{100};
        int m_value_random{-1};

    public:
        void start();
        void start(std::vector<std::string>& argv);

        std::string get_name();
        int get_count();

    private:
        bool set_name();
        bool set_diffuctly();
        bool set_random();
        bool game();
};

#endif