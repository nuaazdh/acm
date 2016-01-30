//
// Created by luerfeng on 2016/01/28.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>
#include <map>

#define  MAX_HEIGHT (210)
#define  MAX_WIDTH (60*4)

char map[MAX_HEIGHT][MAX_WIDTH];
char line[MAX_HEIGHT];

int dr[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};
int height, width;
char dict[] = "WAKJSD";

int hex2dec(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'f') {
        return 10 + c - 'a';
    } else {
        return 10 + c - 'A';
    }
}

int is_valid_pos(int i, int j) {
    return (i >= 0 && i < height && j >= 0 && j < width);
}

void print_map(int h, int w) {
    int i, j;
    for (i = 0; i < h; ++i) {
        for (j = 0; j < w; ++j) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int i, int j, char find, char set) {
    int di;
    map[i][j] = set;
    for (di = 0; di < 4; ++di) {
        if (is_valid_pos(i + dr[di], j + dc[di]) && map[i + dr[di]][j + dc[di]] == find) {
            dfs(i + dr[di], j + dc[di], find, set);
        }
    }
}

void dfs_character(int i, int j, int &hole) {
    int di;
    map[i][j] = ' ';
    for (di = 0; di < 4; ++di) {
        if (is_valid_pos(i + dr[di], j + dc[di]) && map[i + dr[di]][j + dc[di]] == '0') {
            ++hole;
            dfs(i + dr[di], j + dc[di], '0', ' ');
        }
        if (is_valid_pos(i + dr[di], j + dc[di]) && map[i + dr[di]][j + dc[di]] == '1') {
            dfs_character(i + dr[di], j + dc[di], hole);
        }
    }
}


void find_character_count(int kcase) {
    int i, j;
    int hole;
    std::map<char, int> result;
    // clear backgroud
    for (j = 0; j < width; ++j) {
        if (map[0][j] == '0') dfs(0, j, '0', ' ');
        if (map[height - 1][j] == '0') dfs(height - 1, j, '0', ' ');
    }
    for (i = 0; i < height; ++i) {
        if (map[i][0] == '0') dfs(i, 0, '0', ' ');
        if (map[i][width - 1] == '0') dfs(i, width - 1, '0', ' ');
    }
    // find the symbol
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            hole = 0;
            if (map[i][j] == '1') {
                dfs_character(i, j, hole);
                if (result.count(dict[hole])) {
                    ++result[dict[hole]];
                } else {
                    result[dict[hole]] = 1;
                }
            }
        }
    }
    printf("Case %d: ", kcase);
    for (std::map<char, int>::iterator it = result.begin(); it != result.end(); ++it) {
        for (i = 0; i < it->second; ++i)
            printf("%c", it->first);
    }
    printf("\n");
}

int main() {
    int h, w, i, j, num, kcase = 0;
    while (scanf("%d%d", &h, &w) && h) {
        memset(map, 0, sizeof(map));
        height = h;
        width = 4 * w;
        for (i = 0; i < h; ++i) {
            scanf("%s", line);
            for (j = 0; j < w; ++j) {
                num = hex2dec(line[j]);
                map[i][4 * j] = (num & (1 << 3)) ? '1' : '0';
                map[i][4 * j + 1] = (num & (1 << 2)) ? '1' : '0';
                map[i][4 * j + 2] = (num & (1 << 1)) ? '1' : '0';
                map[i][4 * j + 3] = (num & 0x01) ? '1' : '0';
            }
        }
//        print_map(height,width);
        find_character_count(++kcase);
    }
    return 0;
}