//
//  exercise-4-1-UVa1589.c
//  acm
//
//  Created by luerfeng on 16/1/3.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define ROW_SIZE 10
#define COL_SIZE 9

char cheese[11][10];
int row, col;
int next_step[4][2];
int next_pos_poss = 0;

int is_valid(int r, int c)
{
    if(r>=1 && r<=3 && c >= 4 && c<=6)
        return 1;
    return 0;
}

int is_valid_place(int r, int c)
{
    if(r>=1 && r<ROW_SIZE && c >=1 && c<=COL_SIZE)
        return 1;
    return 0;
}

void insert_poss_pos(int r, int c)
{
    next_step[next_pos_poss][0] = r; next_step[next_pos_poss][1] = c;
    next_pos_poss++;
}

void print_cheese()
{
    int i,j;
    for (i=1; i<=ROW_SIZE; ++i) {
        for (j=1; j<COL_SIZE; ++j) {
            printf("%c ",cheese[i][j]);
        }
        printf("\n");
    }
}

void print_move()
{
    int i;
    for (i = 0; i<next_pos_poss; ++i) {
        printf("%d: row=%3d, col=%3d\n",i,next_step[i][0],next_step[i][1]);
    }
    printf("\n");
}

void find_move()
{
    next_pos_poss = 0;
    if(is_valid(row-1, col))  insert_poss_pos(row-1, col);
    if(is_valid(row, col-1))  insert_poss_pos(row, col-1);
    if(is_valid(row+1, col))  insert_poss_pos(row+1, col);
    if(is_valid(row, col+1))  insert_poss_pos(row, col+1);
}

int is_there_horse(int r, int c)
{
    if(is_valid_place(r-2, c-1) && cheese[r-2][c-1] == 'H' && !cheese[r-1][c-1]) return 1;
    if(is_valid_place(r-2, c+1) && cheese[r-2][c-1] == 'H' && !cheese[r-1][c+1]) return 1;
    if(is_valid_place(r-1, c-2) && cheese[r-1][c-2] == 'H' && !cheese[r-1][c-1]) return 1;
    if(is_valid_place(r+1, c-2) && cheese[r+1][c-2] == 'H' && !cheese[r+1][c-1]) return 1;
    
    if(is_valid_place(r-1, c+2) && cheese[r-1][c+2] == 'H' && !cheese[r-1][c+1]) return 1;
    if(is_valid_place(r+1, c+2) && cheese[r+1][c+2] == 'H' && !cheese[r+1][c+1]) return 1;
    if(is_valid_place(r+2, c-1) && cheese[r+2][c-1] == 'H' && !cheese[r+1][c-1]) return 1;
    if(is_valid_place(r+2, c+1) &&
       cheese[r+2][c+1] == 'H' &&
       !cheese[r+1][c+1]) return 1;
    return 0;
}

int check_dead(int r, int c)
{
    int i,j;
    for(i=r+1,j=0; i <= ROW_SIZE; ++i)
    {
        if(!cheese[i][c]) continue;
        ++j;
        if((j == 1) && (cheese[i][c] == 'G' || (cheese[i][c] == 'R')))
            return 1;
        if(j==2 && cheese[i][c] == 'C')
            return 1;
    }
    for (i = r-1,j=0; i>=1; --i) {
        if(!cheese[i][c]) continue;
        ++j;
        if(cheese[i][c] == 'R' && j==1)
            return 1;
        if(j==2 && cheese[i][c] == 'C')
            return 1;
    }
    for(i=c+1;i<=COL_SIZE;++i)
    {
        if(!cheese[r][i]) continue;
        ++j;
        if(j>2) break;
        if(cheese[r][i] == 'R' && j==1)
            return 1;
        if(j==2 && cheese[r][i] == 'C')
            return 1;
    }
    for(i=1,j=0;i<c;++i)
    {
        if(!cheese[r][i]) continue;
        ++j;
        if(j>2) break ;
        if(cheese[r][i] == 'R' && j==1)
            return 1;
        if(j==2 && cheese[r][i] == 'C')
            return 1;
    }
    if (is_there_horse(r,c)) {
        return 1;
    }
    return 0;
}


int main()
{
    char t;
    int count,r,c,i;
    while (scanf("%d%d%d",&count,&row,&col) == 3 && count) {
        memset(cheese,0,sizeof(cheese));
        getchar();
        while (count--) {
            if(scanf("%c%d%d",&t,&r,&c)==3)
                cheese[r][c] = t;
            getchar();
        }
        find_move();
//        print_cheese();
//        print_move();
        for (i=0; i<next_pos_poss; ++i) {
            if(check_dead(next_step[i][0], next_step[i][1])==0)
            {
                printf("NO\n");
                break;
            }
        }
        if (i>=next_pos_poss){
            printf("YES\n");
        }
        while((c=getchar())!='\n');
    }
    return 0;
}
