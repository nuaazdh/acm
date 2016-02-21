//
// Created by luerfeng on 2016/02/20.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <stdio.h>
#include <string.h>

const int max_size = 100;

int ith = 0;
int n, L;
char solution[max_size];

int is_hars_seq() {
    int len = strlen(solution), i, j;
    if (len < 2)
        return 1;
    for (i = 1; 2 * i <= len; ++i) {
        int ok = 1;
        for (j = len - 2 * i; j >= 0 && j < len - i; ++j) {
            if (solution[j] != solution[j + i]) {
                ok = 0;
                break;
            }
        }
        if (ok)
            return 0;
    }
    return 1;
}

void dfs(int cur) {
    for (int i = 0; i < L && ith < n; ++i) {
        solution[cur] = (char) ('A' + i);
//        printf("%d:%s\n", ith, solution);
        if (is_hars_seq()) {
            if (++ith >= n) {
                int len = strlen(solution);
                for (int j = 0; j < len; ++j) {
                    if (j && (j % 4 == 0) && (j % 64 != 0)) printf(" ");
                    printf("%c", solution[j]);
                    if (j && ((j + 1) % 64 == 0)) printf("\n");
                }
                if (len % 64) printf("\n");
                printf("%d\n", len);
                break;
            }
            dfs(cur + 1);
        }
        solution[cur] = 0;
    }
}


int main() {
    while (scanf("%d%d", &n, &L) == 2 && n) {
        memset(solution, 0, sizeof(solution));
        ith = 0;
        dfs(0);
    }
    return 0;
}
