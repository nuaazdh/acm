//
//  3-3-vertical-math.c
//  acm
//
//  Created by luerfeng on 15/12/22.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>


#define STR_LEN 20
#define BUFFER_SIZE 100

char charset[STR_LEN];
char buffer[BUFFER_SIZE];

int main()
{
    memset(charset, 0, sizeof(charset));
    scanf("%s", charset);
    int count = 0;
    for (int abc=100; abc<=999; abc++) {
        for (int de=10; de<=99; de++) {
            memset(buffer, 0, sizeof(buffer));
            int x = abc*(de%10), y = abc*(de/10), z=abc*de;
            sprintf(buffer, "%d%d%d%d%d",abc,de,x,y,z);
            int valid = 1;
            for (int i=0; i<BUFFER_SIZE && buffer[i] != 0; ++i) {
                if(strchr(charset, buffer[i]) == NULL)
                {
                    valid  = 0;
                    break;
                }
            }
            if(valid)
                printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n",++count,abc,de,x,y,z);
        }
    }
    if(count>0)
        printf("The number of solutions =%d\n",count);
}