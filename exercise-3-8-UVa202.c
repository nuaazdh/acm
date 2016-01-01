//
//  exercise-3-8-UVa202.c
//  acm
//
//  Created by luerfeng on 15/12/30.
//  Copyright © 2015年 luerfeng. All rights reserved.
//
/*
 多次提交均因为格式错误，每行输出以后换行，而不是第一行以外的行加空行
 */

#include <stdio.h>
#include <string.h>

#define PRECISION 10000

char number[PRECISION];
int rd[PRECISION];

int main()
{
    int a,b,c;
    memset(number,0,sizeof(number));
    memset(rd,0,sizeof(rd));
    while(scanf("%d%d", &a,&b) != EOF){
        c = a;
        int i=0, first = 0;
        while (1) {
            a = a%b;
            a *= 10;
            int found = 0;
            for (first=0; first<i;++first) {
                if(rd[first] == a ){
                    found = 1;
                    break;
                }
            }
            if(found) break;
            rd[i]=a;
            number[i++] = (a/b) + '0';
        }
        printf("%d/%d = %d",c,b, c/b);
        putchar('.');
        for (int j=0; j<i ; ++j) {
            if(first == j)
                putchar('(');
            putchar(number[j]);
            if(j + 1 >= 50){ printf("..."); break; }
        }
        putchar(')');
        printf("\n   %d = number of digits in repeating cycle\n\n",i-first);
    }
    return 0;
}