
//
//  exercise-1-4.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main()
{
    const double pi = acos(-1.0);
    int n;
    scanf("%d", &n);
    printf("%.3f %.3f\n", sin(n*2*pi/360.0), cos(n*2*pi/360.0));
    return 0;
}
