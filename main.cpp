//
// Created by Cold on 03/05/2022.
//
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "LQQuestion.h"
#include "LQEngine.h"


std::string read_file(const char* path){
    FILE* file = fopen(path,"r");
    if (file == nullptr){
        return "fnf";
    }
    fseek(file,0,SEEK_END);
    auto file_end = ftell(file);
    fseek(file,0,SEEK_SET);
    char* buffer = (char*)malloc(file_end + 1);
    fread(buffer,1,file_end,file);
    fclose(file);

    return std::string(buffer);
}

int main(int argc, char** argv){
    if (argc < 2){
        std::cout << "Error:Not enough arguments" << std::endl;
        return 1;
    }

    std::string database_buffer = read_file(argv[1]);
    if (database_buffer == "fnf"){
        std::cout << "Error:File not found" << std::endl;
        return 2;
    }

    LQEngine engine(database_buffer);

    //TODO

}
