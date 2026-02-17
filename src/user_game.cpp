#include "user_game.h"

void User_game::start(){
    std::cout << "___________start____game____________"<< std::endl;
    std::cout << "Hi! Enter your name, please: ";
    set_name_user();
    std::cout << std::endl;

    //std::cout << "Enter koeff diferend >> ";
    if(!set_random_number()){
        std::cout << "koeff [100]" << std::endl;
    }

    if(!set_random()){
        std::cout << "can't random " << std::endl;
        return;
    }

    game();

    if(!save_scores()){
        std::cout << "Error, can't save to file." << std::endl;
    }

    if(!read_scores()){
        std::cout << "Error, can't read file." << std::endl;
        return;
    }


    if(!read_lines(m_read_line)){
        std::cout << "Error, can't read lines." << std::endl;
        return;
    }


    m_result = set_high_scores_container(m_words);

    if(m_result.empty()){
        std::cout << "Container result is empty." << std::endl;
    }
    
    if(!m_result.empty()){
        view_result();
    }
}

bool User_game::set_random_number(){
    int kf;
    
    std::cout << "Enter koeff difficulty: ";
    // std::cin >> kf;
    //
    // if(kf <= 0 || kf > 1000){
    //     std::cout << "Error: koeff is standard 100.(check value kf): " << kf << std::endl;
    //     return false;
    // }
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
    
    if(!wr.readFromFile_user(m_name_file, m_read_line)){
        return false;
    }

    return true;
}

bool User_game::read_lines(std::vector<std::string>& lines){
    if(lines.empty()){
        std::cout << "[User_game::read_lines]Error: container (vector) is empty." << std::endl;
        return false; 
    }

    std::vector<std::string> temp;

    for(auto it = lines.begin(); it != lines.end(); it++){
        temp = parsingLine(*it);
        if(!temp.empty()){

            for(auto it_temp = temp.begin(); it_temp != temp.end(); it_temp++){

                if(!(*it_temp).empty()){
                    m_words.push_back(*it_temp);
                }

            }

        }
        temp.clear();
    }


    return true;
}

void User_game::view_result(){

    std::cout << "_________________result_total__________________" << std::endl;

    for(auto pair = m_result.begin(); pair != m_result.end(); pair++){

        std::cout << "name: " << (*pair).first << " count: " << (*pair).second << std::endl;
    }
}

void User_game::view_scores(){
    if(m_words.empty()){
        std::cout << "[User_game::view_scores] Error, container (vector) is empty." << std::endl;
        return;
    }

    std::cout << "-------------------------------------------------------"<<std::endl;
    for(const auto str: m_words){
        std::cout << str << std::endl;
    }
}

std::vector<std::string> User_game::parsingLine(
    std::string& line
    , char split_token
){
    if(line.empty()){
        std::cout << "[User_game::parsingLine]Error: string is empty." << std::endl;
        return std::vector<std::string>{""};
    }

    std::vector<std::string> temp_vec;
    std::string temp;

    for(auto it = line.begin(); it != line.end(); it++){

        if(*it == split_token){
            if(!temp.empty()){
                temp_vec.push_back(temp);
                temp.clear();
            }
        }
        else{
            temp += *it;
        }
    }

    if(!temp.empty()){
        temp_vec.push_back(temp);
    }

    std::cout << "lines >> " << temp_vec.size() << std::endl; 

    return temp_vec;
}

std::vector<std::pair<std::string, int>> User_game::set_high_scores_container(
    std::vector<std::string>& words){

    if(words.empty()){
        std::cout << "[User_game::set_high_scores_container]Error: (vector)container strings is empty." << std::endl;
        return std::vector<std::pair<std::string, int>>{};
    }

    std::vector<std::pair<std::string, int>> temp_vec;
    std::pair <std::string, int> temp_pair;
    std::string name, count;

    for(auto it = words.begin(); it != words.end(); it++){

        int num = isDigit(*it);
        
        if(num >= 0){
            count += *it;
        }
        else{
            name += *it;
        }
        
        if(!name.empty() && !count.empty()){
        
            temp_pair.first = name;
            temp_pair.second = std::stoi(count);
        
            temp_vec.push_back(temp_pair);
        
            temp_pair = {};
            name.clear(); 
            count.clear();
        }
    }

    return temp_vec;
}

int User_game::isDigit(std::string& word){
    if(word.empty()){
        std::cout << "[User_game::isDigit]Error: string is empty." << std::endl;
        return -1;
    }

    std::string temp;

    for(auto it = word.begin(); it != word.end(); it++){
        if(std::isdigit(*it)){
            temp.push_back(*it);
        }
    }

    if(!temp.empty()){
        return std::stoi(temp);
    }

    return -1;
}