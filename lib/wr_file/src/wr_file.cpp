#include "wr_file.h"

bool WriteReadFile::writeToFile_user(std::string& file, std::string& name, std::string& str){
    if(str.empty() || name.empty()){
        std::cout << "[WriteReadFile::writeToFile_user] Error: string | name is empty." << std::endl;
        return false;
    }

    if(file.empty()){
        std::cout << "[WriteReadFile::writeToFile_user] Error: string file is empty." << std::endl;
        return false;
    }

    std::fstream fout;
    fout.open(file, std::fstream::out | std::fstream::app);

    if(!fout.is_open()){
        std::cout << std::boolalpha << "file is not open, status >> " << fout.is_open() << std::endl;
        return false;
    }


    fout << name;
    fout << " ";
    fout << str;
    fout << std::endl;

    //std::cout << "save date is success!!" << std::endl;

    return true;
}

bool WriteReadFile::readFromFile_user(std::string& file, std::vector<std::string>& date){
    if(file.empty()){
        std::cout << "[WriteReadFile::readFromFile_user] Error: string file is empty." << std::endl;
        return false;
    }

    std::fstream fin;
    fin.open(file, std::fstream::in);

    if(!fin.is_open()){
        std::cout << std::boolalpha << "file is not open, status >> " << fin.is_open() << std::endl;
        return false;
    }

    std::string line;

    for(; std::getline(fin, line);){
        date.push_back(line);
    }

    if(date.empty()){
        std::cout << "[WriteReadFile::readFromFile_user] Error, container (vector) is empty." << std::endl;
        return false;
    }

    std::cout << "!! read from file." << std::endl;
    
    return true;
}