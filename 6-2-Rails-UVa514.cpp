//
// Created by luerfeng on 2016/01/23.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>

#define MAX_SEQ_SIZE 1100

int pop_seq[MAX_SEQ_SIZE];
int stack[MAX_SEQ_SIZE];

int main() {
    int stack_size, pop_i = 0, nth_pop, top, in_seq;
    while (scanf("%d", &stack_size) == 1 && stack_size) {
        do {
            pop_i =1;
            while (pop_i <= stack_size && scanf("%d", &nth_pop) == 1 && nth_pop) {
                pop_seq[pop_i++] = nth_pop;
            }
            if (nth_pop == 0) {
                printf("\n");
                break;
            }
            pop_i =1, in_seq =1, top=0;
            while (pop_i <= stack_size && in_seq <= stack_size) {
                if (pop_seq[pop_i] == in_seq) { ++pop_i, ++in_seq;}
                else if(pop_seq[pop_i] > in_seq){ stack[++top] = in_seq++; }
                else if(top && stack[top] == pop_seq[pop_i]){ --top; ++pop_i; }
                else{
                    break;
                }
            }
            (pop_i >= stack_size) ? (printf("Yes\n")) : (printf("No\n"));
        } while (1);
    }
    return 0;
}