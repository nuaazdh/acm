//
//  exercise-3-10-UVa1587.c
//  acm
//
//  Created by luerfeng on 15/12/30.
//  Copyright © 2015年 luerfeng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int box_size[6][3];
int arc[12];

int main()
{
    int w,h,t,kcase=0, face_type=0, arc_type=0;
    while (scanf("%d %d", &w, &h) != EOF) {
        if(kcase == 0) {
            memset(box_size,0,sizeof(box_size));
            memset(arc, 0, sizeof(arc));
        }
        kcase++;
        
        if (w<h) {
            t=w;w=h;h=t;
        }
        
        int i;
        for (i=0; i<face_type; ++i) {
            if(box_size[i][0] == w && box_size[i][1]==h)
            {
                box_size[i][2]++;break;
            }
        }
        if(i>=face_type)
        {
            box_size[face_type][0] = w;
            box_size[face_type][1] = h;
            box_size[face_type][2] = 1;
            face_type++;
        }
        
        if(kcase%6==0)
        {
//            for (int i=0; i<face_type; ++i) {
//                printf("%d %d %d\n",box_size[i][0],box_size[i][1],box_size[i][2]);
//            }
            
            kcase=0;
            int poss = 1;
            if(face_type > 3){
//                printf("face type=%d\n",face_type);
                poss = 0;
            }else{
                int i;
                for (i=0; i<face_type; ++i) {
                    if(box_size[i][2] %2 )
                    {
                        poss = 0;break;
                    }else{
                        int j;
                        for (int k = 0; k<2; ++k) {
                            for (j=0; j<arc_type; ++j) {
                                if (box_size[i][k] == arc[2*j]) {
                                    arc[2*j+1] += box_size[i][2];
                                    break;
                                }
                            }
                            if(j>=arc_type)
                            {
                                arc[2*arc_type] = box_size[i][k];
                                arc[2*arc_type+1] = box_size[i][2];
                                arc_type++;
                            }

                        }//for k
                        
                    }//else
                }//for
                if(poss){
                    int j;
                    for(j = 0;j<arc_type;++j)
                    {
                        if(arc[2*j+1] %4 != 0)
                        {
                            poss = 0;
                            break;
                        }
                    }
//                    for (int k=0; k<2*(arc_type); ++k) {
//                        printf("%d ", arc[k]);
//                    }
//                    printf("\n");
                    if(j >= arc_type) poss = 1;
                }
            }
            
            if(poss)
                printf("POSSIBLE\n");
            else
                printf("IMPOSSIBLE\n");
            face_type = 0;
            arc_type = 0;
        }
    }
    return 0;
}
