#ifndef MANAGERGAME_HPP
#define MANAGERGAME_HPP

#include <string>
#include <iostream>
#include <vector>

#include "logicgame.hpp"
#include "parsing.hpp"
#include "scores.hpp"

class ManagerGame{
    private:
        LogicGame m_logic_game;
        Scores m_scores;
        std::vector<std::string> m_vec_commands;

    public:
        void start(std::vector<std::string>& argv);
};

#endif