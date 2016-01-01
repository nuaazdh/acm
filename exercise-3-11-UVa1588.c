//
//  exercise-3-11-UVa1588.c
//  acm
//
//  Created by luerfeng on 15/12/31.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define STR_LEN 110

char s[STR_LEN];
char t[STR_LEN];

int main()
{
    while (scanf("%s",s)!=EOF) {
        scanf("%s",t);
        printf("s:%s\nt:%s\n",s,t);
        int slen = strlen(s), tlen=strlen(t), sr = 0,tr = 0,i,j;
        for (i=0; i<slen; ++i) {
            int p = i,q = 0;
            while(p<slen && q<tlen && (s[p]-'0'+t[q]-'0')<=3){p++;q++;}
            printf("p=%d,q=%d\n",p,q);
            if(p<slen && q<tlen) continue;
            if(p>=slen) {sr = slen+tlen-q; break;}
            sr = slen;
            break;
        }
        if(i>=slen){
            printf("%d\n",slen+tlen);
            continue;
        }
        printf("other\n");
        
        for (j=0; j<tlen; ++j) {
            int p=j, q=0;
            while(p<tlen && q<slen && (t[p]-'0'+s[q]-'0')<=3){p++;q++;}
            printf("p=%d,q=%d\n",p,q);
            if(p<tlen && q<slen) continue;
            if(p>=tlen) {tr = slen+tlen-q; break;}
            tr = tlen;
            break;

        }
        if(sr<tr)  sr = tr;
        printf("%d\n", tr);
    }
    return 0;
}