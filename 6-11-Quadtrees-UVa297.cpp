//
// Created by luerfeng on 2016/01/27.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <stdio.h>
#include <string.h>

#define MAX_LEN 2048
char tree1[MAX_LEN];
char tree2[MAX_LEN];
char conbine_tree[MAX_LEN];


int get_pixel(int &pos, int weight) {
    int cnt, total = 0;
    if (pos > strlen(conbine_tree))
        return 0;
    if (conbine_tree[pos] == 'f') {
        pos++;
        total += weight;
    } else if (conbine_tree[pos] == 'p') {
        cnt = 4;
        while (cnt--) {
            ++pos;
            if (conbine_tree[pos] == 'f') {
                total += weight/4;
            }else if(conbine_tree[pos] == 'p'){
                total += get_pixel(pos, weight/4);
            }else{
            }
        }
    } else {
        pos++;
    }
    return total;
}



int main() {
    int T, len1, len2, i, j, pos, pcnt;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", tree1);
        scanf("%s", tree2);
        len1 = strlen(tree1);
        len2 = strlen(tree2);
        memset(conbine_tree, 0, sizeof(conbine_tree));
        i = j = pos = 0;
        while (i < len1 && j < len2) {
            if ((tree1[i] == 'p' && tree2[j] == 'p')) {
                conbine_tree[pos++] = 'p';
                ++i;
                ++j;
                continue;
            }
            if (tree1[i] != 'p' && tree2[j] != 'p') {
                if (tree1[i++] == 'f' || tree2[j++] == 'f') {
                    conbine_tree[pos++] = 'f';
                } else {
                    conbine_tree[pos++] = 'e';
                }
            } else if (tree1[i] == 'p' && tree2[j] != 'p') {
                if (tree2[j] == 'f') {
                    conbine_tree[pos++] = tree2[j++];
                    pcnt = 4;
                    ++i;
                    while (pcnt > 0) {
                        if (tree1[i] != 'p')  --pcnt;
                        else  pcnt += 4;
                        ++i;
                    }
                } else {
                    j++;
                    conbine_tree[pos++] = tree1[i++];
                    pcnt = 4;
                    while (pcnt > 0) {
                        if (tree1[i] != 'p')  --pcnt;
                        else  pcnt += 4;
                        conbine_tree[pos++] = tree1[i++];
                    }
                }

            } else if (tree2[j] == 'p' && tree1[i] != 'p') {
                if (tree1[i] == 'f') {
                    conbine_tree[pos++] = tree1[i++];
                    pcnt = 4;
                    ++j;
                    while (pcnt > 0) {
                        if (tree2[j] != 'p')  --pcnt;
                        else pcnt += 4;
                        ++j;
                    }
                } else {
                    ++i;
                    conbine_tree[pos++] = tree2[j++];
                    pcnt = 4;
                    while (pcnt > 0) {
                        if (tree2[j] != 'p') --pcnt;
                        else pcnt += 4;
                        conbine_tree[pos++] = tree2[j++];
                    }
                }
            }

        }
        if (i < len1) {
            while (i < len1) conbine_tree[pos++] = tree1[i++];
        } else {
            while (j < len2) conbine_tree[pos++] = tree2[j++];
        }
        pos = 0;
        printf("There are %d black pixels.\n",get_pixel(pos,1024));

    }
    return 0;
}
