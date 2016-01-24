//
// Created by luerfeng on 2016/01/16.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define ULL unsigned long long
//std::vector<unsigned int> ugly_numbers;

ULL nth_ugly_number(int n) {
    std::priority_queue<ULL, std::vector<ULL>, std::greater<ULL> > q;
    std::set<ULL> s;
    int ugly[] = {2, 3, 5};
    q.push(1);
    while(1){
        ULL t = q.top();
        for (int j = 0; j < 3; ++j) {
            if (!s.count(t*ugly[j])) {
                s.insert(t*ugly[j]);
                q.push(t*ugly[j]);
            }
        }
        if(n==1)
            return q.top();
        q.pop(); n--;
    }
}

int main() {
//    nth_ugly_number(15);
//    for (std::vector<unsigned int>::iterator it = ugly_numbers.begin(); it != ugly_numbers.end() ; ++it) {
//        std::cout<<*it<<std::endl;
//    }
    std::cout<<"The 1500'th ugly number is "<<nth_ugly_number(1500)<<"."<<std::endl;
    return 0;
}