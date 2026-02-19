 #include "logicgame.hpp"
        
// void LogicGame::start(){
// }

void LogicGame::start(std::vector<std::string>& argv){

}

const std::string LogicGame::get_name() const{
    return m_name;
}
int LogicGame::get_count() const{
    return m_count;
}
bool LogicGame::set_name_user(){
    std::cout << std::endl;
    std::cin >> m_name;
}
bool LogicGame::set_diffuctly_user(){
    int koef_temp{-1};

    std::cout << "Enter kf dyffuctly: ";

    for(;!(cin >> koef_temp) || koef_temp < 10 || koef_temp > 1000;){
        
        if(std::cin.eof()){
            return false;
        }

        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << std::endl << "again enter: ";
    }
    std::endl;
    // std::cin >> koef_temp;
    // for(;koef_temp <= 10 || koef_temp > 1000;){
    //     std::cout << "again enter koef >> ";
    //     std::cin >> koef_temp;
    //     std::cout <<std::endl;
    // }

    m_kf_diffuctly = koef_temp;

    return true;
}

bool LogicGame::set_diffuctly(const int dif){

}


bool LogicGame::random(){
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
		std::cin >> current_value;
        // валидация!!!! Проверка на число если нет очистка

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