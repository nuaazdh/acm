//
//  4-0-1-combination.c
//  acm
//
//  Created by luerfeng on 16/1/1.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

/*
 给定m 和 n 计算组合数
 */
#include <stdio.h>

int order(int n)
{
    if(n==0) return 1;
    int res = 1;
    while (n>1) {
        res *= n--;
    }
    return res;
}

int combo(int m, int n)
{
    if(m>n/2) m=n-m;
    int prod = 1;
    for (int i=0; i<m; ++i) {
        prod = ((n-i)*prod)/(i+1);
    }
    return prod;
}

int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    printf("%d\n", combo(m, n));
    return 0;
    
}