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
    view_result();

    if(!save_scores()){
        std::cout << "Error, can't save to file."<<std::endl;
    }

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

    return true;
}

bool User_game::set_random(){

    std::srand(std::time(nullptr));
    m_value_ramdom = std::rand()% m_kf;

    return true;
}

void User_game::set_name_user(){
    std::cout << std::endl;
    std::cin >> m_name;
}

bool User_game::game(){

    size_t count{0};
	int current_value = 0;
	bool not_win = true;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;

		if (current_value < m_value_ramdom) {
			std::cout << "less than " << current_value << std::endl;

		}
		else if (current_value > m_value_ramdom) {
			std::cout << "greater than " << current_value << std::endl;

		}
		else {
			std::cout << "you win!" << std::endl;
            not_win = false;
            count++;
			break;
		}
        count++;


	} while(not_win);

    m_count = count;

    return true;
}

bool User_game::save_scores(){

    WriteReadFile wr;
    std::string count;
    count += m_count;       // error
    //count = {m_count};

    if(!wr.writeToFile_user(m_name_file, m_name, count)){
        return false;
    }

    return true;
}

void User_game::view_result(){

    std::cout << "Total result:"<<std::endl;
    std::cout << "name: " << m_name <<std::endl;
    std::cout << "count: " << m_count << std::endl;
}

void User_game::view_scores(){

}