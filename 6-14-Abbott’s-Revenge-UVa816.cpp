//
// Created by luerfeng on 2016/01/29.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>

std::map<char, int> direction;
std::map<char, int> instruction;
char arrow[4][3] = {{'N', 'W', 'E'},
                    {'E', 'N', 'S'},
                    {'W', 'S', 'N'},
                    {'S', 'E', 'W'}};
std::vector<int> intersection[32][32][4];
int enter_r, enter_c, goal_r, goal_c;


void init_direction() {
    direction['N'] = 0;
    direction['E'] = 1;
    direction['W'] = 2;
    direction['S'] = 3;
}

void init_arrow() {
    instruction['F'] = 0;
    instruction['L'] = 1;
    instruction['R'] = 2;
}

int get_direction(char c) {
    if (direction.count(c))
        return direction[c];
    else
        return -1;
}

int get_arrow(char c) {
    if (instruction.count(c))
        return instruction[c];
    else
        return -1;
}

char get_next_direction(char d, char a) {
    return arrow[get_direction(d)][get_arrow(a)];
}

int move_next(int r, int c, char d) {
    if (d == 'N') --r;
    else if (d == 'S') ++r;
    else if (d == 'W') --c;
    else if (d == 'E') ++c;
    else return -1;
    return r * 100 + c * 10 + get_direction(d);
}

bool is_valid_pos(int pos) {
    return pos >= 110 && pos <= 993;
}

int read_maze() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 4; ++k) {
                intersection[i][j][k].clear();
            }
        }
    }
    int r, c, dir, i, valid = 1, next_pos;
    char ins[10];
    while (scanf("%d%d", &r, &c) && r) {
        ++valid;
        while (scanf("%s", ins) && ins[0] != '*') {
            size_t len = strlen(ins);
            if ((dir = get_direction(ins[0])) == -1) {
                valid = 0;
                continue;
            }
            for (i = 1; i < len; ++i) {
                if (get_arrow(ins[i]) == -1) {
                    valid = 0;
                    continue;
                }
                char next_d = get_next_direction(ins[0], ins[i]);
                next_pos = move_next(r, c, next_d);
                if (is_valid_pos(next_pos))
                    intersection[r][c][dir].push_back(next_pos);
            }
        }
    }
    return valid;
}


void solve_maze() {
    char direction;
    scanf("%d %d %c %d %d", &enter_r, &enter_c, &direction, &goal_r, &goal_c);
    int node = read_maze();
    std::vector<int> path;
    std::vector<int> prev;
    int current_pos = move_next(enter_r, enter_c, direction);
    if (current_pos / 100 == goal_r && current_pos % 100 / 10 == goal_c) {
        printf("  (%d,%d) (%d,%d)\n", enter_r, enter_c, goal_r, goal_c);
        return;
    }
    if (node == 0 || !is_valid_pos(current_pos)) {
        printf("  No Solution Possible\n");
        return;
    }

    std::queue<int> queue;
    std::queue<int> p_queue;
    queue.push(current_pos);
    p_queue.push(0);
    while (!queue.empty()) {
//        for (int i = 0; i < path.size(); ++i) {
//            printf("p:%d  current: (%d) \n", path[prev[i]], path[i]);
//        }
//        printf("\n");

        current_pos = queue.front();
//        printf("current:%d %d %d\n", current_pos / 100, current_pos % 100 / 10, current_pos % 10);
//        if(!is_valid_pos(current_pos)) break;
        path.push_back(current_pos);
        prev.push_back(p_queue.front());
        if (current_pos / 100 == goal_r && current_pos % 100 / 10 == goal_c) {
            std::vector<int> result;
            for (int i = prev.size() - 1; i != 0; i = prev[i]) {
                result.push_back(path[i]);
            }
            result.push_back(path[0]);
            result.push_back(enter_r * 100 + enter_c * 10 + get_direction(direction));
            for (int j = result.size() - 1, i = 1; j >= 0; --j, ++i) {
                if (i % 10 != 1) {
                    printf(" ");
                } else {
                    printf("  ");
                }
                printf("(%d,%d)", result[j] / 100, result[j] % 100 / 10);
                if (i % 10 == 0 && j != 0) printf("\n");
            }
            printf("\n");
            return;
        }
        int p = path.size() - 1;
        std::vector<int> next = intersection[current_pos / 100][current_pos % 100 / 10][current_pos % 10];
        for (int i = 0;
             i < next.size(); ++i) {
            if (std::find(path.begin(), path.end(), next[i]) == path.end()) {
                queue.push(next[i]);
                p_queue.push(p);
            }
        }
        queue.pop();
        p_queue.pop();
    }
    if (current_pos / 100 != goal_r || current_pos % 100 / 10 != goal_c) {
        printf("  No Solution Possible\n");
        return;
    }
}


int main() {
    std::string name;
    init_direction();
    init_arrow();
    while (getline(std::cin, name) && name != "END") {
        std::cout << name << "\n";
        solve_maze();
    }
    return 0;
}
