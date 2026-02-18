// #include "wr_file.h"
#include "user_game.h"

int main(int argc, char* argv[]){

    std::vector<std::string> argv_v;

    for(size_t i = 1; i < argc; i++){
        std::string temp = argv[i];
        argv_v.push_back(temp);
    }


    User_game game;
    game.start(argv_v);

    return 0;
}