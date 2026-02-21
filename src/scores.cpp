#include "scores.hpp"

bool Scores::set_name(const std::string& name){
    if(name.empty()){
        std::cout << "[Scores::set_name]Error: string is empty."<<std::endl;
        return false;
    }

    m_name = name;

    return true;
}

bool Scores::set_count(const int count){
    if(count <= 0){
        std::cout << "[Scores::set_count]Error: count is negative"<<std::endl;
        return false;
    }

    m_count = count;

    return true;
}
bool Scores::save_scores(){
    if(m_count == -1 || m_name == "noname"){
        std::cout << "[Scores::save_scores]Error: bad is m_count or m_name" << std::endl;
        return false;
    }

    std::string count = std::to_string(m_count);

    if(!m_wr.writeToFile_user(m_name_file, m_name, count)){
        std::cout << "[Scores::save_scores]Error: can't save data to file" << std::endl;
        return false;
    }

    return true;
}
bool Scores::read_scores(){

    if(!m_wr.readFromFile_user(m_name_file, m_read_line)){
        std::cout << "[Scores::save_scores]Error: can't read the file." << std::endl;
        return false;
    }

    return true;
}

void Scores::view_result(){

    if(m_count == -1 || m_name == "noname"){
        std::cout << "[Scores::save_scores]Error: bad is m_count or m_name" << std::endl;
        return;
    }

    std::cout <<"___________________result____game__________________" << std::endl;
    std::cout << "name: " << m_name << " count: " << m_count << std::endl;
}
void Scores::view_scores(){

    if(!read_results_to_container()){
        std::cout << "[Scores::view_scores]Error: read_results_to_container." << std::endl;
        return;
    }

    if(m_result.empty()){
        std::cout << "[Scores::view_scores]Error: container(vector) is empty." << std::endl;
        return;
    }

    std::cout << "_________________results_total__________________" << std::endl;
    
    for(auto pair = m_result.begin(); pair != m_result.end(); pair++){
        std::cout << "name: " << (*pair).first << " count: " << (*pair).second << std::endl;
    }
}

bool Scores::read_results_to_container(){
    if(m_read_line.empty()){
        std::cout << "[Scores::read_results_to_container]Error: container (vector) lines is empty." << std::endl;
        return false; 
    }

    if(!m_parsing.set_high_scores_container(m_read_line)){
        std::cout << "[Scores::read_results_to_container]Error: can't set_high_scores_container" << std::endl;
        return false;
    }


    m_result = m_parsing.get_scores_container();
    
    if(m_result.empty()){
        std::cout << "[Scores::read_results_to_container]Error: container (vector) pair is empty." << std::endl;
        return false;        
    }
    
    return true;
}

void Scores::view_scores_top(){
        if(!read_results_to_container()){
        std::cout << "[Scores::view_scores]Error: read_results_to_container." << std::endl;
        return;
    }

    if(m_result.empty()){
        std::cout << "[Scores::view_scores]Error: container(vector) is empty." << std::endl;
        return;
    }


    if(!sort_container_top()){
        std::cout << "[Scores::view_scores]Error: sort_container_top." << std::endl;
        return;
    }

    std::cout << "_________________results_top__________________" << std::endl;
    
    for(auto pair = m_result_top.begin(); pair != m_result_top.end(); pair++){
        std::cout << "name: " << (*pair).first << " count: " << (*pair).second << std::endl;
    }
}

bool Scores::sort_container_top(){
    if(m_result.empty()){
        std::cout <<"[Scores::sort_container_top]Error: m_result is empty." << std::endl;
        return false;
    }
    
    m_result_top.clear();

    // 1 обход всего контейнера... подряд
    for(auto it = m_result.begin(); it != m_result.end(); it++){
        std::string name = (*it).first;
        int val = (*it).second;

        std::vector<std::pair<std::string, int>>::iterator found = m_result_top.end();

        //2 обход формируемого контейнера 
        for(std::vector<std::pair<std::string, int>>::iterator j = m_result_top.begin();
        j != m_result_top.end(); j++){
            
            if((*j).first == name){
                found = j;
                break;
            }
        }

        if(found == m_result_top.end()){
            // первый раз встретил имя добавляю его
            m_result_top.push_back(*it);
        }
        else{
            //значение меньше переписыаем
            if(val < (*found).second){
                (*found).second = val;
            } 
        }
    }

    return true;
}