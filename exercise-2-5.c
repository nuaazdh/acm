//
//  exercise-2-5.c
//  acm
//
//  Created by luerfeng on 15/12/21.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a,b,c;
    while (scanf("%d%d%d",&a,&b,&c) == 3) {
        if(b==0)
            break;
        printf("%d.",a/b);
        double res = a*1.0/b-a/b;
        for (int i =0; i<c; ++i) {
            res *= 10;
        }
        printf("%.f\n", res);
    }
    return 0;
}