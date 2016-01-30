//
// Created by luerfeng on 2016/01/27.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>

#define TREE_WIDTH (20000)
int leaves[TREE_WIDTH];

void build_tree(int root) {
    int L, R;
    scanf("%d", &L);
    if (L != -1) {
        leaves[root - 1] += L;
        build_tree(root - 1);
    }
    scanf("%d", &R);
    if (R != -1) {
        leaves[root + 1] += R;
        build_tree(root + 1);
    }
}

int main() {
    int i, root, val, kcase = 0;
    while (scanf("%d", &val) && val != -1) {
        memset(leaves, 0, sizeof(leaves));
        root = TREE_WIDTH / 2;
        leaves[root] = val;
        build_tree(root);
        printf("Case %d:\n", ++kcase);
        for (i = 0 ; i < TREE_WIDTH; ++i) {
            if(leaves[i]){
                printf("%d", leaves[i]);
                break;
            }
        }
        for (++i; i < TREE_WIDTH; ++i) {
            if(leaves[i]){
                printf(" %d",leaves[i]);
            }else{
                break;
            }
        }
        printf("\n\n");
    }
    return 0;
}