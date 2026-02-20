#include "parsing.hpp"

std::vector<std::pair<std::string, int>> Parsing::get_scores_container() const{
    if(m_result.empty()){
        std::cout << "[Parsing::get_scores_container]Error: contianer (vector) pair is empty" << std::endl;
        return std::vector<std::pair<std::string, int>> {};
    }
    
    return m_result;
}

// Доработал проверку, теперь имя может иметь цифры
bool Parsing::set_high_scores_container(std::vector<std::string>& lines){

    if(lines.empty()){
        std::cout << "[Parsing::set_high_scores_container]Error: (vector)container lines is empty." << std::endl;
        return false;
    }

    std::vector<std::string> words;

    for(auto it = lines.begin() ; it != lines.end(); it++){
        std::vector<std::string> temp_words;

        temp_words = parsingLine(*it);

        if(temp_words.empty()){
            std::cout << "Error: can't parsingLine >> " << *it << std::endl;
            continue;
        }

        for(auto j_it = temp_words.begin(); j_it != temp_words.end(); j_it++){
            words.push_back(*j_it);
        }
    }

    if(words.empty()){
        std::cout << "[Parsing::set_high_scores_container]Error: container (vector) string is empty." << std::endl;
        return false;
    }

    std::vector<std::pair<std::string, int>> temp_vec;
    std::pair <std::string, int> temp_pair;
    std::string name, count;

    for(auto it = words.begin(); it != words.end(); it++){
        int num{-1};
        
        if(!isDijit(*it)){
            continue;
        }

        num = std::stoi(*it);
        
        if(num > 0){
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

    if(temp_vec.empty()){
        std::cout << "[Parsing::set_high_scores_container]Error: (vector)container pair is empty." << std::endl;
        return false;
    }

    m_result = temp_vec;

    return true;
}

std::vector<std::string> Parsing::parsingLine(std::string& lines, char split_token = ' '){
    if(lines.empty()){
        std::cout << "[Parsing::parsingLine]Error: container (vector) lines is empty." << std::endl;
        return std::vector<std::string>{}; 
    }

    std::vector<std::string> temp;

    for(auto it = lines.begin(); it != lines.end(); it++){
        std::string str_temp; 
        std::string::iterator j = it;

        for(; j != lines.end() && *j != split_token; j++){
            str_temp +=*j;
        }

        it = j;

        if(!str_temp.empty()){
            temp.push_back(str_temp);
        }
    }
    return temp;
}

bool Parsing::isDijit(std::string& word){
    if(word.empty()){
        std::cout << "[Parsing::isDijit]Error: string is empty." << std::endl;
        return false;
    }

    bool flag = true;
    for(auto it = word.begin(); it != word.end() && flag; it++){
        if(!std::isdigit(*it)){
            flag = false;
        }
    }

    return flag;
}