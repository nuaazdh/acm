//
//  4-3-The-Dole-Queue.c
//  acm
//
//  Created by luerfeng on 16/1/1.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int trainee[20];

void choose(int n, int k, int m)
{
    memset(trainee,1,sizeof(trainee));
    int rest = n;
    int i=0,j=n-1;
    while (rest) {
        int p=0,q=0;
        for (; ; i=(i+n+1)%n) {
            if(trainee[i%n])
                p++;
            if(p==k) break;
        }
        for (; ; j = (n+j-1)%n) {
            if(trainee[j])
                q++;
            if(q==m) break;
        }
        trainee[i] = trainee[j] = 0;
        if (i==j) {
            printf("%3d",i+1);
            --rest;
        }else{
            printf("%3d%3d",i+1,j+1);
            rest -= 2;
        }
        if(rest>=1)
            printf(",");
    }
    printf("\n");
}


int main()
{
    int n,k,m;
    while (scanf("%d%d%d",&n,&k,&m) == 3 && n!=0) {
        choose(n,k,m);
    }
    return 0;
}