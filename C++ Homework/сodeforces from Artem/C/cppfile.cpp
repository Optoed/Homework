#define _CRT_SECURE_NO_WARNINGS

#define forn(i, n) for (int i = 0; i < int(n); ++i)

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

const int N = 1000 + 7;

int n, m;
int a[N], b[N];

bool read() {
    if (scanf("%d%d", &n, &m) != 2)
        return false;
    forn(i, n)
        scanf("%d", &a[i]);
    forn(i, m)
        scanf("%d", &b[i]);
    return true;
}

int dp[N][N];

void solve() {
    forn(i, n + 1) forn(j, m + 1) dp[i][j] = 1e9;
    dp[0][0] = 0;
    forn(i, n + 1) forn(j, m + 1) {
        if (i < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        if (j < m) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
        if (i < n && j < m) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (a[i] != b[j]));
    }
    printf("%d\n", dp[n][m]);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}