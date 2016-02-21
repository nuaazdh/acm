//
// Created by luerfeng on 2016/02/14.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>
#include <stack>

char balance_parenthese(char c) {
    switch (c) {
        case ')':
            return '(';
        case ']':
            return '[';
        default:
            return ' ';
    }
}

int main() {
    int T, i, len;
    char buff[200];
    scanf("%d", &T);
    while(getchar()!='\n');
    while (T--) {
        memset(buff, 0, sizeof(buff));
        gets(buff);
        len = strlen(buff);
        std::stack<char> parentheses;
        for (i = 0; i < len; ++i) {
            if (buff[i] == '(' || buff[i] == '[') {
                parentheses.push(buff[i]);
            } else if (buff[i] == ')' || buff[i] == ']') {
                if (!parentheses.empty() && parentheses.top() == balance_parenthese(buff[i])) {
                    parentheses.pop();
                } else {
                    break;
                }
            } else {

            }
        }
        if (parentheses.empty() && i == len) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}

