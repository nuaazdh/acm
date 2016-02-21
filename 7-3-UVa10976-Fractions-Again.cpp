//
// Created by luerfeng on 2016/02/18.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <stdio.h>
#include <set>

int main() {
    int k;
    while (scanf("%d", &k) == 1 && k) {
        std::set<int> x_set;
        for (int x = k + 1; x <= 2 * k; ++x) {
            int y = k * x / (x - k);
            if (k * (x + y) == x * y) {
                if (!x_set.count(x))
                    x_set.insert(x);
            }
        }
        printf("%ld\n", (x_set.size()));
        for (std::set<int>::const_iterator it = x_set.begin(); it != x_set.end(); ++it) {
            printf("1/%d = 1/%d + 1/%d\n", k, (*it * k / (*it - k)), *it);
        }
    }
    return 0;
}
