//
//  exercise-4-4-Cube-painting-UVa253.c
//  acm
//
//  Created by luerfeng on 16/1/5.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>

char cube[14];

int is_identical(char*s)
{
    int i,j, found;
    for(i=0;i<3;++i)
    {
        found = 0;
        for (j=6; j<12; ++j)
        {
            if(s[j] != s[i])
                continue;
            if(s[5-i] != s[17-j])
                continue;
            found = 1;
            s[j] = s[17-j] = ' ';
            break;
        }
        if(!found) return 0;
    
    }
    return 1;
}

int main()
{
    while (scanf("%s",cube) != EOF) {
        if(is_identical(cube))
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
    return 0;
    
}


