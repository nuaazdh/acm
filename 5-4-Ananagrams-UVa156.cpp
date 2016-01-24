//
// Created by luerfeng on 16/1/14.
//

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void convert_string(string &str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    sort(str.begin(),str.end());
}

int main()
{
    set<string> word_set;
    map<string, int> word_cnt;
    string word;
    while(cin>>word){
        if(word.compare("#")==0)
            break;
        word_set.insert(word);
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        sort(word.begin(),word.end());
        if(word_cnt.find(word)!=word_cnt.end()){
            word_cnt[word] ++;
        }else{
            word_cnt[word] = 1;
        }
    }

    for (set<string>::iterator it = word_set.begin(); it != word_set.end(); ++it) {
        string word = *it;
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        sort(word.begin(),word.end());
        if(word_cnt[word]==1)
            cout<<*it<<endl;
    }

}