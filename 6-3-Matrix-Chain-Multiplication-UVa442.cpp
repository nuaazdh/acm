//
// Created by luerfeng on 2016/01/23.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <stack>

typedef struct {
    int row;
    int column;
} matrix;

const int max_size = 27;

matrix matrix_vector[max_size];


int main() {
    int n, row, column;
    std::string str;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> str >> row >> column;
        matrix_vector[str[0] - 'A'].row = row;
        matrix_vector[str[0] - 'A'].column = column;
    }
    std::string line;
    while (std::getline(std::cin, line)) {
        if(line.empty())
            continue;
        int total = 0;
        std::stack<char> expr;
        std::stack<matrix> matrix_exp;
        bool error = false;
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ')') {
                if(matrix_exp.size()<2)
                    continue;
                matrix a = matrix_exp.top();
                matrix_exp.pop();
                matrix b = matrix_exp.top();
                matrix_exp.pop();
                if (a.row != b.column) {
                    error = true;
                    break;
                }
                total += b.row * b.column * a.column;
                b.column = a.column;
                matrix_exp.push(b);

            } else if (line[i] >= 'A' && line[i] <= 'Z') {
                matrix tmp = matrix_vector[line[i] - 'A'];
                matrix_exp.push(tmp);
            }
        }
        if (error) {
            std::cout << "error\n";
        } else {
            std::cout << total << "\n";
        }
    }

    return 0;
}
