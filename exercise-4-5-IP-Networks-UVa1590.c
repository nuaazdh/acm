//
//  exercise-4-5-IP-Networks.c
//  acm
//
//  Created by luerfeng on 16/1/5.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1010

unsigned int ip_list[MAX_SIZE];
unsigned int min_net;
unsigned int mask;

void min_ip(int n)
{
    mask=~0;
    min_net = ip_list[0];
    while (n--) {
        while ((mask & min_net) != (ip_list[n] & mask)) {
            mask=mask<<1;
            min_net &= mask;
        }
    }
}

unsigned str2IP(char *s)
{
    unsigned ip=0,j=0;
    while (*s!='\0') {
        unsigned char num=0;
        do{
            num = num*10 + *(s++)-'0';
        }while(*s != '.' && *s != '\0');
        ip<<=8;ip^=num;
        ++s,++j;
        if(j>4) break;
    }
    return ip;
}

void print_ip(unsigned ip)
{
    printf("%d.%d.%d.%d\n",(ip>>24)%256,(ip>>16)%256, (ip>>8)%256, ip%256);
}

int main()
{
    int m,n, i=0;
    char buff[50];
    memset(ip_list, 0, sizeof(ip_list));
    
    while (scanf("%d",&n)==1) {
        m = n, i=0;
        while(n--){
            memset(buff,0,sizeof(buff));
            scanf("%s",buff);
            ip_list[i++] =  str2IP(buff);
        }
        min_ip(m);
        print_ip(min_net);
        print_ip(mask);
    }
    return 0;
}