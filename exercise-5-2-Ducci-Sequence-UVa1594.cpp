//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdlib.h>

using  namespace std;

bool move_loop(std::vector<int> &v, std::string &str) {
    int len = v.size();
    bool all_zeros = true;
    str = "";
    int tmp = v[0];
    for (int i = 0; i < len; ++i) {
        if (i != len - 1)
            v[i] = abs(v[i] - v[(i + 1) % len]);
        else
            v[i] = abs(v[len - 1] - tmp);
        str += to_string(v[i]) + "_";
        if (0 != v[i])
            all_zeros = false;
    }
    return all_zeros;
}


bool is_zero_loop(std::vector<int> &v) {
    std::set<std::string> cache;
    std::string str;
    int max_loop = 1000;
    while (1) {
        if (move_loop(v, str))
            return true;
        if (cache.count(str) || max_loop-- <= 0)
            break;
        cache.insert(str);
    }
    return false;
}


int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int num;
        std::vector<int> seq;
        while (n--) {
            std::cin >> num;
            seq.push_back(num);
        }
        if (is_zero_loop(seq)) {
            std::cout << "ZERO" << std::endl;
        } else {
            std::cout << "LOOP" << std::endl;
        }
    }
    return 0;
}