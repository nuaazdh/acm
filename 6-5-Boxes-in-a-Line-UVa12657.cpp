//
// Created by luerfeng on 2016/01/23.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>

const int max_size = 100100;

int prev[max_size];
int next[max_size];

void swap_int(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void link(int L, int R)
{
    next[L] = R;
    prev[R] = L;
}

void print_order() {
    int i;
    for (i = next[0]; i != 0; i = next[i]) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void print_vorder()
{
    int i;
    for (i = prev[0]; i != 0; i = prev[i]) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    int m, n, cmd, x, y, i, j, inv = 0, kcase = 0;
    unsigned long long sum;

    while (std::cin >> m >> n && m && n) {
        sum = 0;
        inv = 0;
        for (i = 1; i <= m; ++i) {
            next[i] = i + 1;
            prev[i] = i - 1;
        }
        next[0] = 1;
        next[m] = 0;
        prev[0] = m;
//        print_order();
//        print_vorder();
        for (i = 0; i < n; ++i) {
            std::cin >> cmd;
            if (cmd == 4) {
                inv = 1 - inv;

            } else {
                if (inv) {
                    if (cmd == 1) cmd = 2;
                    else if (cmd == 2) cmd = 1;
                    if (cmd == 3) swap_int(x, y);
                }
                std::cin >> x >> y;
                if (cmd == 1) {
                    if (next[x] == y) {
                        continue;
                    }
                    prev[next[x]] = prev[x];
                    next[prev[x]] = next[x];
                    next[prev[y]] = x;
                    prev[x] = prev[y];
                    prev[y] = x;
                    next[x] = y;

                } else if (cmd == 2) {
                    if (prev[x] == y) {
                        continue;
                    }
                    if (next[x]) prev[next[x]] = prev[x];
                    next[prev[x]] = next[x];
                    if(next[y]) prev[next[y]] = x;
                    next[x] = next[y];
                    prev[x] = y;
                    next[y] = x;
                } else if (cmd == 3) {
                    if(prev[x] == y)
                        swap_int(x,y);
                    if(prev[y] == x){
                        next[prev[x]] = y;
                        prev[next[y]] = x;
                        prev[y] = prev[x];
                        next[x] = next[y];
                        prev[x] = y;
                        next[y] = x;

                    }else{
                        prev[next[x]] = y;
                        next[prev[x]] = y;
                        prev[next[y]] = x;
                        next[prev[y]] = x;
                        swap_int(prev[x], prev[y]);
                        swap_int(next[x], next[y]);
                    }
                }
            }// else
//            print_order();
//            print_vorder();
        }//for
        j = 1;
        for (i = next[0]; i != 0; i = next[i], j++) {
            if (inv && !(m & 1)) {
                if (j & 1) continue;
            } else {
                if (!(j & 1)) continue;
            }
            sum += i;
        }
        std::cout << "Case " << ++kcase << ": " << sum << "\n";
    }
    return 0;
}