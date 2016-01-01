//
//  exercise-3-4-UVa455.c
//  acm
//
//  Created by luerfeng on 15/12/25.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

/**
 注意：
 the cat ran out => 3
 
 */

#include <stdio.h>
#include <string.h>

#define STR_SIZE 90 
char ans[STR_SIZE];

int periodic_k(char str[], int len, int k )
{
    if(len == k)
        return 1;
    if(k>len/2)
        return 0;
    for (int i=0; i<k; ++i) {
        for (int j=k; j <len; j+=k) {
            if(str[j+i] != str[i])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(ans, 0, sizeof(ans));
        scanf("%s", ans);
        int i, len = strlen(ans);
        for (i=1; i<len && (ans[i] != ' '); ++i) {
            if (ans[i] == ans[0]) {
                if(periodic_k(ans, len, i))
                {
                    break;
                }
            }
        }
        while ( getchar() != '\n' );
        printf("%d\n", i);
        if(T) printf("\n");
    }
}