//
// Created by luerfeng on 2016/01/17.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>

const int win_prize_player = 70;
const int max_player_cnt = 144;

std::vector<std::string> score[max_player_cnt];
std::string name_list[max_player_cnt];
std::multimap<int,int> score_id_map;
std::vector<int> score_list;

bool is_ameture(std::string& name)
{
    if(name.find_last_not_of('*') != std::string::npos)
        return true;
    return false;
}

void print_title()
{
    std::cout<<"Player Name         Place     RD1   RD2   RD3"<<std::endl;
    for (int i = 0; i < 72; ++i) {
        std::cout<<"-";
    }
    std::cout<<std::endl;
}


int main()
{
    int T;
    std::cin>>T;
    while(T--){
        double total;
        std::map<std::string, int> name_id_map;
        std::cin>>total;
        std::vector<double> alloc_percentage;
        for (int i = 0; i < win_prize_player; ++i) {
            double percentage;
            std::cin>>percentage;
            alloc_percentage.push_back(percentage);
        }
        int players_no;
        std::cin >> players_no;
        std::cin.ignore();
        std::string line;
        std::set<int> valid_id_set;
        while(players_no--){
            std::getline(std::cin, line);
            std::string seg = line.substr(0,20);
            line = line.substr(20, std::string::npos);
            name_list[players_no] = seg;
            int count=0;
            std::stringstream ss(line);
            int cnt = 0;
            int total = 0;
            while(std::cin>>seg){
                cnt++;
                score[players_no].push_back(seg);
                if(seg[0] != 'D')
                    total += atoi(seg);
            }
            if(cnt>2){
                valid_id_set.insert(players_no);}
            if(cnt==4) {
                score_id_map.insert(std::make_pair<total, players_no>);
                score_list.push_back(total);
            }
        }
        std::sort(score_list.begin(), score_list.end());
        print_title();
        for (int i = 0; i < valid_id_set.size(); ++i) {
            int offset = 0;
            int limit = 0;
            limit = score_id_map.count(score_list[offset]);
            for (int j = 0; j < limit; ++j) {

            }
            offset += limit;
        }

    }
}