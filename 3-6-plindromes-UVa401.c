//
//  3-5-plindromes-UVa401.c
//  acm
//
//  Created by luerfeng on 15/12/23.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 200

int main()
{
    char mirror[] = "AAE3HHIIJLLJMMOOS2TTUUVVXXYYZ5112S3E5Z88";
    char buff[BUFFER_SIZE];
    memset(buff, 0, sizeof(buff));
    scanf("%s", buff);
    int is_palindrome = 0;
    int is_mirror = 0;
    int i = 0,len = strlen(buff) - 1;
    for(i=0; i<len && (buff[i] == buff[len]); ++i,--len);
    if(i>=len)
        is_palindrome = 1;
    len = strlen(buff) - 1;
    printf("%d\n",len);
    for(i=0; i<len ; ++i,--len) {
        int j=0;
        for (j=0; j<strlen(mirror); j+=2) {
            if(mirror[j] == buff[i])
                break;
        }
        printf("%d %c  %c %c\n",j,mirror[j],mirror[j+1], buff[len]);
        if(j == strlen(mirror) || mirror[j+1] != buff[len])
            break;
    }
    printf("%d %d\n",i,len);
    if(i>=len)
        is_mirror = 1;
    printf("%s", buff);
    if(!is_mirror && !is_palindrome){
        printf("-- is not a palindrome.\n\n");
    }else if(!is_mirror && is_palindrome){
        printf("--- is a regular palindrome.\n\n");
    }else if(is_mirror && !is_palindrome){
        printf("--- is a mirrored string.\n\n");
    }else{
        printf("--- is a mirrored palindrome.\n\n");
    }
        
}