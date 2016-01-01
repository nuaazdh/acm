//
//  exercise-2-2.c
//  acm
//
//  Created by luerfeng on 15/12/21.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    int kcase = 1;
    while (1) {
        int a,b,c;
        if(scanf("%d%d%d", &a, &b, &c)!=3)
            break;
        int flag = 1;
        for (int i=10; i<=100; ++i) {
            if(i%3 ==a && i%5==b && i%7 == c){
                flag = 0;
                printf("Case %d:%d\n", kcase++, i);
                break;
            }
        }
        if(flag)
            printf("Case %d:No answer\n", ++kcase);
    }
}