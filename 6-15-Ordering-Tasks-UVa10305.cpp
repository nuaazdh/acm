//
// Created by luerfeng on 2016/01/30.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <vector>
#include <string.h>

const int max_size = 2000;
int visit[max_size];
int post_task[max_size];
int graph[max_size][max_size];
std::vector<int> ans;

void dfs(int nth) {
    if (visit[nth] == 1)
        return;
    visit[nth] = 1;
    for (int i = 1; i <= graph[nth][0]; ++i) {
//        if (visit[graph[nth][i]] != 2)
        dfs(graph[nth][i]);

    }
//    visit[nth] = 2;
    ans.push_back(nth);
    return;
}


int main() {
    int m, n;
    while (scanf("%d %d", &n, &m) && (m || n)) {
        memset(graph, 0, sizeof(graph));
        memset(visit, 0, sizeof(visit));
        memset(post_task, 0, sizeof(post_task));
        ans.clear();
        int a, b;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            ++graph[a][0];
            graph[a][graph[a][0]] = b;
            ++post_task[b];
        }
        // DAG
        for (int i = 1; i <= n; ++i) {
            if (!post_task[i])
                dfs(i);
        }
        for (std::vector<int>::iterator it = ans.end() - 1; it != ans.begin(); --it) {
            printf("%d ", *it);
        }
        printf("%d\n", *(ans.begin()));
    }
    return 0;
}