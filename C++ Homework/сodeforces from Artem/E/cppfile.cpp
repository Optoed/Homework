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
#ifndef _DEBUG
#include <bits/stdc++.h>
#endif

using namespace std;

typedef pair<int, int> pt;
typedef long long li;

const int N = 100 * 1000 + 13;

int n, fx, fy;
pt a[N];

bool read() {
    if (scanf("%d%d%d", &fx, &fy, &n) != 3)
        return false;
    forn(i, n)
        scanf("%d%d", &a[i].x, &a[i].y);
    return true;
}

pt b[N];

void solve() {
    a[n++] = { fx, fy };
    sort(a, a + n);
    forn(i, n) b[i] = { a[i].y, a[i].x };
    sort(b, b + n);
    map<pt, int> d;
    queue<pt> q;
    q.push({ 0, 0 });
    d[{0, 0}] = 0;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        //cerr << x << " " << y << " " << d[{x, y}] << endl;
        if (d[{x, y}] == 11) continue;
        if (x == fx && y == fy) {
            printf("%d\n", d[{x, y}]);
            return;
        }
        {
            auto it = lower_bound(a, a + n, make_pair(x, y));
            if (it != a + n && it->x == x) {
                if (it->x == fx && it->y == fy) {
                    printf("%d\n", d[{x, y}]);
                    return;
                }
                int ds = it->y - y;
                int nx = x, ny = it->y - (ds + 1) / 2;
                auto jt = d.find({ nx, ny });
                if (!d.count({ nx, ny })) {
                    d[{nx, ny}] = d[{x, y}] + 1;
                    q.push({ nx, ny });
                }
            }
            if (it != a) {
                --it;
                if (it->x == x) {
                    if (it->x == fx && it->y == fy) {
                        printf("%d\n", d[{x, y}]);
                        return;
                    }
                    int ds = y - it->y;
                    int nx = x, ny = it->y + (ds + 1) / 2;
                    auto jt = d.find({ nx, ny });
                    if (!d.count({ nx, ny })) {
                        d[{nx, ny}] = d[{x, y}] + 1;
                        q.push({ nx, ny });
                    }
                }
            }
        }
        {
            auto it = lower_bound(b, b + n, make_pair(y, x));
            if (it != b + n && it->x == y) {
                if (it->y == fx && it->x == fy) {
                    printf("%d\n", d[{x, y}]);
                    return;
                }
                int ds = it->y - x;
                int nx = it->y - (ds + 1) / 2, ny = y;
                auto jt = d.find({ nx, ny });
                if (!d.count({ nx, ny })) {
                    d[{nx, ny}] = d[{x, y}] + 1;
                    q.push({ nx, ny });
                }
            }
            if (it != b) {
                --it;
                if (it->x == y) {
                    if (it->y == fx && it->x == fy) {
                        printf("%d\n", d[{x, y}]);
                        return;
                    }
                    int ds = x - it->y;
                    int nx = it->y + (ds + 1) / 2, ny = y;
                    auto jt = d.find({ nx, ny });
                    if (!d.count({ nx, ny })) {
                        d[{nx, ny}] = d[{x, y}] + 1;
                        q.push({ nx, ny });
                    }
                }
            }
        }
    }
    puts(":(");
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}