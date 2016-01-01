/*
//  exercise-3-9-UVa10340.c
//  acm
//
//  Created by luerfeng on 15/12/30.
//  Copyright © 2015年 luerfeng. All rights reserved.
*/
/*
 tpos < tlen && t[tpos] != s[spos] 顺序不能颠倒
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 10000

char s[MAX_LEN];
char t[MAX_LEN];

int main()
{
    int slen, tlen, spos, tpos;
    while (scanf("%s",s) != EOF) {
        scanf("%s",t);
        slen = strlen(s), tlen = strlen(t);
        if(slen>tlen)
        {
            printf("No\n");continue;
        }
        tpos = 0;
        for (spos=0; spos<slen; ++spos,++tpos) {
            while ( tpos < tlen && t[tpos] != s[spos]) tpos++;
            if(tpos >= tlen){
                printf("No\n"); break;
            }
        }
        if(spos>=slen)
            printf("Yes\n");
    }
    return 0;
}