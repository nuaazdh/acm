//
//  4-5-Spreadsheet-Tracking-UVa512.c
//  acm
//
//  Created by luerfeng on 16/1/3.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_TABLE_SIZE 100

int row,column;
int row_o, column_o;
int table[MAX_TABLE_SIZE][MAX_TABLE_SIZE];
int cmd[MAX_TABLE_SIZE];

void init_table()
{
    memset(table,0,sizeof(table));
    for (int i=1; i<=row; ++i) {
        for (int j=1; j<=column; ++j) {
            table[i][j] = (i-1)*column+j;
        }
    }
}

void delete_row(int r)
{
    for (int i=r; i<=row; ++i) {
        for (int j=1; j<=column; ++j) {
            table[i][j] = table[i+1][j];
        }
    }
    --row;
}

void delete_col(int c)
{
    for (int i=1; i<=row; ++i) {
        for (int j=c; j<=column; ++j) {
            table[i][j] = table[i][j+1];
        }
    }
    --column;
}

void insert_row(int r)
{
    ++row;
    for (int i=row; i>=r; --i) {
        for (int j=1; j<=column; ++j) {
            table[i][j] = table[i-1][j];
        }
    }
    for (int j=1; j<=column; ++j) {
        table[r][j] = 0;
    }
}

void insert_column(int c)
{
    ++column;
    for (int i=1; i<=row; ++i) {
        for (int j=column; j>=c; --j) {
            table[i][j] = table[i][j-1];
        }
    }
    for (int i=1; i<=row; ++i) {
        table[i][c] = 0;
    }
}

void exchange(int r1, int c1,int r2, int c2)
{
    int tmp = table[r1][c1];
    table[r1][c1] = table[r2][c2];
    table[r2][c2] = tmp;
}

void print_table()
{
    for (int i=1; i<=row; ++i) {
        for (int j=1; j<=column; ++j) {
            printf("%4d",table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void query_table(int r, int c)
{
    for (int i=1; i<=row; ++i) {
        for (int j=1; j<=column; ++j) {
            if (table[i][j] == ((r-1)*column_o+c)) {
                printf("moved to (%d,%d)\n",i,j);
                return;
            }
        }
    }
    printf("GONE\n");
}

int main()
{
    int kcase = 0;
    while ((scanf("%d%d", &row_o, &column_o) == 2) && row_o) {
        row = row_o; column = column_o;
        if(kcase) printf("\n");
        printf("Spreadsheet #%d\n", ++kcase);
        init_table();
//        print_table();
        int command;
        scanf("%d",&command);
        char command_line[100];
        while (command--) {
            scanf("%s",command_line);
            if(strcasecmp(command_line, "EX")==0)
            {
                int r1,c1,r2,c2;
                scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
                exchange(r1, c1, r2, c2);
            }else if(strcasecmp(command_line, "DR")==0){
                int count = 0;
                scanf("%d",&count);
                memset(cmd, 0, sizeof(cmd));
                while(count--) {
                    int r;
                    scanf("%d",&r);
                    cmd[r] = 1;
                }
                for (int i=MAX_TABLE_SIZE-1; i>0; --i) {
                    if(cmd[i]) delete_row(i);
                }
                
            }else if(strcasecmp(command_line, "DC")==0){
                int count = 0;
                scanf("%d",&count);
                memset(cmd, 0, sizeof(cmd));
                while(count--) {
                    int r;
                    scanf("%d",&r);
                    cmd[r] = 1;
                }
                for (int i=0,j=0 ; i<MAX_TABLE_SIZE; ++i) {
                    if(cmd[i]) { delete_col(i-j); j++; }
                }
            }else if(strcasecmp(command_line, "IR")==0){
                int count = 0;
                scanf("%d",&count);
                memset(cmd, 0, sizeof(cmd));
                while(count--) {
                    int r;
                    scanf("%d",&r);
                    cmd[r] = 1;
                }
                for (int i=0,j=0 ; i<MAX_TABLE_SIZE; ++i) {
                    if(cmd[i]) { insert_row(i+j); j++; }
                }
            }else if(strcasecmp(command_line, "IC")==0){
                int count = 0;
                scanf("%d",&count);
                memset(cmd, 0, sizeof(cmd));
                while(count--) {
                    int r;
                    scanf("%d",&r);
                    cmd[r] = 1;
                }
                for (int i = MAX_TABLE_SIZE -1 ; i > 0; --i) {
                    if(cmd[i])  insert_column(i);
                }
            }
//            print_table();
        }
        int query;
        scanf("%d",&query);
        while (query--) {
            int r,c;
            scanf("%d%d",&r,&c);
            printf("Cell data in (%d,%d) ",r,c);
            query_table(r,c);
        }
    }
    return 0;
}