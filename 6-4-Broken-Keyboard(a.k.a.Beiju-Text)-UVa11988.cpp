//
// Created by luerfeng on 2016/01/23.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100010

int next[MAX_LEN];
char line[MAX_LEN];

int main() {
    int len, i, cur = 0, last = 0;
    while (scanf("%s", line + 1) != EOF) {
        len = strlen(line + 1);
        cur = 0, last = 0, next[0] = 0;
        for (i = 1; i <= len; ++i) {
            if (line[i] == '[') {
                cur = 0;
            } else if (line[i] == ']') {
                cur = last;
            } else {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last) last = i;
                cur = i;
            }
        }
        for (i = next[0]; i != 0; i = next[i]) {
            printf("%c", line[next[i]]);
        }
        printf("\n");
    }
    return 0;
}