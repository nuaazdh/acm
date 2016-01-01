//
//  3-2-snake-shape-squre.c
//  acm
//
//  Created by luerfeng on 15/12/22.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SQURE_SIZE 10

int snake[SQURE_SIZE][SQURE_SIZE];

int main()
{
    int n;
    scanf("%d", &n);
    memset(snake, 0, sizeof(snake));
    int num = 1;
    for (int i=1; i<=(n/2+1); ++i) {
        for (int j=i; j<=n-(i-1); ++j) {
            snake[j][n-(i-1)] = num++;
        }
        if (num>n*n) break;
        for (int j=n-i; j>=i; --j) {
            snake[n-(i-1)][j] = num++;
        }
        if(num>n*n) break;
        for (int j=n-i; j>=i; --j) {
            snake[j][i] = num++;
        }
        if(num>n*n) break;
        for (int j=i+1; j<=n-i; j++) {
            snake[i][j] = num++;
        }
        if(num > n*n) break;
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            printf("%d ", snake[i][j]);
        }
        printf("\n");
    }
    return 0;
}