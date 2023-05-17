#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>
#ifndef _DEBUG
#include <bits/stdc++.h>
#endif

using namespace std;

int n;

bool read() {
    if (scanf("%d", &n) != 1)
        return false;
    return true;
}

void solve() {
    vector<int> sv;
    for (int i = 1; i * i < n; ++i)
        sv.push_back(i * i);
    int ans = 0;
    for (int i = 1; i * i < n; ++i) if (n - i * i < i * i)
        ans += binary_search(sv.begin(), sv.end(), n - i * i);
    printf("%d\n", ans);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}