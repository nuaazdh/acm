//
//  2-1-aabb-squre-number.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    for (int i=30;;++i) {
        int m=i*i;
        if(i*i<1000)
            continue;
        if(i*i>9999)
            break;
        int high = m/100, low = m%100;
        if((high/10==high%10) && (low%10 == low/10))
            printf("%d\n",m);
    }
    return 0;
}