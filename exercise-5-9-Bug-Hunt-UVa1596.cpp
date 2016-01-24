//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <map>
#include <stack>
#include <vector>

std::map<std::string, int> variable_size_map;
std::map<std::string, int> variable_value_map;
std::vector<std::string> cmd;

std::string get_variable(std::string &s) {
    size_t pos1 = s.find_first_of('[');
    if (pos1 == std::string::npos)
        return s;
    std::string out = s.substr(0, pos1);
    s = s.substr(pos1 + 1);
    size_t pos2 = s.find_last_of(']');
    s = s.substr(0, pos2);
    return out;
}

bool get_value(std::string &s, int &value) {
    if (!isalpha(s[0])) {
        value = std::stoi(s);
        return true;
    }
    std::string variable_name;
    std::stack<std::string> variable_stack;

    while (isalpha(s[0])) {
        variable_name = get_variable(s);
        if (!variable_size_map.count(variable_name))
            return false;
        variable_stack.push(variable_name);
    }
    value = std::stoi(s);
    while (!variable_stack.empty()) {
        s = variable_stack.top() + "[" + std::to_string(value) + "]";
        if (! variable_value_map.count(s) || value >= variable_size_map[variable_stack.top()])
            return false;
        value = variable_value_map[s];
        variable_stack.pop();
    }
    return true;
}


void read_cmd() {
    std::string line;
    while (std::getline(std::cin, line)) {
        cmd.push_back(line);
    }
}


int main() {
    std::string line;
    while (std::getline(std::cin, line) && line[0]!='.') {
        variable_size_map.clear();
        variable_value_map.clear();
        bool flag = true;
        int line_no = 1;
        do {
            if(line[0]=='.')
                break;
            size_t pos = line.find("=");
            if (pos == std::string::npos) { //declaration
                std::string variable_name = get_variable(line);
                int value_size;
                if (variable_size_map.count(variable_name) || !get_value(line, value_size)) {
                    flag = false;
                    break;
                }
                variable_size_map[variable_name] = value_size;
            } else {  //assignment
                //left
                std::string right = line.substr(pos + 1);
                std::string left = line.substr(0, pos);
                int left_v, right_v;

                if (false == get_value(right, right_v)  ) {
                    flag = false;
                    break;
                }
                std::string left_variable = get_variable(left);
                if (!variable_size_map.count(left_variable) || false == get_value(left, left_v) ||
                    left_v >= variable_size_map[left_variable]) {
                    flag = false;
                    break;
                }
                variable_value_map[left_variable+"["+std::to_string(left_v)+"]"] = right_v;
            }
            line_no++;
        }while(std::getline(std::cin, line) && line[0]!='.');
        if (flag == false) {
            std::cout << line_no << std::endl;
            while(std::getline(std::cin, line) && line[0]!='.');
        } else {
            std::cout << "0\n";
        }
    }//while(1)
}