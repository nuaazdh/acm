//
// Created by luerfeng on 2016/02/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>

int main() {
    int kcase = 0;
    __int64_t n, num[20];
    while (scanf("%lld", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &num[i]);
        }
        __int64_t max = num[0];
        for (int i = 0; i < n; ++i) {
            __int64_t product = 1;
            for (int j = 0; j < n - i; ++j) {
                product *= num[i + j];
                if (max < product)
                    max = product;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++kcase, (max < 0 ? 0 : max));

    }
    return 0;
}