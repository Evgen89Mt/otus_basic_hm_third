#include "user_game.h"

void User_game::start(){
    std::cout << "___________start____game____________"<< std::endl;
    std::cout << "Hi! Enter your name, please: ";
    set_name_user();
    std::cout << std::endl;

    std::cout << "Enter koeff diferend >> ";
    if(!set_random_number()){
        std::cout << "koeff [100]" << std::endl;
    }

    if(!set_random()){
        std::cout << "can't random " << std::endl;
        return;
    }

    game();
}

bool User_game::set_random_number(){
    int koef_temp{-1};

    std::cin >> koef_temp;
    for(;koef_temp <= 0 || koef_temp > 1000;){
        std::cout << "again enter koef >> ";
        std::cin >> koef_temp;
        std::cout <<std::endl;
    }

    m_kf = koef_temp;
    // std::cout << "!! m_kf >> " << m_kf << std::endl;

    return true;
}

bool User_game::set_random(){

    std::srand(std::time(nullptr));
    m_value_ramdom = std::rand()% m_kf;

    std::cout << "!! random >> " << m_value_ramdom<< std::endl;

    return true;
}

void User_game::set_name_user(){
    std::cin >> m_name;
}

bool User_game::game(){

    return true;
}
bool User_game::save_scores(){

    return true;
}
void User_game::view_scores(){

}