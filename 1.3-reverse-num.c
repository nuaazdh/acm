//
//  reverse_num.cpp
//  acm
//
//  Created by luerfeng on 15/12/18.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
    printf("%d%d%d\n",a%10,a/10%10,a/100);
    return 0;
}