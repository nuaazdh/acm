//
//  3-7-master-mind.c
//  acm
//
//  Created by luerfeng on 15/12/23.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 1000

int main()
{
    int count = 0;
    int n;
    while ((scanf("%d", &n) == 1) && n) {
        printf("Game %d:\n", ++count);
        int ans[ARRAY_SIZE];
        int guess[ARRAY_SIZE];
        for (int i=0; i<n; ++i)  scanf("%d", &ans[i]);
        while (1) {
            int A = 0, B = 0;
            for (int i=0; i<n; ++i) {
                scanf("%d", &guess[i]); // 输入和统计可以合并在一起
                if (guess[i] == ans[i])  A++;
            }
            if(guess[0] == 0) break;
            for (int d = 1; d<=9; d++) {
                int c1 = 0, c2 = 0;
                for (int i=0; i<n; ++i) {
                    if(ans[i] == d) c1++;
                    if(guess[i] == d) c2++;
                }
                if(c1<c2) B+= c1; else B+= c2;
            }
            printf(" (%d,%d)\n", A, B-A);
        }//while
    }
    return 0;
}