//
//  3-8-digit-generator.c
//  acm
//
//  Created by luerfeng on 15/12/24.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define SIZE 100005
int table[SIZE];

int main()
{
    memset(table, 0, sizeof(table));
    for (int m=0; m<SIZE; ++m) {
        int x = m, y = m;
        while (x) {
            y += x%10; x/=10;
        }
        if (table[y] ==0 || table[y] > m) table[y] = m;
    }
    int n;
    scanf("%d", &n);
    while (n--) {
        int d;
        scanf("%d", &d);
        printf("%d\n", table[d]);
    }
    return 0;
}