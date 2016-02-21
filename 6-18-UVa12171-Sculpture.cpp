//
// Created by luerfeng on 2016/02/03.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <string.h>

int x_direction[] = {-1, 0, 0, 1, 0, 0}, y_direction[] = {0, -1, 0, 0, 1, 0}, z_direction[] = {0, 0, -1, 0, 0, 1};

int space[100][100][100];
int x1[100], y1[100], z1[100];
int x2[100], y2[100], z2[100];
int xmin, ymin, zmin, xmax, ymax, zmax;
int square, cubic;

int is_valid_pos(int x, int y, int z) {
    return (xmin - 1 <= x && x <= xmax && ymin - 1 <= y && y <= ymax && zmin - 1 <= z && z <= zmax);
}

int main() {
    int T, n, x, y, z, w, h, d, i, j, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(space, 0, sizeof(space));
//        memset(visit, 0, sizeof(visit));
        xmin = ymin = zmin = xmax = ymax = zmax = 0;
        square = cubic = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d %d %d %d %d %d", &x1[i], &y1[i], &z1[i], &x2[i], &y2[i], &z2[i]);

        }

        printf("%d %d %d %d %d %d\n", xmin, ymin, zmin, xmax, ymax, zmax);
        printf("%d %d\n", square, cubic);
    }
    return 0;
}