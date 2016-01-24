//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n;
    while(std::cin>>n && n > 0){
        std::queue<int> hand;
        std::queue<int> throwing;
        for (int i = 1; i <= n; ++i) {
            hand.push(i);
        }
        while(hand.size()>1){
            throwing.push(hand.front());
            hand.pop();
            if(hand.size()<2)
                break;
            hand.push(hand.front());
            hand.pop();
        }
        std::cout<<"Discarded cards:";
        while(throwing.size()>1)
        {
            std::cout<<" "<<throwing.front()<<",";
            throwing.pop();
        }
        if(throwing.size())
            std::cout<<" "<<throwing.front();
        std::cout<<std::endl;
        std::cout<<"Remaining card: "<<hand.front()<<std::endl;
    }
    return 0;
}