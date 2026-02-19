#ifndef MANAGERGAME_HPP
#define MANAGERGAME_HPP

#include <string>
#include <iostream>
#include <vector>

#include "logicgame.hpp"
#include "parsing.hpp"
#include "scores.hpp"

struct Command{
    LogicGame m_logic_game;
    Parsing m_parsing;
    Scores m_scores;

    std::string name;
    bool (User_game::*method)(std::vector<std::string>& args_vec);
};

class ManagerGame{
    private:
        std::vector<Command> m_commnds;                     // команды (для работы с ком строки)
        std::vector<std::string> m_vec_commands;            // вектор команд из ком строки
    public:
        void start();
        void start(std::vector<std::string>& argv);

    private:
     bool init_command();
    Command* findCommand(std::string& command_name);

    bool executeTableCommand(std::vector<std::string>&);            //д2,3   
    bool executeDifficultyGameCommand(std::vector<std::string>&);   //д.1
    bool executeDifficultyLevelCommand(std::vector<std::string>&);  //д.5
    //д.4 нужно логику прорабатывать в методе save_scores
    //bool executeCommand(std::vector<std::string>&);
};

#endif