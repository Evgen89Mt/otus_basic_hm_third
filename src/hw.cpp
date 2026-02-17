// #include "wr_file.h"
#include "user_game.h"

int main(int argc, char** argv){

    // for(size_t i = 0; i <= argc; i++)
    // {
    //     if(*(argv+i) != nullptr)
    //         std::cout << i << " " << *(argv+i) << std::endl;
    // }
    // std::cout << " argc: " << argc << std::endl;
    // 0 ./src/03.home_work
    // 1 -m
    // 2 42
    // argc: 3

    User_game game;
    game.start();

    return 0;
}