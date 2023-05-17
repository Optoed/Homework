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
#include <random>
#include <cassert>

#ifndef _DEBUG
#include <bits/stdc++.h>
#endif

using namespace std;

typedef pair<int, int> pt;
typedef long long li;
typedef long double ld;

mt19937 rnd(42);

const ld EPS = 1e-8;
const ld PI = acosl(-1);

const int N = 100 + 7;

template<class A, class B>
ostream& operator <<(ostream & out, const pair<A, B> & a) {
    return out << "(" << a.x << ", " << a.y << ")";
}

int n;
pt a[N];
int m;
array<int, 3> b[N];

bool read() {
    if (scanf("%d", &n) != 1)
        return false;
    forn(i, n)
        scanf("%d%d", &a[i].x, &a[i].y);
    scanf("%d", &m);
    forn(i, m) forn(j, 3) {
        scanf("%d", &b[i][j]);
        --b[i][j];
    }
    return true;
}

ld ang[N];

pt operator -(const pt& a, const pt& b) {
    return { a.x - b.x, a.y - b.y };
}

li dot(const pt& a, const pt& b) {
    return a.x * li(b.x) + a.y * li(b.y);
}

li cross(const pt& a, const pt& b) {
    return a.x * li(b.y) - a.y * li(b.x);
}

ld len(const pt& a) {
    return sqrtl(a.x * li(a.x) + a.y * li(a.y));
}

vector<pt> g[N];

void solve() {
    memset(ang, 0, sizeof(ang));
    li sq = 0;
    forn(i, m) {
        ld sum = 0;
        forn(j, 3) {
            pt A = a[b[i][j]];
            pt B = a[b[i][(j + 1) % 3]];
            pt C = a[b[i][(j + 2) % 3]];
            if (cross(C - A, B - A) == 0) {
                puts("No");
                return;
            }
            ang[b[i][j]] += acosl(dot(C - A, B - A) / len(C - A) / len(B - A));
            sum += acosl(dot(C - A, B - A) / len(C - A) / len(B - A));
            if (j == 0) sq += abs(cross(C - A, B - A));
        }
        if (sq > 2ll * a[2].x * a[2].y) {
            puts("No");
            return;
        }
    }
    if (sq != 2ll * a[2].x * a[2].y) {
        puts("No");
        return;
    }
    forn(i, 4) if (fabsl(ang[i] - PI / 2) > EPS) {
        puts("No");
        return;
    }
    for (int i = 4; i < n; ++i) if (fabsl(ang[i] - 2 * PI) > EPS) {
        puts("No");
        return;
    }

    forn(i, n) g[i].clear();
    forn(i, m) forn(j, 3) {
        g[b[i][j]].push_back(a[b[i][(j + 1) % 3]]);
        g[b[i][j]].push_back(a[b[i][(j + 2) % 3]]);
    }

    forn(i, n) {
        map<pt, int> cnt;
        if (i < 4) ++cnt[a[(i + 1) % 4]], ++cnt[a[(i + 3) % 4]];
        for (auto it : g[i]) ++cnt[it];
        for (auto it : cnt) if (it.y != 2) {
            puts("No");
            return;
        }
    }

    puts("Yes");
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}