//
//  exercise-2-1.c
//  acm
//
//  Created by luerfeng on 15/12/21.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    for (int i=100; i<1000; ++i) {
        if(i == (i/100)*(i/100)*(i/100) + (i%100/10)*(i%100/10)*(i%100/10)
           +(i%10)*(i%10)*(i%10))
            printf("%i\n", i);
    }
    return 0;
}