//
//  3-4-tex-quote-UVa272.c
//  acm
//
//  Created by luerfeng on 15/12/23.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int main()
{
    int c, q=1;
    while ((c=getchar()) != EOF) {
        if (c=='"') {
            printf("%s", q ? "``" : "''"); q = !q;
        }else{
            printf("%c", c);
        }
    }
}
