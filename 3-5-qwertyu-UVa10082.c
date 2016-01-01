//
//  3-5-qwertyu-UVa10082.c
//  acm
//
//  Created by luerfeng on 15/12/23.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char buff[] = "1234567890-=QWERTYUIOP[]\\{}|ASDFGHJKL;':\"ZXCVBNM,./<>?";
    int c;
    while ((c=getchar()) != EOF) {
        if (c == ' ') {
            printf("%c", c);
            continue;
        }
        char *ptr = strchr(buff, c);
        if(ptr==NULL)
            break;
        printf("%c", buff[ptr-buff-1]);
    }
    printf("\n");
    return 0;
}