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

const int N = 40 * 1000 + 13;
const int LIM = 1e6;

int n;
long long m;
int a[N];

bool read() {
    if (scanf("%d%lld", &n, &m) != 2)
        return false;
    forn(i, n)
        scanf("%d", &a[i]);
    return true;
}

void solve() {
    vector<char> prime(N, true);
    vector<int> prs;
    for (int i = 2; i < N; ++i) {
        if (!prime[i]) continue;
        prs.push_back(i);
        for (li j = i * li(i); j < N; j += i) {
            prime[j] = false;
        }
    }
    vector<int> pr;
    forn(i, n) {
        for (int j = 0; j < int(prs.size()) && prs[j] * prs[j] <= a[i]; ++j) if (a[i] % prs[j] == 0) {
            pr.push_back(prs[j]);
            while (a[i] % prs[j] == 0) a[i] /= prs[j];
        }
        if (a[i] > 1) pr.push_back(a[i]);
    }
    sort(pr.begin(), pr.end());
    pr.resize(unique(pr.begin(), pr.end()) - pr.begin());

    vector<char> bad(LIM);
    for (int x : pr) {
        int r = m % x;
        for (int i = r; i < LIM; i += x) bad[i] = true;
    }

    forn(i, LIM) if (!bad[i]) {
        printf("%lld\n", m - i);
        return;
    }
    assert(false);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while (read()) {
        solve();
    }
}