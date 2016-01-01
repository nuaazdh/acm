//
//  exercise-1-6.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>


int main()
{
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    if(a>=b+c || b>=a+c || c>=a+b)
        printf("not a triangle\n");
    else if(a*a == (b*b+c*c) || b*b==a*a+c*c || c*c==a*a+b*b)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}