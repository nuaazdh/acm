//
// Created by luerfeng on 2016/02/14.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>
#include <queue>

int cheeseboard[8][8];
int from_pos, to_pos;
int d_r[] = {-1, -1, 1, 1, -2, -2, 2, 2}, d_c[] = {-2, 2, -2, 2, -1, 1, -1, 1};

int valid_pos(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

void print_cheeseboard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%3d", cheeseboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solve() {
    std::queue<int> queue;
    queue.push(from_pos);
    while (!queue.empty()) {
        int pos = queue.front();
        if (pos == to_pos)
            return;
        for (int i = 0; i < 8; ++i) {
            if (valid_pos(pos / 8 + d_r[i], pos % 8 + d_c[i]) && !cheeseboard[pos / 8 + d_r[i]][pos % 8 + d_c[i]]) {
                cheeseboard[pos / 8 + d_r[i]][pos % 8 + d_c[i]] = cheeseboard[pos / 8][pos % 8] + 1;
                queue.push((pos / 8 + d_r[i]) * 8 + pos % 8 + d_c[i]);
            }
        }
        queue.pop();
//        print_cheeseboard();
    }
}

int main() {
    char from[5], to[5];
    while (scanf("%s", from) != EOF) {
        memset(cheeseboard, 0, sizeof(cheeseboard));
        scanf("%s", to);
        from_pos = (from[1] - '1') * 8 + from[0] - 'a';
        to_pos = (to[1] - '1') * 8 + to[0] - 'a';
        solve();
        printf("To get from %s to %s takes %d knight moves.\n", from, to, cheeseboard[to_pos / 8][to_pos % 8]);
    }
}