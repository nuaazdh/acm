//
// Created by luerfeng on 2016/02/02.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char buff[200][200];

int valid_node(char c) {
    return (c != ' ' && c != '|' && c != '-' && c != '#' && c != '\0');
}

void print_tree(int current_line_no, int line_no, int begin, int ends) {
    if (current_line_no > line_no || begin > ends)
        return;
    for (int i = begin; i <= ends; ++i) {
        if (!valid_node(buff[current_line_no][i]))
            continue;
        printf("%c(", buff[current_line_no][i]);
        if (current_line_no + 2 > line_no || buff[current_line_no + 1][i] != '|') {
            printf(")");
            continue;
        }
        int next_begin = i, next_end = i;
        while (next_begin && buff[current_line_no + 2][next_begin] == '-') --next_begin;
        while (buff[current_line_no + 2][next_end] == '-') ++next_end;
        print_tree(current_line_no + 3, line_no, next_begin, next_end);
        printf(")");
    }
}


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(buff, 0, sizeof(buff));
        int line_no = 0;
        while (gets(buff[line_no]) && buff[line_no][0] != '#') {
            if (strlen(buff[line_no]) == 0)
                continue;
//            printf("%s\n", buff[line_no]);
            ++line_no;
        }
        int end = strlen(buff[0]);
        printf("(");
        print_tree(0, line_no, 0, end);
        printf(")\n");
    }
    return 0;
}