//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    while (std::cin >> n && n > 0) {
        std::map<std::string, int> exchange;
        while (n--) {
            int m, n;
            std::cin >> m >> n;
            std::string key = std::to_string(m) + "_" + std::to_string(n);
            std::string key_r = std::to_string(n) + "_" + std::to_string(m);
            if (exchange.count(key)) {
                exchange[key]++;
            } else {
                exchange[key] = 1;
            }
            if(exchange.count(key_r)){
                exchange[key_r]--;
            }else{
                exchange[key_r] = -1;
            }
        }
        bool b_work_out = true;
        for (std::map<std::string, int>::iterator it = exchange.begin(); it != exchange.end(); ++it) {
            if (it->second != 0) {
                std::cout << "NO" << std::endl;
                b_work_out = false;
                break;
            }
        }
        if (b_work_out)
            std::cout << "YES" << std::endl;

    }
}
