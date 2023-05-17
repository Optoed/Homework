#define _CRT_SECURE_NO_WARNINGS

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define x first
#define y second

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <array>
#include <numeric>
#include <set>
#include <cassert>
#ifndef _DEBUG
#include <bits/stdc++.h>
#endif

using namespace std;

typedef pair<int, int> pt;
typedef long long li;

const int N = 35;

int n;
string s;

bool read() {
    static char buf[N];
    if (scanf("%s", buf) != 1)
        return false;
    s = buf;
    n = s.size();
    return true;
}

void solve() {
    vector<int> cur(n);
    iota(cur.begin(), cur.end(), 0);
    static char buf[5];
    forn(_, 5) {
        int cnt = 0;
        int pos;
        scanf("%s%d", buf, &pos);
        --pos;
        for (int x : cur)
            cnt += s[(x + pos) % n] == '1';
        char sv = cnt > int(cur.size()) - cnt ? '1' : '0';
        vector<int> nw;
        for (int x : cur) if (s[(x + pos) % n] == sv)
            nw.push_back(x);
        cur = nw;
        printf("%c\n", sv);
        fflush(stdout);
    }
    assert(cur.size() > 1);
    int res;
    scanf("%s%d", buf, &res);
    assert(count(cur.begin(), cur.end(), res));
    for (int x : cur) if (x != res) {
        printf("%d\n", x);
        fflush(stdout);
        return;
    }
}

int main() {
#ifdef _DEBUG
    //freopen("input.txt", "r", stdin);
#endif
    if (read()) {
        solve();
    }
}