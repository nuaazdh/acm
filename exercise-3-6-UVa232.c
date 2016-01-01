//
//  exercise-3-6-UVa232.c
//  acm
//
//  Created by luerfeng on 15/12/28.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

#define PUZZLE_SIZE 12

char puzzle[PUZZLE_SIZE][PUZZLE_SIZE];

void print_puzzle(char puzzle[][PUZZLE_SIZE], int m, int n)
{
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if(j!=0) printf(" ");
            printf("%c",puzzle[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m,n;
    int kcase = 0;
    while (1) {
        while(scanf("%d", &m)!=1);
        if(m==0)
            return 0;
        while(scanf("%d", &n)!=1);
//        printf("m=%d n=%d\n", m, n);
        int c = getchar();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                c = getchar();
//                printf("get:%c for i=%d j=%d\n",c,i,j);
                puzzle[i][j] = c;
            }
            c = getchar();
        }
        if (kcase) {
            printf("\n");
        }
//        print_puzzle(puzzle, m, n);
        printf("puzzle #%d:\nAcross\n", ++kcase);
        int no = 1;
        for (int i=0; i<m; ++i) {
            int hasno = 0;
            for (int j=0; j<n; ++j) {
                if(puzzle[i][j] == '*'){
                    if(hasno ==0 ) continue;
                    else{ printf("\n"); hasno = 0;}
                }else{
                    if( hasno== 0) printf("%3d.",no);
                    hasno = 1;
                    putchar(puzzle[i][j]);
                    if(i==0 || puzzle[i-1][j] == '*'|| j==0 ||(j>0 && puzzle[i][j-1] == '*')) no++;
                    if(j==n-1) printf("\n");
                }
            }
        }
        printf("Down\n");
        no = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if(puzzle[i][j] == '*' ){
                    continue;
                }else{
                    if(i==0 || puzzle[i-1][j] == '*')
                        printf("%3d.",no);
                    if(i==0 || puzzle[i-1][j] == '*'|| j==0 || (j>0 && puzzle[i][j-1] == '*')) no++;
                    if(i!=0 && puzzle[i-1][j] != '*')
                        continue;
                    int k = i;
                    while (puzzle[k][j]!='*' && k<m) {
                        putchar(puzzle[k++][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
}