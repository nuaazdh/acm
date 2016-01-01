//
//  exercise-3-2.c
//  acm
//
//  Created by luerfeng on 15/12/24.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define STR_SIZE 105

char ans[STR_SIZE];

double mole(char c)
{
    switch (c) {
        case 'C':
            return 12.01;
        case 'H':
            return 1.008;
        case 'O':
            return 16.00;
        default:
        return 14.01;
    }
}

int main()
{
    memset(ans, 0, sizeof(ans));
    int T;
    scanf("%d", &T);
    while (T--) {
        double mass = 0;
        scanf("%s", ans);
        int len  = strlen(ans);
        double last = 1.0;
        int num = 0;
        for (int i=0; i<len;) {
            if (ans[i] >= '0' && ans[i] <= '9') {
                num = 0;
                do {
                    num = num*10 + (ans[i++]-'0');
                }while (i<len && (ans[i]>='0')&& (ans[i]<='9'));
                mass += num*last;
                num = 0;
            }else{
                mass += last*num;
                last = mole(ans[i]);
                num = 1;
                ++i;
            }
        }
        mass += num*last;
        printf("%.3f\n", mass);
    }
}