//
// Created by luerfeng on 2016/01/20.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <map>
#include <set>

std::map<char, std::string> morse_code;
std::map<std::string, std::string> dict;

void read_morse_code() {
    std::string c;
    std::string code;
    while (std::cin >> c && c != "*") {
        std::cin >> code;
        morse_code[c[0]] = code;

    };
}

std::string encode(std::string &word) {
    std::string str = "";
    for (int i = 0; i < word.length(); ++i) {
        str += morse_code[word[i]];
    }
    return str;
}

void read_word() {
    std::string word;
    while (std::cin >> word && word != "*") {
        dict[word] = encode(word);
    }
}

bool decode(std::string str1, std::string str2, int &mismatch_size) {
    if (str1 == str2) {
        mismatch_size = 0;
        return true;
    }
    if (str2.length() > str1.length())
        std::swap(str1, str2);
    if (str2 != str1.substr(0, str2.length())) {
        return false;
    }
    mismatch_size = str1.length() - str2.length();
    return true;
}

void match_morse(std::string &word) {
    int min_mismatch_len = 0x3fffff, mismatch_len = 0x3fffff;
    std::string ret;
    for (std::map<std::string, std::string>::iterator it = dict.begin(); it != dict.end(); ++it) {
        if (decode(it->second, word, mismatch_len)) {
            if (mismatch_len < min_mismatch_len) {
                min_mismatch_len = mismatch_len;
                ret = it->first;
            } else if (mismatch_len == min_mismatch_len && mismatch_len == 0 && *(ret.rbegin()) != '!') {
                ret += "!";
            }
        }
    }
    if (min_mismatch_len)
        ret += "?";
    std::cout << ret << "\n";
}


int main() {
    read_morse_code();
    read_word();
    std::string word;
    while (std::cin >> word && word != "*") {
        match_morse(word);
    }
    return 0;
}