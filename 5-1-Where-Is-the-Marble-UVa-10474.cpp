#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,q,num,kcase=0;
    vector<int> marbles;
    while(cin>>n>>q && n)
    {
        marbles.clear();
        cout<<"CASE# "<<++kcase<<":"<<endl;
        while(n--)
        {
            cin>>num;
            marbles.push_back(num);
        }
        sort(marbles.begin(),marbles.end());
        while(q--)
        {
            cin>>num;
            int pos = find(marbles.begin(),marbles.end(),num) - marbles.begin();
            if(pos>=marbles.size())
            {
                cout<<num<<" not found"<<endl;
            }else{
                cout<<num<<" found at "<<pos+1<<endl;
            }
        }
    }

    return 0;
}