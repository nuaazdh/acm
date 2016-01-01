//
//  exercise-3-5-UVa227.c
//  acm
//
//  Created by luerfeng on 15/12/25.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define PUZZLE_SIZE 5

char puzzle[PUZZLE_SIZE][PUZZLE_SIZE];
char operation[100];

void print_puzzle(char puzzle[][PUZZLE_SIZE])
{
    for (int i=0; i<PUZZLE_SIZE; ++i) {
        for (int j=0; j<PUZZLE_SIZE; ++j) {
            if(j != 0)
                printf(" ");
            printf("%c", puzzle[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int finish = 0;
    int kcase= 0;
    for (; ; ) {
        int col = 0, row = 0;
        int c;
        for (int i=0; i<PUZZLE_SIZE; ++i) {
            for (int j=0; j<PUZZLE_SIZE; ++j) {
                c = getchar();
                if(c == 'Z'){
                    return 0;
                }
                puzzle[i][j] = c;
                if(puzzle[i][j] == ' '){
                    row = i; col = j;
                }
            }
            getchar();
            if(finish) break;
        }
        if(finish) break;
//        print_puzzle(puzzle);
//        printf("row = %d col = %d\n",row,col);
        
        memset(operation, 0, sizeof(operation));
        int k=0;
        while (1) {
            scanf("%s",operation+k);
            if(operation[strlen(operation)-1] == '0') break;
            k = strlen(operation);
        }
//        printf("%s\n",operation);
        getchar();
        for (k=0; operation[k] != '0'; ++k){
            if(operation[k] == 'A'){
                if(row<=0) break;
                puzzle[row][col] = puzzle[row-1][col];
                --row;
            }else if(operation[k] == 'B'){
                if (row>=PUZZLE_SIZE-1) break;
                puzzle[row][col]= puzzle[row+1][col];
                ++row;
            }else if(operation[k] == 'L'){
                if(col<=0) break;
                puzzle[row][col] = puzzle[row][col-1];
                --col;
            }else if(operation[k] =='R'){
                if(col>=PUZZLE_SIZE-1) break;
                puzzle[row][col] = puzzle[row][col+1];
                ++col;
            }else{
                break;
            }
//            printf("%d %d\n",row,col);
//            print_puzzle(puzzle);
        }
        if(kcase)
            printf("\n");
        printf("Puzzle #%d:\n",++kcase);
        if(operation[k]!='0'){
            printf("This puzzle has no final configuration.\n");
        }else{
            puzzle[row][col]= ' ';
            print_puzzle(puzzle);
        }
    }
    return 0;
}