//
//  exercise-1-5.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double price = n*95.0;
    if(n*95>300)
        price *= 0.85;
    printf("%.3f\n", price);
    return 0;
}