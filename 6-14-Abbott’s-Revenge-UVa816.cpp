//
// Created by luerfeng on 2016/01/29.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>


int map[9][9][4];
int visit[9][9][4];
int row_path[10000] = {0};
int prev[10000] = {0};
int col_path[10000] = {0};
int direction_path[10000] = {0};
char direction_set[] = "NESW";


int direction_encode(char dc) {
    switch (dc) {
        case 'N':
            return 0;
        case 'E':
            return 1;
        case 'S':
            return 2;
    }
    return 3;
}

int get_next_direction(char d, char t) {
    int turn = 0;
    switch (t) {
        case 'L':
            turn = 3;
            break;
        case 'R':
            turn = 1;
            break;
    }
    return (turn + direction_encode(d)) % 4;
}

void move_next(int &r, int &c, char d) {
    switch (d) {
        case 'N':
            --r;
            break;
        case 'S':
            ++r;
            break;
        case 'E':
            ++c;
            break;
        case 'W':
            --c;
            break;
        default:
            break;
    }
}

bool is_valid_pos(int r, int c) {
    return (r > 0 && r < 10 && c > 0 && c < 10);
}

int main() {
    char maze[1024], ins[1024];
    int er, ec, gr, gc, cur_pos;
    int r, c, d;
    int counter;
    while (gets(maze) && strcmp("END", maze)) {
        printf("%s\n", maze);
        std::queue<int> p_queue;
        counter = 0;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        memset(row_path, 0, sizeof(row_path));
        memset(col_path, 0, sizeof(col_path));
        memset(direction_path, 0, sizeof(direction_path));
        memset(prev, 0, sizeof(prev));
        scanf("%d %d %s %d %d", &er, &ec, ins, &gr, &gc);

        prev[counter] = counter - 1;
        row_path[counter] = er;
        col_path[counter] = ec;
        direction_path[counter++] = direction_encode(ins[0]);

        move_next(er, ec, ins[0]);
        prev[counter] = counter - 1;
        row_path[counter] = er;
        col_path[counter] = ec;
        direction_path[counter++] = direction_encode(ins[0]);

        p_queue.push(counter - 1);

        while (scanf("%d", &r) == 1 && r) {
            scanf("%d", &c);
            while (scanf("%s", ins) == 1 && ins[0] != '*') {
                d = direction_encode(ins[0]);
                for (int i = 1; ins[i]; ++i) {
                    map[r][c][d] |= (1 << (get_next_direction(ins[0], ins[i])));
                }
//                printf("%d %d %c\n", r, c, direction_set[d]);
            }
        }
        while (!p_queue.empty()) {
            cur_pos = p_queue.front();
            r = row_path[cur_pos], c = col_path[cur_pos], d = direction_path[cur_pos];
            visit[r][c][d] = 1;
//            for (int i = 0; i < counter; ++i) {
//                printf("prev[%d]:%d, path:%d %d %c\n", i, prev[i], row_path[prev[i]], col_path[prev[i]],
//                       direction_set[direction_path[prev[i]]]);
//            }
//            printf("current: %d %d %c\n", r, c, direction_set[d]);
            if (r == gr && c == gc) {
                std::stack<int> result;
                for (int i = cur_pos; i != -1; i = prev[i]) {
//                    printf("%d %d %d\n", i, prev[i], path[i]);
                    result.push(i);
                }
                for (int j = 1; !result.empty(); ++j, result.pop()) {
                    if (j % 10 == 1) printf("  ");
                    else printf(" ");
                    printf("(%d,%d)", row_path[result.top()], col_path[result.top()]);
                    if (j % 10 == 0 && result.size() != 1) printf("\n");
                }
                break;
            } else {
                int next = map[r][c][d];
                for (int i = 0; i < 4; ++i) {
                    if (next & (1 << i)) {
                        int tr = r, tc = c;
                        move_next(tr, tc, direction_set[i]);
                        if (!visit[tr][tc][i] && is_valid_pos(tr, tc)) {
                            prev[counter] = cur_pos;
                            row_path[counter] = tr;
                            col_path[counter] = tc;
                            direction_path[counter++] = i;
                            p_queue.push(counter - 1);
//                            printf("possible: %d %d %c\n", tr, tc, direction_set[i]);
                        }
                    }
                }
            }
            p_queue.pop();
        }
        if (!(r == gr && c == gc)) {
            printf("  No Solution Possible");
        }
        printf("\n");
        while (getchar() != '\n');
    }
    return 0;
}
