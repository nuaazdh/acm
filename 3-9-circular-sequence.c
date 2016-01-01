//
//  3-9-circular-sequence.c
//  acm
//
//  Created by luerfeng on 15/12/24.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define  STR_SIZE 105

char dna[STR_SIZE];

int main()
{
    memset(dna, 0, sizeof(dna));
    scanf("%s", dna);
    int len = strlen(dna);
    printf("%d\n", len);
    int min = 0;
    for (int i=1; i<len; ++i){
        for (int j=0; j<len; ++j) {
            if(dna[(j+min)%len] > dna[(j+i)%len])
            {
                printf("%d %d %d %c %c\n",i,j,min,dna[(j+min)%len],dna[(j+i)%len]);
                min = i;
                break;
            }else if(dna[(j+min)%len] < dna[(j+i)%len]){
                break;
            }
        }
    }
    printf("%d\n",min);
    for (int i=0; i<len; ++i) {
        printf("%c", dna[(min+i)%len]);
    }
    printf("\n");
    return 0;
}