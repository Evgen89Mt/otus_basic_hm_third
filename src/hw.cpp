// #include "wr_file.h"
#include "user_game.h"

int main(int argc, char* argv[]){

    std::vector<std::string> argv_v;

    std::cout << "Count " << argc << std::endl;
    
    for(size_t i = 1; i < argc; i++){
        std::string temp = argv[i];
        std::cout << "value >> " << temp << std::endl; 
    }


    User_game game;
    game.start();

    return 0;
}