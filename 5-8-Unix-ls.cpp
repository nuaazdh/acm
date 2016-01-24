//
// Created by luerfeng on 2016/01/16.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

const int max_file_cnt = 110;

std::string files[max_file_cnt];

void print_extra(const std::string &s, int len, char extra)
{
    std::cout<<s;
    for (int i = 0; i < len-s.length(); ++i) {
        std::cout<<extra;
    }
}

int main() {
    int n;
    while (std::cin >> n) {
        int max_length = 0;
        for (int i=0;i<n;++i) {
            std::cin >> files[i];
            max_length = std::max((int) files[i].length(), max_length);
        }
        std::sort(files, files+n);
        int column = (60-max_length)/(max_length+2)+1;
        int row = (n - 1) / column + 1;
        print_extra("", 60, '-');
        std::cout<<std::endl;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (j * row + i >= n)
                    break;
                print_extra(files[j * row + i], (j==column-1 ? max_length : max_length+2) , ' ');
            }
            std::cout << std::endl;
        }
    }
    return 0;
}


