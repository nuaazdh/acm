//
// Created by luerfeng on 2016/01/23.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <queue>

std::vector<std::string> parse_sentance(std::string line) {
    std::vector<std::string> sv;
    std::stringstream ss(line);
    std::string word;
    while (ss >> word) {
        sv.push_back(word);
    }
    return sv;
}


int main() {
    int T, P;
    std::cin >> T;
    while (T--) {
        bool has_thread_in_lock = false;
        std::deque<int> ready;
        std::queue<int>block;
        int execute_time[5], quantum;
        int variable_table[26] = {0};
        int execute_line[15] = {0};
        int running;
        std::vector<std::string> program[15];

        std::cin >> P;
        for (int i = 0; i < 5; ++i) {
            std::cin >> execute_time[i];
        }
        std::cin >> quantum;
        for (int i = 0; i < P; ++i) {
            std::string line;
            do {
                std::getline(std::cin, line);
                if (line.empty())
                    continue;
                program[i].push_back(line);
            } while (line != "end");
            ready.push_back(i);
        }
        while (!ready.empty()) {
            running = ready.front();
            ready.pop_front();
            int rest = quantum; // rest of execute time
            while (rest > 0) {
                std::string cmd = program[running][execute_line[running]];
                std::vector<std::string> sentance = parse_sentance(cmd);
                if (sentance.size() == 3) { // assignment
                    variable_table[sentance[0][0] - 'a'] = std::stoi(sentance[2]);
                    rest -= execute_time[0];
                } else if (sentance.size() == 2) { // print
                    std::cout << running + 1 << ": " << variable_table[sentance[1][0] - 'a'] << std::endl;
                    rest -= execute_time[1];
                } else if (sentance[0] == "lock") { // lock, unlock, end
                    if (has_thread_in_lock == false) {
                        has_thread_in_lock = true;
                        rest -= execute_time[2];
                    } else {
                        block.push(running);
                        break;
                    }
                } else if (sentance[0] == "unlock") {
                    has_thread_in_lock = false;
                    if (!block.empty()) {
                        ready.push_front(block.front());
                        block.pop();
                    }
                    rest -= execute_time[3];
                } else {
                    break;
                }//if
                execute_line[running]++;
            }//while(rest>0)
            if (rest == 0) {
                ready.push_back(running);
            }
        }//while
        if(T) std::cout<<"\n";
    }//while(T--)
}


