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

const int N = 10 * 1000 + 13;

int n, m, k, v;
int x;
string s;

bool read() {
    if (scanf("%d%d%d%d", &n, &m, &k, &v) != 4)
        return false;
    scanf("%d", &x);
    static char buf[N];
    scanf("%s", buf);
    s = buf;
    return true;
}

void solve() {
    int w = s.size();
    long long full = ((k + 1) * 1ll * w);
    int j;
    forn(t, n) {
        for (long long i = (x * 1ll * v) % full, j = 0; j < m; i = (i + 1) % full, ++j) {
            int pos = i % (k + 1);
            if (pos == k)
                printf("%c", '.');
            else if (s[i / (k + 1)] == '0')
                printf("%c", pos == 0 || pos == k - 1 ? '#' : (t == 0 || t == n - 1 ? '#' : '.'));
            else
                printf("%c", pos == k - 1 ? '#' : '.');
        }
        puts("");
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}