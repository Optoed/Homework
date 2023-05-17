#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

struct point{
	int x, y;
};

point operator -(const point &a, const point &b){
	return {a.x - b.x, a.y - b.y};
}

long long cross(const point &a, const point &b){
	return a.x * 1ll * b.y - a.y * 1ll * b.x;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<point> a(n);
	forn(i, n) scanf("%d%d", &a[i].x, &a[i].y);
	int m;
	scanf("%d", &m);
	vector<array<int, 3>> b(m);
	forn(i, m) forn(j, 3){
		scanf("%d", &b[i][j]);
		--b[i][j];
	}
	
	if ((3 * m + 4) % 2 != 0 || n - (3 * m + 4) / 2 + m != 1){
		puts("No");
		return 0;
	}
	
	long long ar = 0;
	forn(i, m){
		long long cur = abs(cross(a[b[i][0]] - a[b[i][1]], a[b[i][2]] - a[b[i][1]]));
		if (cur == 0){
			puts("No");
			return 0;
		}
		ar += cur;
	}
	
	if (ar != a[2].x * 2ll * a[2].y){
		puts("No");
		return 0;
	}
	
	vector<map<int, int>> g(n);
	forn(i, m) forn(j, 3) forn(k, 3) if (j != k)
		++g[b[i][j]][b[i][k]];
	forn(i, n){
		if (i < 4){
			++g[i][(i + 1) % 4];
			++g[i][(i + 3) % 4];
		}
		for (auto it : g[i]) if (it.second != 2){
			puts("No");
			return 0;
		}
	}
	
	puts("Yes");
}