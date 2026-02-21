 #include "logicgame.hpp"
        

void LogicGame::start(const int kf = 0){

    std::cout << "_____________start____game____________"<< std::endl;
    std::cout << "Hi! Enter your name, please: ";
    set_name_user();

    switch (kf)
    {
    case ZERO:
        std::cout << "Enter koeff diferend >> ";
        if(!set_difficulty_user()){
            std::cout << "koeff [100]" << std::endl;
        }
        std::cout << std::endl;
        break;
    case LEVEL1:
        if(!set_difficulty(10)){
            std::cout << "koeff [100]" << std::endl;
        }
        break;
    case LEVEL2:
        if(!set_difficulty(100)){
            std::cout << "koeff [100]" << std::endl;
        }
        break;
    case LEVEL3:
        if(!set_difficulty(1000)){
            std::cout << "koeff [100]" << std::endl;
        }
        break;
    default:
        if(!set_difficulty(kf)){
            std::cout << "koeff [100]" << std::endl;
        }
        break;
    }

    if(!random()){
        std::cout << "can't random " << std::endl;
        return;
    }

    if(!game()){
        std::cout << "can't game " << std::endl;
        return;
    }
}

const std::string LogicGame::get_name() const{
    return m_name;
}

const int LogicGame::get_count() const{
    return m_count;
}

void LogicGame::set_name_user(){
    std::cout << std::endl;
    std::cin >> m_name;

    for(;m_name == "";){
        std::cout << std::endl << "again enter name: ";
        std::cin >> m_name;
    }

    std::cout << std::endl;
}

bool LogicGame::set_difficulty_user(){

    int koef_temp{-1};

    for(;!(std::cin >> koef_temp) || koef_temp < 10 || koef_temp > 1000;){
        
        if(std::cin.eof()){
            return false;
        }

        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << std::endl << "again enter kf: ";
    }
    std::cout << std::endl;
    // for(;koef_temp <= 10 || koef_temp > 1000;){
    //     std::cout << "again enter koef >> ";
    //     std::cin >> koef_temp;
    //     std::cout <<std::endl;
    // }

    m_kf_diffuctly = koef_temp;

    return true;
}

bool LogicGame::set_difficulty(const int dif){
    if(dif < 10 || dif > 1000){
        std::cout << "[LogicGame::set_difficulty]Error: set_difficulty." << std::endl;
        return false;
    }

    m_kf_diffuctly = dif;

    return true;
}

bool LogicGame::random(){

    if(m_kf_diffuctly == 0){
        std::cout << "Error: koeff is zero." << std::endl;
        return false;
    }

    std::srand(std::time(nullptr));
    m_value_random = std::rand()% m_kf_diffuctly;

    return true;
}

bool LogicGame::game(){

    size_t count{0};
	int current_value = 0;
	bool not_win = true;

	std::cout << "Enter your guess:" << std::endl;

	do {

        for(;!(std::cin >> current_value);){
        
        if(std::cin.eof()){
            return false;
        }

        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << std::endl << "again enter guess: ";
    }
        

		if (current_value < m_value_random) {
			std::cout << "less than " << current_value << std::endl;

		}
		else if (current_value > m_value_random) {
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