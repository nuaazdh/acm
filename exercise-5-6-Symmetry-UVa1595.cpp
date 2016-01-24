//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <set>

using  namespace std;

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::set<std::string> dot;
        int max_x = -1;
        int min_x = -1;
        bool first_loop = true;
        while (n--) {
            int x, y;
            std::cin >> x >> y;
            if (first_loop) {
                first_loop = false;
                min_x = max_x = x;
            } else {
                min_x = std::min(min_x, x);
                max_x = std::max(max_x, x);
            }
            dot.insert(std::to_string(x) + "_" + std::to_string(y));
        }//while(n--)
        bool sym = true;
        for (std::set<std::string>::iterator it = dot.begin(); it != dot.end(); ++it) {
            size_t pos = it->find_first_of('_');
            int xv = stoi(it->substr(0,pos));
//            int yv = stoi(it->substr(pos+1));
            std::string key = std::to_string((max_x+min_x) - xv)+"_"+it->substr(pos+1);
            if(!dot.count(key))
            {
                std::cout<<"NO\n";
                sym = false;
                break;
            };
        }
        if(sym){
            std::cout<<"YES\n";
        }
    }
    return 0;
}
