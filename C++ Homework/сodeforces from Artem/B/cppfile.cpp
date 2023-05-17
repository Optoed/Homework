#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#ifndef _DEBUG
#include <bits/stdc++.h>
#endif

using namespace std;

int n, x, y;

bool read() {
    if (scanf("%d%d%d", &n, &x, &y) != 3)
        return false;
    return true;
}

void solve() {
    x = abs(x), y = abs(y);
    printf("%lld\n", (n + x) * 1ll * (n + y) - x * 1ll * y);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}