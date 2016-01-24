//
// Created by luerfeng on 2016/01/16.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

const int max_row = 10010;
vector<int> database[max_row];


int main() {
    int m, n;
    while (cin >> m >> n) {
        int cnt =  0;
        map<string, int> simap;
        cin.ignore();
        for (int i = 0; i < m; ++i) {
            string line;
            std::getline(cin, line);
            database[i].clear();
            for (int j = 0; j < n; ++j) {
                string value;
                int pos = line.find_first_of(',');
                if(pos != string::npos){
                    value = line.substr(0, pos);
                    line = line.substr(pos + 1, string::npos);
                }else{
                    value = line;
                }
                if(!simap.count(value)){
                    simap[value] = cnt++;
                }
                database[i].push_back(simap[value]);
            }
        }//for
        bool found = false;
        for (int i = 0; i < n -1 ; ++i) {
            for (int j = i+1; j < n; ++j) {
                map<string, int> has;
                for (int k = 0; k < m; ++k) {
                    string str = std::to_string(database[k][i])+"_"+std::to_string(database[k][j]);
                    if(has.count(str)){
                        cout<<"NO"<<endl;
                        cout<<has[str]+1<<" "<<k+1<<endl;
                        cout<<i+1<<" "<<j+1<<endl;
                        found = true;
                        break;
                    }else{
                        has[str] = k;
                    }
                }
                if(found) break;
            }
            if(found) break;
        }
        if(!found) cout<<"YES"<<endl;


    }
    return 0;
}