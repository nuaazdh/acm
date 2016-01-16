//
//  4-4-Message Decoding-UVa213.c
//  acm
//
//  Created by luerfeng on 16/1/2.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define HEADER_LEN 10000
#define MESSAGE_LEN 100000

char header[HEADER_LEN];
char message[MESSAGE_LEN];

int readheader()
{
    memset(header, 0, sizeof(header));
    int c, i=0;
    while ((c=getchar())!=EOF) {
        if(c=='\n' || c=='\r'){
            return 1;
        }
        header[i++] = c;
    }
    return 0;
}

int  decode_message(int start, int len)
{
    int index = 0;
    for (int i=0; i<len; ++i) {
        index = 2*index+(message[start+i]-'0');
    }
    if(index == (1<<len)-1) // segment over
        return 0;
    if(len==1){
        putchar(header[0]);
    }else{
        int offset = 0;
        while (len>1) {
            offset += (1<<(len-1)) - 1;
            --len;
        }
        if((offset+index)>strlen(header))
            return 0;
        putchar(header[offset+index]);
    }
    return 1;
}


int main()
{
    int i=0;
    while (readheader()) {
//        printf("header:%s\n",header);
        if(strlen(header)<1)
            break;
        int len = 0;
        while (scanf("%s",message+len)!=EOF) {
            len = strlen(message);
            if(message[len-1]=='0' && message[len-2]=='0'&& message[len-3]=='0')
                break;
        }
//        printf("message:%s\n",message);
//        printf("ouput:");
        len = strlen(message);
        int bits = 0;
        for (i=0; i<len-3;) {
            bits = (message[i]-'0')*4+(message[i+1]-'0')*2+(message[i+2]-'0')*1;
            if (!bits) {
                break;
            }
            i+=3;
            while(decode_message(i, bits))
            {
                i+=bits;
            }
            i+=bits;
        }
        printf("\n");
        getchar();
    }
}