//
//  1-5-sort-3-numbers.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int max(int a, int b);

int main()
{
    int m,n,p;
    int ma,mid,min;
    scanf("%d%d%d", &m, &n, &p);
    if(m>n)
    {
        ma = m;
        mid = n;
    }else{
        ma = n;
        mid = m;
    }
    if(ma < p)
    {
        min = ma;
        ma = p;
    }else{
        min = p;
    }
    printf("%d %d %d\n", (min<mid)?min:mid, (min<=mid?mid:min), ma);
    return 0;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
