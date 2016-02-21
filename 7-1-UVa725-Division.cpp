//
// Created by luerfeng on 2016/02/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <stdio.h>
#include <string.h>

int check_valid(char *s) {
    int a[10] = {0};
    while (*s != '\0') {
        a[*s - '0']++;
        if (a[*s - '0'] > 1)
            return 0;
        ++s;
    }
    return 1;
}


int main() {
    int N;
    char buff[20];
    int kcase = 0;
    while (scanf("%d", &N) && N) {
        if(kcase++) printf("\n");
        memset(buff, 0, sizeof(buff));
        int found = false;
        for (int i = 1234; i <= 50000; ++i) {
            sprintf(buff, "%05d%05d", i, i * N);
            if (check_valid(buff)) {
                found = true;
                printf("%05d / %05d = %d\n", i * N, i, N);
            }
        }
        if (!found) {
            printf("There are no solutions for %d.\n", N);
        }
    }
    return 0;
}