//
//  4-1-Ancient-Cipher-UVa1339.c
//  acm
//
//  Created by luerfeng on 16/1/1.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define STR_LEN 110

char a[STR_LEN];
char b[STR_LEN];

#define ALPHA_SIZE 26
int count_a[ALPHA_SIZE];
int count_b[ALPHA_SIZE];

void sort_int(int* a, int len)
{
    for (int i=0; i<len; ++i) {
        for (int j=i; j<len; ++j) {
            if(a[j] > a[i])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int is_cipher(char *s, char* t, int len)
{
    memset(count_a, 0, sizeof(count_a));
    memset(count_b, 0, sizeof(count_b));
    for (int i=0; i<len; ++i) {
        count_a[s[i]-'A']++;
        count_b[t[i]-'A']++;
    }
    sort_int(count_a, ALPHA_SIZE);
    sort_int(count_b, ALPHA_SIZE);
    for (int i=0; i<ALPHA_SIZE; ++i) {
        if(count_a[i] != count_b[i])
            return 0;
    }
    return 1;
}

int main()
{
    while (scanf("%s", a)!=EOF) {
        scanf("%s",b);
        int len=strlen(a);
        if (is_cipher(a, b, len)) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}

