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

const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

const int N = 28;

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

typedef pair<ld, ld> point;

struct line {
    ld A, B, C;
    line(const point& a, const point& b) {
        A = a.y - b.y;
        B = b.x - a.x;
        C = -A * a.x - B * a.y;
    }
    line() {}
};

point a[N];

ld dist(const point& a, const point& b) {
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld det(const ld& a, const ld& b, const ld& c, const ld& d) {
    return a * d - b * c;
}

bool inter(const line& a, const line& b, point& p) {
    ld D = det(a.A, a.B, b.A, b.B);
    if (fabsl(D) < EPS) return false;
    ld Dx = det(a.C, a.B, b.C, b.B);
    ld Dy = det(a.A, a.C, b.A, b.C);
    p = { -Dx / D, -Dy / D };
    return true;
}

bool on(const point& a, const point& b, const point& c) {
    return fabsl(dist(a, b) + dist(a, c) - dist(b, c)) < EPS;
}

void solve() {
    vector<point> res;
    forn(i, n) a[i] = { cosl(2 * PI * i / n), sinl(2 * PI * i / n) };
    forn(i, n) {
        line l1(a[s[i] - 'A'], a[s[(i + 1) % n] - 'A']);
        forn(j, n) {
            if (i == j || (j + 1) % n == i || (i + 1) % n == j) continue;
            line l2(a[s[j] - 'A'], a[s[(j + 1) % n] - 'A']);
            point p;
            if (inter(l1, l2, p) && on(p, a[s[i] - 'A'], a[s[(i + 1) % n] - 'A']) && on(p, a[s[j] - 'A'], a[s[(j + 1) % n] - 'A'])) {
                bool nw = true;
                for (auto& np : res)
                    nw &= dist(p, np) > EPS;
                if (nw)
                    res.push_back(p);
            }
        }
    }
    printf("%d\n", int(res.size()));
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}