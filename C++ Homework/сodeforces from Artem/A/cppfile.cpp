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

int a, b, c;
int d, e, f;

bool read() {
    if (scanf("%d%d%d", &a, &b, &c) != 3)
        return false;
    scanf("%d%d%d", &d, &e, &f);
    --a, --b, --c;
    --d, --e, --f;
    return true;
}

void solve() {
    queue<array<int, 3>> q;
    map<array<int, 3>, int> used;
    q.push({ a, b, c });
    used[{a, b, c}] = 0;
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        int ds = used[a];
        if (a == array<int, 3>( { d, e, f })) {
            printf("%d\n", ds);
            return;
        }
        forn(i, 3) forn(j, i) {
            a[i] = (a[i] + 1) % 12, a[j] = (a[j] + 1) % 12;
            if (!used.count(a)) {
                used[a] = ds + 1;
                q.push(a);
            }
            a[i] = (a[i] + 11) % 12, a[j] = (a[j] + 11) % 12;
        }
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