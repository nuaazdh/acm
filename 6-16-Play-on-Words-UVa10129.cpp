//
// Created by luerfeng on 2016/01/31.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stack>

const int alpha_size = 26;
int graph[alpha_size][alpha_size], visit[alpha_size], first[alpha_size], last[alpha_size];


void dfs(int v, std::stack<int> &stack) {
    visit[v] = 1;
    for (int i = 0; i < alpha_size; ++i) {
        if (graph[v][i] && !visit[i])
            dfs(i, stack);
    }
    stack.push(v);
}

void dfs2(int v) {
    visit[v] = 1;
    for (int i = 0; i < alpha_size; ++i) {
        if (graph[v][i] && !visit[i])
            dfs2(i);
    }
}

int check_scc() {
    memset(visit, 0, sizeof(visit));
    std::stack<int> stack;
    for (int i = 0; i < alpha_size; ++i) {
        if ((first[i] | last[i]) && !visit[i])
            dfs(i, stack);
    }
    memset(visit, 0, sizeof(visit));
    if (!stack.empty()) {
        int top = stack.top();
        stack.pop();
        dfs2(top);
        while (!stack.empty() && visit[stack.top()]) stack.pop();
    }
    return stack.empty();
}

int check_degree() {
    int in_out_not_equal_cnt = 0;
    for (int i = 0; i < alpha_size; ++i) {
        if ((first[i] - last[i] > 1) || (last[i] - first[i] > 1)) {
            return 0;
        }
        if (first[i] != last[i]) ++in_out_not_equal_cnt;
        if (in_out_not_equal_cnt > 2) {
            return 0;
        }
    }
    return 1;
}


int main() {
    int T;
    std::cin >> T;
    std::string impossible = "The door cannot be opened.\n", possible = "Ordering is possible.\n";
    while (T--) {
        int n;
        std::cin >> n;
        memset(graph, 0, sizeof(graph));
        memset(first, 0, sizeof(first));
        memset(last, 0, sizeof(last));
        std::string word;
        while (n--) {
            std::cin >> word;
            if (!word.empty()) {
                int start = tolower(word[0]) - 'a', ends = tolower(word[word.length() - 1]) - 'a';
                ++graph[start][ends];
                ++first[start];
                ++last[ends];
            }
        }
        if (check_scc() && check_degree()) {
            std::cout << possible;
        } else {
            std::cout << impossible;
        }
    }
}