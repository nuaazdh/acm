//
//  2-3-approximate-calculation.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    double result = 1.0;
    for (int i=1; ; ++i) {
        double term = 1.0/(2*i+1);
        if(i&1) result -= term;
        else result += term;
        if(2*i+1>1000000) break;
    }
    
    printf("%.6f\n", result);
    return 0;
}
