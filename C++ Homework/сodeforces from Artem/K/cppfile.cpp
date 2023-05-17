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

int n, m;
int can[7];

bool read() {
    if (scanf("%d%d", &n, &m) != 2)
        return false;
    forn(i, 7)
        scanf("%d", &can[i]);
    return true;
}

vector<int> opts[] = {
    {},
    {
        (1 << 0) | (1 << 1) | (1 << 2) | (1 << 8),
        (1 << 0) | (1 << 8) | (1 << 16) | (1 << 17),
        (1 << 2) | (1 << 8) | (1 << 9) | (1 << 10),
        (1 << 0) | (1 << 1) | (1 << 9) | (1 << 17)
    },
    {
        (1 << 0) | (1 << 1) | (1 << 2) | (1 << 10),
        (1 << 0) | (1 << 1) | (1 << 8) | (1 << 16),
        (1 << 0) | (1 << 8) | (1 << 9) | (1 << 10),
        (1 << 1) | (1 << 9) | (1 << 16) | (1 << 17)
    },
    {
        (1 << 0) | (1 << 1) | (1 << 8) | (1 << 9)
    },
    {
        (1 << 0) | (1 << 1) | (1 << 9) | (1 << 10),
        (1 << 1) | (1 << 8) | (1 << 9) | (1 << 16)
    },
    {
        (1 << 0) | (1 << 1) | (1 << 2) | (1 << 9),
        (1 << 0) | (1 << 8) | (1 << 9) | (1 << 16),
        (1 << 1) | (1 << 9) | (1 << 17) | (1 << 8),
        (1 << 1) | (1 << 8) | (1 << 9) | (1 << 10)
    },
    {
        (1 << 1) | (1 << 2) | (1 << 8) | (1 << 9),
        (1 << 0) | (1 << 8) | (1 << 9) | (1 << 17)
    }
};

vector<int> wd[] = {
    {},
    {3, 2, 3, 2},
    {3, 2, 3, 2},
    {2},
    {3, 2},
    {3, 2, 2, 3},
    {3, 2}
};

int dp[2][1 << 17];

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

void solve() {
    /*forn(t, 7) {
        cerr << t << ":\n";
        for (auto it : opts[t]) {
            for (int i = 2; i >= 0; --i) {
                forn(j, 8)
                    cerr << ((it >> (i * 8 + j)) & 1 ? '#' : '.');
                cerr << endl;
            }
            cerr << endl;
        }
    }*/
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    forn(ii, n * 8) {
        int i = ii & 1;
        int ni = i ^ 1;
        memset(dp[ni], 0, sizeof(dp[ni]));
        int pos = ii % 8;
        int need = pos < m;
        forn(mask, 1 << 17) if (dp[i][mask]) {
            forn(j, 7) if (can[j]) {
                forn(k, opts[j].size()) if (wd[j][k] + pos <= 8) {
                    if ((mask & opts[j][k]) != 0) continue;
                    int nmask = mask | opts[j][k];
                    if ((nmask & 1) != need) continue;
                    nmask >>= 1;
                    dp[ni][nmask] = add(dp[ni][nmask], dp[i][mask]);
                }
            }
            if ((mask & 1) == need) {
                dp[ni][mask >> 1] = add(dp[ni][mask >> 1], dp[i][mask]);
            }
        }
    }
    printf("%d\n", dp[(n * 8) & 1][0]);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}