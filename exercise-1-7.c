//
//  exercise-1-7.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    int year;
    scanf("%d",&year);
    if(year%400 == 0)
        printf("yes\n");
    else if(year%100==0)
        printf("no\n");
    else if(year%4==0)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}