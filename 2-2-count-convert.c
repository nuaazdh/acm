//
//  2-2-count-convert.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld",&n);
    int count = 0;
    while (n!=1) {
        if(n&1)
            n = 3*n+1;
        else
            n = n/2;
        count++;
    }
    printf("%d\n",count);
    return 0;
}