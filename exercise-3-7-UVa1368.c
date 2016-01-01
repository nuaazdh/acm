//
//  exercise-3-7.c
//  acm
//
//  Created by luerfeng on 15/12/29.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_M 55
#define MAX_N 1010

char dna[MAX_M][MAX_N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int m,n;
        scanf("%d%d", &m, &n);
        getchar();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                int c = getchar();
                dna[i][j] = c;
            }
            getchar();
        }
        
//        printf("m=%d n=%d\n",m,n);
//        for (int i=0; i<m; ++i) {
//            for (int j=0; j<n; ++j) {
//                putchar(dna[i][j]);
//            }
//            putchar('\n');
//        }
        
        int dist = 0;
        for (int i=0; i<n; ++i) {
            int a = 0, c=0, g=0, t=0;
            for (int j=0; j<m; ++j) {
                switch (dna[j][i]) {
                    case 'A':
                        a++;break;
                    case 'G':
                        g++;break;
                    case 'C':
                        c++;break;
                    case 'T':
                        t++;break;
                    default:
                        break;
                }
            }
//            printf("a=%d c=%d g=%d t=%d\n",a,g,c,t);
            if(a>=c && a>=g && a>=t){
                putchar('A');
                dist += c+g+t;
            }else if(c>=a&&c>=g&&c>=t){
                putchar('C');
                dist+=a+g+t;
            }else if(g>=a&&g>=c&&g>=t){
                putchar('G');
                dist+=a+c+t;
            }else{
                putchar('T');
                dist+=a+c+g;
            }
        }//for i
        printf("\n%d\n", dist);
    }//while
    return 0;
}