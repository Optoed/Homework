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

mt19937 rnd(42);

const int MOD = int(1e9) + 7;

const int AL = 26;
const int N = 100 * 1000 + 13;

pt a[AL];
string s, t;

bool read() {
    int n;
    if (scanf("%d", &n) != 1)
        return false;
    forn(i, AL)
        a[i] = { -1, -1 };
    forn(i, n) {
        char A, B, C;
        scanf(" %c->%c%c", &A, &B, &C);
        a[A - 'a'] = { B - 'a', C - 'a' };
    }
    static char buf[N];
    scanf("%s", buf);
    s = buf;
    scanf("%s", buf);
    t = buf;
    return true;
}

void solve() {
    vector<int> cur;
    forn(i, s.size()) cur.push_back(s[int(s.size()) - i - 1] - 'a');
    int j = 0;
    while (!cur.empty() && j < int(t.size())) {
        bool ok = true;
        while (cur.back() != t[j] - 'a') {
            int x = cur.back();
            if (a[x].x == -1) {
                ok = false;
                break;
            }
            cur.back() = a[x].y;
            cur.push_back(a[x].x);
        }
        if (!ok) {
            puts("NO");
            return;
        }
        ++j;
        cur.pop_back();
    }
    puts(cur.empty() && j == int(t.size()) ? "YES" : "NO");
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}