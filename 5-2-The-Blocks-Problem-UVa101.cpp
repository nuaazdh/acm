/*
 *
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void find_block(std::vector< std::vector<int> >&v, int a, int& p, int& h)
{
    h = 0;
    for (p = 0; p < v.size(); ++p) {
        h = std::find(v[p].begin(), v[p].end(),a) - v[p].begin();
        if(h < v[p].size()) {
            ++h;
            break;
        }
    }
}

void clear_above(std::vector< std::vector<int> >&v, int p, int h)
{
    while (v[p].size()>h) {
        v[v[p].back()].push_back(v[p].back());
        v[p].pop_back();
    }
}

void pile(std::vector< std::vector<int> >&v , int ap, int ah, int bp)
{
    stack<int> st;
    while (v[ap].size() >= ah) {
        st.push(v[ap].back());
        v[ap].pop_back();
    }
    while(!st.empty()) {
        v[bp].push_back(st.top());
        st.pop();
    }
}

void init(std::vector< std::vector<int> > &v,int n)
{
    for (int i = 0; i < n; ++i) {
        vector<int> vt;
        vt.push_back(i);
        v.push_back(vt);
    }
}

void print_result(std::vector< std::vector<int> >& v)
{
    for (int i = 0; i<v.size(); ++i) {
        cout<<i<<":";
        for (int j = 0; j < v[i].size(); ++j) {
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }
}

int main() {

    int n,a,b,ap,ah, bp,bh;
    string cmd, type;
    std::vector< std::vector<int> > v;
    cin>>n;
    init(v,n);
    while(1){
        cin>>cmd;
        if(cmd.compare("quit")==0){
            print_result(v);
            break;
        }
        cin>>a>>type>>b;
        find_block(v,a,ap,ah);
        find_block(v,b,bp,bh);
        if(ah<0 || bh<0)
        {
            continue;
        }
        if(ap==bp)
            continue;
        if(type.compare("onto")==0)
            clear_above(v,bp,bh);
        if(cmd.compare("move")==0)
            clear_above(v,ap,ah);

        pile(v,ap,ah,bp);
    }
    return 0;
}