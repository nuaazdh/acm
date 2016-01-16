//
//  4-0-2-prime.c
//  acm
//
//  Created by luerfeng on 16/1/1.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <math.h>


int is_prime(int n)
{
    if(n==1){
        return 0;
    }else if(n==2){
        return 1;
    }else{
        for (int i=2; i<(int)sqrt(n)+1; ++i) {
            if(n%i == 0)
            {
                return 0;
            }
        }//for
        return 1;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    if(is_prime(n))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}