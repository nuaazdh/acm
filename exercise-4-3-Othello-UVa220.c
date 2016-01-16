//
//  exercise-4-3-Othello-UVa220.c
//  acm
//
//  Created by luerfeng on 16/1/4.
//  Copyright © 2016年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char othello[10][10];
int dr[] = {-1,-1,-1,0,0,1,1,1} , dc[] = {-1,0,1,-1,1,-1,0,1};
int w,b;

char switch_player(char current)
{
    return current=='B' ? 'W' : 'B';
}

void print_othello()
{
    for(int i=0;i<8;++i){
        for (int j=0; j<8; ++j) {
            putchar(othello[i][j]);
        }
        putchar('\n');
    }
}

int is_valid_place(int x, int y)
{
    return x>=0 && x<8 && y>=0 && y<8;
}

int valid_place(char type, int x, int y)
{
    char px=x, py=y, c = (type == 'W' ? 'B' : 'W');
    for (int i=0; i<8; ++i) {
        int j = 1;
        x=px+dr[i];
        y=py+dc[i];
        while (is_valid_place(x,y) && othello[x][y] == c)
        {
            x+=dr[i];
            y+=dc[i];
            ++j;
        }
        if(j > 1 && is_valid_place(x,y) && othello[x][y] == type)
        {
            return 1;
        }
    }
    return 0;
}

int list_player(char type)
{
    int count = 0;
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            if(othello[i][j] == '-' && valid_place(type, i,j))
            {
                if (count) {
                    putchar(' ');
                }
                printf("(%d,%d)",i+1,j+1); count++;
            }
        }
    }
    if (!count) {
        puts("No legal move.");
        return 0;
    }
    putchar('\n');
    return 1;
}

void print_move()
{
    int b=0, w=0;
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            if(othello[i][j]=='B') ++b;
            if(othello[i][j]=='W') ++w;
        }
    }
    printf("Black - %2d White - %2d\n",b,w);
}


void move_player(char type, int x, int y)
{
    othello[x][y] = type;
    char c = switch_player(type);
    
    for (int i=0; i<8; ++i) {
        int px=x+dr[i], py=y+dc[i], j = 1;
        while (is_valid_place(px, py) && othello[px][py]==c) {
            ++j; px+=dr[i], py+=dc[i];
        }
        if(is_valid_place(px, py) && othello[px][py]== type)
        {
            for (int k = 1; k<=j; ++k) {
                othello[px][py] = type;
                px-=dr[i], py-=dc[i];
            }
        }
    }
    print_move();
    
}


int main()
{
    int n, kcase = 0;
    int c;
    scanf("%d",&n);
    while (n--) {
        if(!kcase) getchar();
        memset(othello, 0, sizeof(othello));
        w = b = 0;
        for (int i=0; i<8; ++i) {
            for (int j=0; j<8; ++j) {
                c=getchar();
                if(c=='B') b++;
                if(c=='W') w++;
                othello[i][j] = c;
            }
            getchar();
        }
//            print_othello();
        
        char cmd[10];
        char current_player;
        current_player = getchar();
        while (1) {
            memset(cmd, 0, sizeof(cmd));
            scanf("%s",cmd);
            if(cmd[0] == 'Q') //quit
            {
                print_othello();break;
            }
            if(cmd[0]=='L'){
                if(!list_player(current_player))
                    current_player = switch_player(current_player);
            }else if (cmd[0]=='M')
            {
                move_player(current_player, cmd[1]-'1', cmd[2]-'1');
                current_player = switch_player(current_player);
            }else{
            }
        }
        if(n) putchar('\n');
    }//while
    return 0;
}

