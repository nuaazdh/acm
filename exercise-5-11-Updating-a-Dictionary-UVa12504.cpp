//
// Created by luerfeng on 2016/01/20.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <map>
#include <set>
#include <string>

std::map<std::string, std::string> dict1;
std::map<std::string, std::string> dict2;
std::set<std::string> k_add;
std::set<std::string> k_remove;
std::set<std::string> k_revise;

bool extract_str(std::string &str, size_t &pos1, size_t &pos2, std::string &value) {
    size_t len = str.length();
    while (pos1 < len - 1 && !isalnum(str[pos1])) pos1++;
    pos2 = pos1 + 1;
    while (pos2 < len && isalnum(str[pos2])) pos2++;
    if (pos2 >= len)
        return false;
    value = str.substr(pos1, pos2 - pos1);
    return true;
}


void read_into_dict(std::string &str, std::map<std::string, std::string> &dict) {
    size_t pos1 = 0, pos2 = 0;
    std::string key, value;
    while (1) {
        if (!extract_str(str, pos1, pos2, key))
            break;
        pos1 = pos2 + 1;

        if (!extract_str(str, pos1, pos2, value))
            break;
        pos1 = pos2 + 1;
        dict[key] = value;
    }
}

void compare_dict(std::map<std::string, std::string> &dict1, std::map<std::string, std::string> &dict2) {
    k_add.clear();
    k_remove.clear();
    k_revise.clear();
    std::map<std::string, std::string>::iterator it = dict1.begin(), ip = dict2.begin();
    while (it != dict1.end() && ip != dict2.end()) {
        int cmp = it->first.compare(ip->first);
        if (cmp == 0) {
            if (it->second.compare(ip->second) != 0)
                k_revise.insert(it->first);
            ++ip, ++it;
        } else if (cmp > 0) {
            k_add.insert(ip->first);
            ip++;
        } else {
            k_remove.insert(it->first);
            it++;
        }
    }
    for (; ip != dict2.end(); ++ip) {
        k_add.insert(ip->first);
    }
    for (; it != dict1.end(); ++it) {
        k_remove.insert(it->first);
    }

}

void print_result(std::set<std::string> &result, char prefix) {
    if (result.size() > 0) {
        int i = 0;
        std::cout << prefix;
        for (std::set<std::string>::iterator it = result.begin(); it != result.end(); ++it) {
            if (0 != i) std::cout << ",";
            std::cout << *it;
            ++i;
        }
        std::cout << std::endl;
    }
}

int main() {
    int T;
    std::string line;
    std::cin >> T;
    std::string no_change("No changes\n");
    while (T--) {
        dict1.clear();
        dict2.clear();
        std::cin >> line;
        read_into_dict(line, dict1);
        std::cin >> line;
        read_into_dict(line, dict2);
        compare_dict(dict1, dict2);
        if (k_add.size() == 0 && k_remove.size() == 0 && k_revise.size() == 0) {
            std::cout << no_change;
        } else {
            print_result(k_add, '+');
            print_result(k_remove, '-');
            print_result(k_revise, '*');
        }
        std::cout << "\n";
    }
    return 0;
}