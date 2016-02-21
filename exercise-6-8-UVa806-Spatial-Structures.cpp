//
// Created by luerfeng on 2016/02/15.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

const int max_size = 64 + 2;
int image[max_size][max_size];


int draw(int n, int len) {
    int x = 0, y = 0, i = 0, j = 0;
    while (n) {
        len >>= 1;
        if (n % 10 == 1) {

        } else if (n % 10 == 2) {
            y += len;
        } else if (n % 10 == 3) {
            x += len;
        } else {
            x += len;
            y += len;
        }
        n /= 10;
    }

    for (i = 0; i < len; ++i) {
        for (j = 0; j < len; ++j) {
            image[i + x][j + y] = 1;
        }
    }
    return len * len;
}

void print_image(int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            printf("%c", image[i][j] ? '*' : '.');
        }
        printf("\n");
    }
}

int decimal_2_base5(int num) {
    int n = 0, base = 1;
    while (num) {
        n += base * (num % 5);
        num /= 5;
        base *= 10;
    }
    return n;
}

int base5_2_decimal(int num) {
    int n = 0, base = 5;
    while (num) {
        n = n * base + (num % 10);
        num /= 10;
    }
    return n;
}

void solve(int i, int j, int n, int path, std::vector<int> &v) {
    int blk = false, wht = false;
    int k = 0, l = 0;
    if (n < 1) return;
    for (k = 0; k < n; ++k) {
        for (l = 0; l < n; ++l) {
            if (!blk && image[i + k][j + l] == 1) blk = true;
            if (!wht && image[i + k][j + l] == 0) wht = true;
            if (wht && blk) break;
        }
    }
    if (!blk)
        return;
    if (k == n && l == n) {
        v.push_back(path);
    } else {
        n >>= 1;
        if (n) {
            solve(i, j, n, path * 10 + 1, v);
            solve(i, j + n, n, path * 10 + 2, v);
            solve(i + n, j, n, path * 10 + 3, v);
            solve(i + n, j + n, n, path * 10 + 4, v);
        }
    }
}

int main() {
    int n, i, j, image_no = 0;
    char line[max_size];
    while (scanf("%d", &n) && n) {
        if (image_no) printf("\n");
        printf("Image %d\n", ++image_no);
        memset(image, 0, sizeof(image));
        if (n > 0) {
            std::vector<int> res;
            for (i = 0; i < n; ++i) {
                scanf("%s", line);
                for (j = 0; j < n; ++j) {
                    image[i][j] = line[j] - '0';
                }
            }
            solve(0, 0, n, 0, res);
            for (i = 0; i < res.size(); ++i) {
                res[i] = base5_2_decimal(res[i]);
            }
            std::sort(res.begin(), res.end());
            if (res.size() > 0) {
                for (i = 0; i < res.size(); ++i) {
                    if (i % 12) printf(" ");
                    printf("%d", res[i]);
                    if (i != 0 && (i + 1) % 12 == 0) printf("\n");
                }
                if (res.size() % 12) printf("\n");
            }
            printf("Total number of black nodes = %ld\n", res.size());
        } else {
            n = -n;
            while (scanf("%d", &i) && i != -1) {
                draw(decimal_2_base5(i), n);
            }
            print_image(n);
        }
    }
    return 0;
}