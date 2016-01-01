//
//  3-1-open-light.c
//  acm
//
//  Created by luerfeng on 15/12/22.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_LIGHT 1010
int light[MAX_LIGHT];

int main()
{
    memset(light,0,sizeof(light));
    int n,k;
    scanf("%d%d", &n, &k);
    for (int i=1; i<=k; ++i) {
        for (int j=i; j<=n; j+=i) {
            light[j] ^= 1;
        }
    }
    int first = 1;
    for (int i=1; i<=n; ++i) {
        if(light[i] != 1)
            continue;
        if(first)
        {
            first = 0;
            printf("%d", i);
        }else{
            printf(" %d",i);
        }
    }
    printf("\n");
    return 0;
}
