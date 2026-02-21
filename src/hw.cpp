// #include "wr_file.h"
// #include "user_game.h"

#include "managergame.hpp"

int main(int argc, char* argv[]){

    std::vector<std::string> argv_v;

    for(size_t i = 0; i < argc; i++){
        std::string temp = argv[i];
        argv_v.push_back(temp);
    }


    //version 1
    // User_game game;
    // game.start(argv_v);

    //version 2
    ManagerGame game;
    game.start(argv_v);
    
    return 0;
}