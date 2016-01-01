//
//  exercise-2-4.c
//  acm
//
//  Created by luerfeng on 15/12/21.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n,m;
    int k=0;
    while (scanf("%d%d",&n,&m) == 2) {
        if(m==0 || n==0)
            break;
        double sum=0;
        while (n<=m) {
            sum += 1.0/n*1.0/n;
            n++;
        }
        printf("Case %d:%.5f\n", ++k, sum);
    }
    return 0;
}