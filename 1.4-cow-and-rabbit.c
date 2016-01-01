//
//  1.c
//  acm
//
//  Created by luerfeng on 15/12/19.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    if(m<=0 || n<=0 || (n-2*m) < 0 || n%2!=0)
    {
        printf("No answer");
    }else{
        printf("%d %d", n-(n-2*m)/2, (n-m*2)/2);
    }
    return 0;
}