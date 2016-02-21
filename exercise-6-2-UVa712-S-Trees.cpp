//
// Created by luerfeng on 2016/02/14.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>

int main() {
    int d, q, i, j, tree_no = 0, index;
    char terminal[130], variable[10], query[10], arrange[10], order[10];
    while (scanf("%d", &d) == 1 && d) {
        for (i = 0; i < d; ++i) {
            scanf("%s", variable);
            order[variable[1] - '0' - 1] = i + '0';
        }
        scanf("%s", terminal);
        scanf("%d", &q);

        printf("S-Tree #%d:\n", ++tree_no);
        for (i = 0; i < q; ++i) {
            scanf("%s", query);
            for (j = 0; j < d; ++j) {
                arrange[order[j] - '0'] = query[j];
            }
            index = 0;
            for (j = 0; j < d; ++j) {
                index = (index << 1) + arrange[j] - '0';
            }
            printf("%c", terminal[index]);
        }
        printf("\n\n");
    }
    return 0;
}