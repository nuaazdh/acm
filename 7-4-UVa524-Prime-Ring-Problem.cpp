//
// Created by luerfeng on 2016/02/19.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>
#include <algorithm>

const int max_size = 20;
int A[max_size], visit[max_size];

int is_prime(int number) {
    if (number < 4)
        return 1;
    if (!number & 0x01)
        return 0;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

void dfs(int cur, int n) {
    if (cur == n && is_prime(A[1] + A[n])) {
        for (int i = 1; i <= n; ++i) {
            if (i > 1) printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    } else {
        for (int i = 2; i <= n; ++i) {
            if (!visit[i] && is_prime(i + A[cur])) {
                visit[i] = 1;
                A[cur + 1] = i;
                dfs(cur + 1, n);
                visit[i] = 0;
            }
        }
    }

}

int main() {
    int kcase = 0;
    int n;
    while (scanf("%d", &n) == 1) {
        if (kcase) printf("\n");
        printf("Case %d:\n", ++kcase);
        if (n < 3) {
            for (int i = 1; i <= n; ++i) {
                if (i > 1) printf(" ");
                printf("%d", i);
            }
            printf("\n");
            continue;
        }
        if (n >= 3 && n & 0x01) { // no solution
//            printf("\n");
            continue;
        }
        memset(visit, 0, sizeof(visit));
        memset(A, 0, sizeof(A));
        A[1] = 1;
        visit[1] = 1;
        dfs(1, n);
    }

}