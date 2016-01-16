//
//  4-2-Hangman-Judge-UVa489.c
//  acm
//
//  Created by luerfeng on 16/1/1.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define STR_LEN 200
char ans[STR_LEN];
char guess[STR_LEN];

char *promp[3] = {"You win.","You lose.","You chickened out."};

int hangman_judge(char* a, char* g)
{
    int rest, wrong=0;
    int hasguess[26];
    int alen = strlen(a), glen = strlen(g);
    rest = alen;
    memset(hasguess, 0, sizeof(hasguess));
    for (int i=0; i<glen; ++i) {
        if(hasguess[g[i]-'a'])
            continue;
        hasguess[g[i]-'a'] = 1;
        int right = 0;
        for (int j=0; j<alen; j++) {
            if(g[i] == a[j])
            {
                right = 1;
                --rest;
            }
        }
        if(!right) wrong++;
        if(!rest) return 0;
        if(wrong>=7)
            return 1;
    }
    if(wrong<7 && rest)
        return 2;
    return 0;
}

int main()
{
    int kcase;
    while (scanf("%d%s%s",&kcase,ans,guess)!=3 && kcase!=-1) {
        scanf("%d",&kcase);
        printf("Round %d\n%s\n", kcase, promp[hangman_judge(ans, guess)]);
    }
    return 0;
}