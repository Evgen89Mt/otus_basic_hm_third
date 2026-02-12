#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

class WriteReadFile{
    public:
        // my func
        bool writeToFile_user(std::string& file, std::string& name, std::string& str);
        bool readFromFile_user(std::string& file, std::vector<std::string>& date);

        // lec func
        // bool writeToFile_l(std::string& file, std::string& str);
        // bool readFromFile_l(std::string& file, std::string& str);

    private:

        std::string file_name;
        std::string name;
        std::string res;
};