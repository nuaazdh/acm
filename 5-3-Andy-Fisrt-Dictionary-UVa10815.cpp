/**
 *
 *
 *
 */
#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    set<string> dict;
    string word;
    while(cin>>word) {
        for (int i = 0; i < word.length(); ++i) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            } else {
                word[i] = ' ';
            }
        }
        stringstream ss(word);
        while(ss >> word)  dict.insert(word);
    }
    for(set<string>::iterator it=dict.begin(); it!=dict.end();++it){
        cout<<*it<<endl;
    }
    return 0;
}