//
//  exercise-4-6-Morse-Mismatches-UVa508.c
//  acm
//
//  Created by luerfeng on 16/1/6.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define ELEMENT_COUNT 90
#define WORD_COUNT 110

typedef struct{
    char digit;
    char hyphens[8];
}element;

typedef struct{
    char word[12];
    unsigned char len;
    char code[700];
}context;

element morse_tb[256];
context ct[WORD_COUNT];

int read_morse()
{
    int index = 0;
    char buff[10];
    memset(morse_tb, 0, sizeof(morse_tb));
    while (1) {
        memset(buff, 0, sizeof(buff));
        scanf("%s",buff);
        if(buff[0]=='*')
            break;
        index = (int)buff[0]-'\0';
        morse_tb[index].digit = buff[0];
        scanf("%s",morse_tb[index].hyphens);
    }
    return 0;
}

int read_word()
{
    char buff[12];
    int word_count = 0;
    memset(ct, 0, sizeof(ct));
    while (1) {
        memset(buff, 0, sizeof(buff));
        scanf("%s",buff);
        if(buff[0]=='*')
            break;
        strncpy(ct[word_count].word, buff, 12);
        ct[word_count].len = strlen(buff);
        word_count++;
    }
    return word_count;
}

void print_word(int n)
{
    int i;
    for (i = 0; i<n; ++i) {
        printf("%s\t%s\n", ct[i].word, ct[i].code);
    }
}

void print_morse()
{
    int i;
    for(i=0;i<256;++i)
    {
        if(morse_tb[i].digit != '\0')
            printf("%c\t%s\n", morse_tb[i].digit,morse_tb[i].hyphens);
    }
}

void translate(int n)
{
    int i,j,len=0,index;
    for (i=0; i<n; ++i) {
        for (j=0; j<ct[i].len; ++j) {
            index = (int)ct[i].word[j]-'\0';
            len= strlen(morse_tb[index].hyphens);
            strncat(ct[i].code, morse_tb[index].hyphens, len);
        }
    }
}

int match_character(char* word, int n)
{
    int i,j=0,index=0,len;
    for (i=0; i<ct[n].len; ++i) {
        index = ct[n].word[i];
        len =strlen(morse_tb[index].hyphens);
        if(strncmp(morse_tb[index].hyphens, word, len)==0)
        {
            ++j;
            word+=len;
        }else{
            return j;
        }
    }
    return j;
}

void match_word(char* word,int dict_n)
{
    int match[WORD_COUNT][2],min_id=0, max_len = 0, i,j=0,mis_id=0,n=0,no=0;
    memset(match, 0, sizeof(match));
    for (i=0; i<dict_n; ++i) {
        if(strncmp(word, ct[i].code, strlen(word))==0)
        {
            if(strncmp(ct[i].code, word, strlen(ct[i].code))==0)//exactly match
            {
                match[j][0]=i;
                match[j][1]=ct[i].len;
                if(n==0){
                    min_id = i;
                }
                n++;j++;
            }else{
                
                if(no==0 || (match_character(word,i) > max_len)){
                    mis_id = i;
                    max_len = match_character(word,i);
                }
                no++;
            }
        }else{
            if(strncmp(ct[i].code, word, strlen(ct[i].code))==0)
            {
                if(no==0 || (match_character(word,i) > max_len)){
                    mis_id = i;
                    max_len = match_character(word,i);
                }
                no++;
            }else{
                
            }
        }
    }//for
    if(n==1){
        printf("%s\n",ct[min_id].word);
    }else if(n>1){
        printf("%s!\n",ct[min_id].word);
    }else if(no>0){
        printf("%s?\n",ct[mis_id].word);
    }else{
        printf("?\n");
    }
}

int main()
{
    char buff[700];
    int table_size=0, word_count;
    table_size = read_morse();
    word_count = read_word();
    translate(word_count);
    while (scanf("%s",buff)!=EOF) {
        if(buff[0]=='*')
            break;
        match_word(buff, word_count);
        
    }
//    print_word(word_count);
//    print_morse();
    return 0;
}