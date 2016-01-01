//
//  2-4-sum-order.c
//  acm
//
//  Created by luerfeng on 15/12/20.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    const int reserve = 1000000;
    int n;
    int s=0;
    int order = 1;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        if(i>25)
            break;
        order *= i;
        s += order;
        order %= reserve;
        s %= reserve;
    }
    printf("%d\n",s%reserve);
    return 0;
}