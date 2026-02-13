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
        std::cout << "Error, can't save to file." << std::endl;
    }

    if(!read_scores()){
        std::cout << "Error, can't read file." << std::endl;
    }

    view_scores();
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
    std::string count = std::to_string(m_count);

    if(!wr.writeToFile_user(m_name_file, m_name, count)){
        return false;
    }

    return true;
}

bool User_game::read_scores(){
    WriteReadFile wr;
    
    if(!wr.readFromFile_user(m_name_file, m_high_scores_file)){
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
    if(m_high_scores_file.empty()){
        std::cout << "[User_game::view_scores] Error, container (vector) is empty." << std::endl;
        return;
    }

    std::cout << "-------------------------------------------------------"<<std::endl;
    for(const auto str: m_high_scores_file){
        std::cout << str << std::endl;
    }
}



std::pair<std::string, std::string> User_game::parsingString(
    std::string& string
    , char split_token = ' '){
                
    if(string.empty()){
        std::cout << "[User_game::parsingString]Error: string is empty." << std::endl;
        return std::pair<std::string, std::string>{};
    }
    std::pair<std::string, std::string> pair_tmp;

    //iterator string (обход по символам до конца строки nullptr)
    for(auto it  = string.begin(); it < string.end(); it++){

        //если я не пустое место, то собираю слово...
        // if(*it != split_token){
            std::string temp;
            //делаем копию итератора для обхода слова
            std::string::iterator it_j = it;
            // включаем цикл до спита
            for(;it_j < string.end() && *it_j != split_token; it_j++){
                temp +=*it_j;
            }
            pair_tmp.first = temp;
            temp.clear();

            for(;it_j < string.end() && *it_j != split_token; it_j++){
                temp +=*it_j;
            }
            pair_tmp.second = temp;
        // }
    }

    if(pair_tmp.first.empty() || pair_tmp.second.empty()){
        std::cout << "[]";
    }

    return pair_tmp;
}

std::vector<std::string> User_game::parsingLine(
    std::string line
    , char split_token = ' '
){
    if(line.empty()){
        std::cout << "[User_game::parsingLine]Error: string is empty." << std::endl;
        return std::vector<std::string>{""};
    }

    std::vector<std::string> temp_vec;

    //TO DO

    return temp_vec;
}

std::vector<std::pair<std::string, int>> User_game::set_high_scores_container(std::string& word){

    if(word.empty()){
        std::cout << "[User_game::set_high_scores_container]Error: string is empty." << std::endl;
        return std::vector<std::pair<std::string, int>>{};
    }

    std::vector<std::pair<std::string, int>> temp_vec;

    //TO DO

    return temp_vec;
}

int User_game::isDigit(std::string& word){
    if(word.empty()){
        std::cout << "[User_game::isDigit]Error: string is empty." << std::endl;
        return -1;
    }

    //TO DO

    return 1;
}