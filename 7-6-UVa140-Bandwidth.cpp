//
// Created by luerfeng on 2016/02/20.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctype.h>
#include <algorithm>

const int max_size = 27;

char visit[max_size];
int G[max_size][max_size];
char solution[max_size];
char best[max_size];
int min_width = 0;

int distance_node(char *s, char a, char b) {
    int ia = 0, ib = 0;
    size_t len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == a) ia = i;
        if (s[i] == b) ib = i;
    }
    return (ia < ib) ? (ib - ia) : (ia - ib);
}


int bandwidth(std::vector<char> &vertex) {
    int width = 0;
    for (int i = 0; i < vertex.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (G[vertex[i] - 'A'][j] &&
                strchr(solution, vertex[i]) != NULL &&
                strchr(solution, ('A' + j)) != NULL) {
                int w = distance_node(solution, vertex[i], char('A' + j));
                if (w > width)
                    width = w;
            }
        }
    }
    return width;
}

void dfs(int cur, std::vector<char> &vertex) {
    if (cur == vertex.size()) {
        int width = bandwidth(vertex);
        if (width < min_width) {
            strncpy(best, solution, max_size - 1);
            min_width = width;
        }
    } else
        for (int i = 0; i < vertex.size(); ++i) {
            if (!visit[i]) {
                visit[i] = 1;
                solution[cur] = vertex[i];
                if (bandwidth(vertex) <= min_width) {
                    dfs(cur + 1, vertex);
                }
                solution[cur + 1] = 0;
                visit[i] = 0;
            }
        }
}


int main() {
    char buff[1024];
    while (scanf("%s", buff) && buff[0] != '#') {
        memset(G, 0, sizeof(G));
        memset(solution, 0, sizeof(solution));
        memset(best, 0, sizeof(best));
        memset(visit, 0, sizeof(visit));
        std::vector<char> vertex;
        min_width = 0x3fff;
        char v;
        for (int i = 0; buff[i] != '\0'; ++i) {
            v = buff[i++];
            if (std::find(vertex.begin(), vertex.end(), v) == vertex.end())
                vertex.push_back(v);
            while (buff[++i] != '\0' && buff[i] != ';') {
                if (std::find(vertex.begin(), vertex.end(), buff[i]) == vertex.end())
                    vertex.push_back(buff[i]);
                G[v - 'A'][buff[i] - 'A'] = G[buff[i] - 'A'][v - 'A'] = 1;
            }
        }
        std::sort(vertex.begin(), vertex.end());
        dfs(0, vertex);
        for (int i = 0; i < strlen(best); ++i) {
            if (i) printf(" ");
            printf("%c", best[i]);
        }
        printf(" -> %d\n", min_width);
    }
    return 0;
}