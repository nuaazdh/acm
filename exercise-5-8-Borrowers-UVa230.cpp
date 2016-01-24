//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <set>


int main() {
    std::string line;
    std::map<std::string, int> bookname_id_map;
    std::set<std::string> author_title_set;
    std::vector<std::string> title_list;
    std::vector<int> book_status;
    std::priority_queue<int, std::vector<int>, std::greater<int> > ret;
    while (std::getline(std::cin, line)) {
        if (line[0] == 'E')
            break;
        size_t pos = line.find("by");
        author_title_set.insert(line.substr(pos + 3) + ":" + line.substr(0, pos - 1));
    }
    for (std::set<std::string>::iterator it = author_title_set.begin(); it != author_title_set.end(); ++it) {
        size_t pos = it->find_first_of(":");
        bookname_id_map[it->substr(pos + 1)] = title_list.size();
        title_list.push_back(it->substr(pos + 1));
        book_status.push_back(1);
    }

    while (std::getline(std::cin, line)) {
        if (line[0] == 'E')
            break;
        if (line[0] == 'R') {
            size_t pos = line.find_first_of(' ');
            ret.push(bookname_id_map[line.substr(pos + 1)]);
        } else if (line[0] == 'B') {
            size_t pos = line.find_first_of(' ');
            book_status[bookname_id_map[line.substr(pos + 1)]] = 0;
        } else {
            while (!ret.empty()) {
                int i;
                for (i = ret.top(); i > 0 && (book_status[i] == 0); --i);
                if (i == 0 && book_status[i] == 0) {
                    std::cout << "Put " << title_list[ret.top()] << " first\n";
                } else {
                    std::cout << "Put " << title_list[ret.top()] << " after " << title_list[i] << std::endl;
                }
                book_status[ret.top()] = 1;
                ret.pop();
            }
            std::cout << "END\n";
        }
    }
    return 0;
}