//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <string>
#include <set>


int main() {
    std::set<std::string> dict;
    std::string word;
    while (std::cin >> word) {
        dict.insert(word);
    }
    for (std::set<std::string>::iterator it = dict.begin(); it != dict.end() ; ++it) {
        word = *it;
        for (int j = 1; j < word.length(); ++j) {
            std::string front = word.substr(0,j);
            std::string back = word.substr(j);
            if(dict.count(front) && dict.count(back))
            {
                std::cout<<word<<std::endl;
                break;
            }
        }

    }
    return 0;
}
