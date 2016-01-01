//
//  exercise-3-1-UVa1586.c
//  acm
//
//  Created by luerfeng on 15/12/24.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

/*
 
 给出一个有 O 和 X组成的串（长度为 1~80），统计得分，每个O的得分为目前连续出现的O的个数，
 每个X的得分为0， 例如OOXXOXXOOO的得分：
 1+2+0+2+1+0++1+2+3
 
 */

#include <stdio.h>
#include <string.h>

#define ANS_SIZE 100

char ans[ANS_SIZE];

int main()
{
    memset(ans, 0, sizeof(ans));
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%s", ans);
        int len = strlen(ans);
        int score = 0, seq_o = 0;
        for (int i=0; i<len; ++i) {
            if(ans[i] == 'X'){
                seq_o = 0;
            }else{
                ++seq_o;
                score += seq_o;
            }//if
        }//for
        printf("%d\n", score);
    }
    return 0;
}
