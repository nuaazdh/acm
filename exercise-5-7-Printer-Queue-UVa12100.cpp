//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <queue>

int main()
{
    int T;
    std::cin>>T;
    while(T--){
        int n,pos, num;
        std::priority_queue<int, std::vector<int>, std::less<int> > job_queue;
        std::queue<int> siml_queue;
        std::cin>>n>>pos;
        while(n--){
            std::cin>>num;
            job_queue.push(num);
            siml_queue.push(num);
        }
        int wait = 0;
        while(1){
            if(siml_queue.front() != job_queue.top()){
                int front = siml_queue.front();
                siml_queue.pop();
                siml_queue.push(front);
                pos = (pos - 1+siml_queue.size())%siml_queue.size();
            }else{
                job_queue.pop();
                siml_queue.pop();
                wait++;
                if(pos==0)
                {
                    std::cout<<wait<<std::endl;
                    break;
                }
                pos--;
            }
        }
    }
}