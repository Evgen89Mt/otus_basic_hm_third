#include "managergame.hpp"

    // Вариант игра с начало argv.size() == 1)
    // Надо бы склеить посмотреть
    // table -- TODO
    
    void ManagerGame::start(std::vector<std::string>& argv){
        if(argv.empty()){
            std::cout << "[ManagerGame::start]Error: container(vector) is empty"<< std::endl;
            return;
        }

        if(argv.size() == 1){

            m_logic_game.start(0);

            if(!m_scores.set_name(m_logic_game.get_name())){
                std::cout << "[ManagerGame::start]Error: m_scores.set_name." << std::endl;
                return;
            }

            if(!m_scores.set_count(m_logic_game.get_count())){
                std::cout << "[ManagerGame::start]Error: m_scores.set_count." << std::endl;
                return;
            }

            m_scores.view_result();

            if(m_scores.save_scores()){
                std::cout << "[ManagerGame::start]Error: m_scores.save_scores." << std::endl;
                return;
            }

            if(m_scores.read_scores()){
                std::cout << "[ManagerGame::start]Error: m_scores.read_scores." << std::endl;
                return;               
            }
            
            m_scores.view_scores();
        }
        else if(argv[1] == "-table"){
            //TODO
        }else if(argv[1] == "-max"){
            //TODO
        }else if(argv[1] == "-level"){
            //TODO
        }else{
            std::cout << "not a clear command >> " << argv[1] << std::endl;
            return;
        }

    }

    bool ManagerGame::init_command(){

    }

    Command* ManagerGame::findCommand(std::string& command_name){

    }

    bool ManagerGame::executeTableCommand(std::vector<std::string>&){
    
    }  
    bool ManagerGame::executeDifficultyGameCommand(std::vector<std::string>&){

    }

    bool ManagerGame::executeDifficultyLevelCommand(std::vector<std::string>&){

    }