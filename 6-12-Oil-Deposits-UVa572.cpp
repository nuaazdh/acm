//
// Created by luerfeng on 2016/01/28.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>

int dr[]={-1,-1,-1,0,0,1,1,1}, dc[]={-1,0,1,-1,1,-1,0,1};

#define MAX_SIZE 110

char deposit[MAX_SIZE][MAX_SIZE];


int is_valid_position(int m, int n, int i , int j)
{
    return (i>=0 && i<m && j>=0 && j<n);
}

void remove_one_deposit(int m, int n, int i, int j)
{
    int di,dj;
    if(!is_valid_position(m,n,i,j) || deposit[i][j]!='@')
        return;
    deposit[i][j] = '*';
    for (di = 0; di < 8; ++di) {
        for (dj = 0; dj < 8; ++dj) {
            if(is_valid_position(m,n,i+dr[di],j+dc[dj])){
                remove_one_deposit(m,n,i+dr[di],j+dc[dj]);
            }
        }
    }
}

int find_and_remove_deposit(int m, int n)
{
    int i,j,found=0;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            if(deposit[i][j]== '@') {
                found = 1;
                break;
            }
        }
        if(found) break;
    }
    if(!found) /* not found */
        return 0;
    remove_one_deposit(m,n,i,j);
    return 1;
}

void read_deposit(int m, int n)
{
    int i;
    for (i = 0; i < m; ++i) {
        scanf("%s",deposit[i]);
    }
}

void print_deposit(int m,int n)
{
    int i,j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%c",deposit[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int row,col,cnt=0;
    while(scanf("%d%d", &row, &col) && row){
        read_deposit(row,col);
//        print_deposit(row,col);
        cnt = 0;
        while(find_and_remove_deposit(row,col)!=0) {
            cnt++;
//            print_deposit(row,col);
//            printf("\n\n");
        }
        printf("%d\n", cnt);
    }
    return 0;
}