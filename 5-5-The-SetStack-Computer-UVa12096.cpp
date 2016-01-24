//
// Created by luerfeng on 2016/{01}/14.
// Description:
//
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<set<int> , int>  id_map;
vector<set<int> >  set_cache;

int getId(set<int> s)
{
    if(!(id_map.count(s)))
    {
        set_cache.push_back(s);
        id_map[s] = set_cache.size()-1;
    }
    return id_map[s];
}


int main() {
    int n, m;
    stack<int> st;
    string cmd;
    cin >> n;
    while (n--) {
        id_map.clear(); set_cache.clear();
        cin >> m;
        while (m--) {
            cin >> cmd;
            if(cmd[0]=='P'){
                set<int> s;
                st.push(getId(s));
            }else if(cmd[0] == 'D'){
                st.push(st.top());
            }else {
                set<int> a = set_cache[st.top()];
                st.pop();
                set<int> b = set_cache[st.top()];
                st.pop();
                set<int> ret;
                if (cmd[0] == 'I') {
                    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(ret, ret.begin()));
                } else if (cmd[0] == 'U') {
                    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(ret, ret.begin()));
                } else if (cmd[0] == 'A') {
                    ret = b;
                    ret.insert(getId(a));
                }
                st.push(getId(ret));
            }
            cout<<(set_cache[st.top()]).size()<<endl;
        }
        cout << "***" << endl;
    }
}