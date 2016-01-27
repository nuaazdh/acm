//
// Created by luerfeng on 2016/01/26.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>

int is_balance = 1;

int balance() {
    int wl, dl, wr, dr;
    scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
    if (wl == 0) {
        wl = balance();
    }
    if (wr == 0) {
        wr = balance();
    }
    if (wl * dl != wr * dr) {
        is_balance = 0;
    }
    return wl + wr;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        is_balance = 1;
        balance();
        if (is_balance) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        if(T) printf("\n");
    }
    return 0;
}