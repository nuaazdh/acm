//
//  2-5-statistics-number.c
//  acm
//
//  Created by luerfeng on 15/12/20.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n) == 1 && n )
    {
        double sum=0.0;
        int case_no = 0;
        int num, max, min;
        for (int i=0; i<n; ++i) {
            scanf("%d", &num);
            sum += num;
            if(i==0){
                max = min = num;
            }else{
                if(num > max) max = num;
                if(num < min) min = num;
            }
        }//for
        if(case_no)
            printf("\n");
        printf("Case %d: %d %d %.3f\n",++case_no, min, max, sum/n);
    }//while
    
    return 0;
}