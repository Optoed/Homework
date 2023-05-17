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

const int N = 1500;

int n, s, k, m;
int a[N], b[N];

bool read() {
    if (scanf("%d%d%d%d", &n, &s, &k, &m) != 4)
        return false;
    forn(i, n) {
        int h, m;
        scanf("%d:%d ", &h, &m);
        a[i] = h * 60 + m;
    }
    forn(i, s) {
        int h, m;
        scanf("%d:%d ", &h, &m);
        b[i] = h * 60 + m;
    }
    return true;
}

void solve() {
    vector<int> cnt(1440);
    forn(i, n) for (int j = a[i]; j < 1440; j += k) 
        ++cnt[j];
    int st = 1440;
    forn(i, 1440) if (cnt[i] >= m) {
        st = i;
        break;
    }
    st += 5;
    int ans = 0;
    forn(i, s) ans += b[i] < st;
    if (ans == s)
        puts("NO");
    else
        printf("%d\n", ans + 1);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}