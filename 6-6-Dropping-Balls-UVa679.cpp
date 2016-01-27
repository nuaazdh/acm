//
// Created by luerfeng on 2016/01/24.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>

int drop_ball(int D, int I) {
    int i, pos = 1;
    for (i = 0; i < D - 1; ++i) {
        pos <<= 1;
        if (I & 0x01) {
        } else {
            ++pos;
        }
        I = (I + 1) / 2;
    }
    return pos;
}

int main() {
    int T,D,I,i;
    while (scanf("%d",&T) == 1 && T != -1) {
        for (i = 0; i < T; ++i) {
            scanf("%d%d",&D,&I);
            printf("%d\n",drop_ball(D,I));
        }
    }
    return 0;
}

