//
// Created by luerfeng on 2016/02/20.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <set>

struct Pour {
    int a, b, c;
    int incr;

    Pour(int aa = 0, int bb = 0, int cc = 0, int s = 0x3fff) : a(aa), b(bb), c(cc), incr(s) { }

    bool operator<(const Pour &rhs) const {
        return this->incr > rhs.incr;
    }
};

bool operator==(const Pour &lhs, const Pour &rhs) {
    return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;
}

std::vector<Pour> find_next_possible(const Pour &p, const Pour &full) {
    std::vector<Pour> ans;
    if (p.a && p.a <= (full.b - p.b)) { // a->b  empty a
        ans.push_back(Pour(0, p.a + p.b, p.c, p.incr + p.a));
    }
    if (p.a && p.a > (full.b - p.b)) { // a->b full b
        ans.push_back(Pour(p.a - (full.b - p.b), full.b, p.c, p.incr + full.b - p.b));
    }
    if (p.a && p.a <= (full.c - p.c)) {// a->c empty a
        ans.push_back(Pour(0, p.b, p.a + p.c, p.incr + p.a));
    }
    if (p.a && p.a > (full.c - p.c)) { // a->c full c
        ans.push_back(Pour(p.a - (full.c - p.c), p.b, full.c, p.incr + full.c - p.c));
    }
    if (p.b && p.b <= (full.c - p.c)) { // b->c empty b
        ans.push_back(Pour(p.a, 0, p.b + p.c, p.incr + p.b));
    }
    if (p.b && p.b > (full.c - p.c)) { // b->c full c
        ans.push_back(Pour(p.a, p.b - (full.c - p.c), full.c, p.incr + full.c - p.c));
    }
    if (p.c && p.c <= (full.a - p.a)) { // c->a empty c
        ans.push_back(Pour(p.a + p.c, p.b, 0, p.incr + p.c));
    }
    if (p.c && p.c > (full.a - p.a)) {// c->a full a
        ans.push_back(Pour(full.a, p.b, p.c - full.a + p.a, p.incr + full.a - p.a));
    }
    if (p.c && p.c <= (full.b - p.b)) { // c->b empty c
        ans.push_back(Pour(p.a, p.b + p.c, 0, p.incr + p.c));
    }
    if (p.c && p.c > (full.b - p.b)) { // c->b full b
        ans.push_back(Pour(p.a, full.b, p.c - (full.b - p.b), p.incr + full.b - p.b));
    }
    if (p.b && p.b <= (full.a - p.a)) {  // b->a empty b
        ans.push_back(Pour(p.a + p.b, 0, p.c, p.incr + p.b));
    }
    if (p.b && p.b > (full.a - p.a)) { // b->a full a
        ans.push_back(Pour(full.a, p.b - (full.a - p.a), p.c, p.incr + full.a - p.a));
    }
    return ans;
}

int decode_pour_status(const Pour &p) {
    int idx = 0;
    (p.a) && (idx += p.a * 200 * 200);
    (p.b) && (idx += p.b * 200);
    (p.c) && (idx += p.c * 1);
    return idx;
}

bool is_finish(const Pour &p, int d) {
    return (p.a == d || p.b == d || p.c == d);
}

int diff(const Pour &p, int d) {
    int c = 0x3f3f3f;
    if (p.a <= d) c = d - p.a;
    if (p.b <= d && (d - p.b < c)) c = d - p.b;
    if (p.c <= d && (d - p.c < c)) c = d - p.c;
    return c;
}

int get_close_liter(const Pour &p, int d) {
    int c = 0x3f3f3f, liter = 0;
    if (p.a <= d) c = d - p.a, liter = p.a;
    if (p.b <= d && (d - p.b < c)) c = d - p.b, liter = p.b;
    if (p.c <= d && (d - p.c < c)) liter = p.c;
    return liter;
}

bool is_more_close(const Pour &p1, const Pour &p2, int d) {
    int df1 = diff(p1, d), df2 = diff(p2, d);
    return (df1 < df2 || (df1 == df2 && p1.incr < p2.incr));
}

std::set<int> lookup;

void init_lookup_table() {
    lookup.clear();
}

bool is_visit(const Pour &p) {
    return lookup.count(decode_pour_status(p)) > 0;

}

void set_visit(const Pour &p) {
    if (!lookup.count(decode_pour_status(p))) {
        lookup.insert(decode_pour_status(p));
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init_lookup_table();
        Pour start, full, ans;
        int d;
        std::priority_queue<Pour> queue;
        scanf("%d%d%d", &full.a, &full.b, &full.c);
        scanf("%d", &d);
        start.c = full.c;
        ans = start;
        start.incr = 0;
        queue.push(start);
        set_visit(start);
        while (!queue.empty()) {
            Pour cur = queue.top();
            queue.pop();
            if (is_more_close(cur, ans, d)) {
                ans = cur;
            }
            std::vector<Pour> next = find_next_possible(cur, full);
            size_t size = next.size();
            for (int i = 0; i < size; ++i) {
                if (!is_visit(next[i])) {
                    queue.push(next[i]);
                    set_visit(next[i]);
                }
            }
        }
        printf("%d %d\n", ans.incr, get_close_liter(ans, d));
    }
    return 0;
}