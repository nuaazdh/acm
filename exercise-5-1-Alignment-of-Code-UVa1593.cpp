//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <vector>
#include <sstream>

const int max_line = 1010;

std::vector<std::string> code[max_line];
int width_column[180]={0};

void print_word(std::string& str, int width, char holder)
{
    std::cout<<str;
    for (int i = 0; i < width-str.length(); ++i) {
        std::cout<<holder;
    }
}

int main()
{
//    std::cin.ignore();
    std::string line;
    int line_cnt = 0;
    while(std::getline(std::cin, line)){
        std::stringstream ss(line);
        std::string word;
        int column = 0;
        while(ss>>word){
            code[line_cnt].push_back(word);
            if(word.length()>width_column[column])
                width_column[column] = word.length();
            column++;
        }
        line_cnt++;
    }
    for (int i = 0; i < line_cnt; ++i) {
        for (int j = 0; j < code[i].size(); ++j) {
            if(j!=code[i].size() -1 )
                print_word(code[i][j],width_column[j]+1, ' ');
            else{
                std::cout<<code[i][j]<<std::endl;
            }
        }
    }
    return 0;
}