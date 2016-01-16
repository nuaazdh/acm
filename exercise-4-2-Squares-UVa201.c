//
//  exercise-4-2-Squares-UVa201.c
//  acm
//
//  Created by luerfeng on 16/1/3.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define BOARD_SIZE 10

typedef struct{
    int type;
    int len;
}arc;

int board[BOARD_SIZE][BOARD_SIZE]; // 1 horizontal, 2 vertical, 3 both;
int vertex[BOARD_SIZE][BOARD_SIZE];
int square[BOARD_SIZE];

int exist_horizon(int i, int j)
{
    return (board[i][j] == 1 || board[i][j] == 3);
}

int exist_vertical(int i, int j)
{
    return (board[i][j]>=2);
}

int exist_squre(int i, int j, int len)
{
    int k;
    if(vertex[i][j] < 2 || vertex[i+len][j]<2 || vertex[i][j+len]<2 || vertex[i+len][j+len]<2)
        return 0;
    for (k=0; k<len; ++k) {
        if(!exist_horizon(i,j+k) || !exist_horizon(i+len, j+k))
            return 0;
        if(!exist_vertical(i+k, j) || !exist_vertical(i+k, j+len))
            return 0;
    }
    return 1;
}

void print_vetex(int n)
{
    int i,j;
    for (i = 1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            printf("%3d",vertex[i][j]);
        }
        printf("\n");
    }
}

void print_board(int n)
{
    int i,j;
    for (i = 1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            printf("%3d",board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m,n,p,q,count;
    char c;
    int i,j,k;
    int kcase = 0;
    while (scanf("%d%d",&n,&m)==2 && n) {
        memset(board,0,sizeof(board));
        memset(vertex, 0, sizeof(vertex));
        memset(square, 0, sizeof(square));
        getchar();
        while (m--) {
            scanf("%c%d%d",&c,&p,&q);
            if(c=='H'){
                board[p][q]+=1;
                vertex[p][q]++;
                vertex[p][q+1]++;
            }else{
                board[q][p]+=2;
                vertex[q][p]++;
                vertex[q+1][p]++;
            }
            getchar();
        }
//        print_vetex(n);
//        print_board(n);
        count = 0;

        for (i = 1; i<n; ++i) {
            for (k=1; k<n; ++k) {
                if (board[i][k] != 3) {
                    continue;
                }
                
                for (j=1; j<=n-i && j <= n-k; ++j) {//size
                    if(exist_squre(i,k,j))
                    {
                        square[j]++; count++;
                    }
                }
                
            }
        }
        if(kcase>0)
            printf("\n**********************************\n\n");
        printf("Problem #%d\n\n",++kcase);
        
        if(!count)
        {
            printf("No completed squares can be found.\n");
            continue;
        }
        for (int i=1; i<=n; ++i) {
            if(square[i])
                printf("%d square (s) of size %d\n",square[i], i);
        }
    }
}