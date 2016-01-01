//
//  exercise-2-6.c
//  acm
//
//  Created by luerfeng on 15/12/21.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    for (int i=100; i<333; ++i) {
        int a,b,c,d,e,f,g,h,i;
        a=i/100;
        b=i%100/10;
        c=i%10;
        d=2*i/100;
        e=2*i%100/10;
        f=2*i%10;
        g=3*i/100;
        h=3*i%100/10;
        i=3*i%10;
        if (!(a^b && b^c && c^d && d^e && e^f && f^g)) {
            continue;
        }
        printf("%d %d %d\n",i,2*i, 3*i);
    }
}