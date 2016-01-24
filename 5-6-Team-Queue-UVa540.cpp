//
// Created by luerfeng on 2016/01/16.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int const TEAM_SIZE = 1000;

int main() {
    int n;
    string cmd;
    int kcase = 0;
    while (cin >> n && n) {
        cout << "Scenario #" << ++kcase << endl;

        int m, num;
        queue<int> id_queue, team_queue[TEAM_SIZE];
        map<int, int> num_queue_id_map;
        while (n--) {
            cin >> m;
            while (m--) {
                cin >> num;
                num_queue_id_map[num] = n;
            }
        }
        while (1) {
            cin >> cmd;
            if (cmd[0] == 'S')
                break;
            if (cmd[0] == 'E') {
                cin >> num;
                int id = num_queue_id_map[num];
                if (team_queue[id].empty()) {
                    id_queue.push(id);
                }
                team_queue[id].push(num);
            } else {
                int t = id_queue.front();
                cout << team_queue[t].front() << endl;
                team_queue[t].pop();
                if (team_queue[t].empty()) {
                    id_queue.pop();
                }
            }
        }
        cout << endl;
    }
}
