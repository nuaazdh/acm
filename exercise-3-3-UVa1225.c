//
//  exercise-3-3-UVa1225.c
//  acm
//
//  Created by luerfeng on 15/12/25.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int main()
{
    int count[10];
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(count, 0, sizeof(count));
        int n;
        scanf("%d", &n);
        for (int i=1; i<=n; ++i) {
            int m = i;
            while (m) {
                count[m%10]++;
                m/=10;
            }
        }
        for (int i=0; i<9; i++) {
            printf("%d ",count[i]);
        }
        printf("%d\n", count[9]);
    }
}