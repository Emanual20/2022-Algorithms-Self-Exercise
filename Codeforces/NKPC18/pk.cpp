/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 2e6 + 5, M = 3e5 + 5, MOD = 998244353;
int n, m;
char s[maxn];
int l[maxn], r[maxn];
string p[maxn];
ll f[maxn];

void dfs2(int x) {
	if (x > m) 
        return;
	if (2 * x <= m){
		l[x] = 2 * x;
		dfs2(2 * x);
	}
	if (2 * x + 1 <= m) {
		r[x] = 2 * x + 1;
		dfs2(2 * x + 1);
	}
}

void dfs(int x) {
	f[x] = 1;
	p[x].push_back(s[x]);
	if (l[x]) {
		dfs(l[x]);
		dfs(r[x]);	
		if (p[l[x]] == p[r[x]]) {
			f[x] = f[x] * f[l[x]] % MOD * f[r[x]] % MOD;
		}	
		else {
			f[x] = 2 * f[x] % MOD * f[l[x]] % MOD * f[r[x]] % MOD;
		}
		if (p[l[x]] < p[r[x]]) swap(p[l[x]], p[r[x]]);
		p[x] += p[l[x]] + p[r[x]];
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> n;
	m = (1 << n) - 1;
	cin >> s + 1;
	dfs2(1);
	dfs(1);
	cout << f[1] % MOD << "\n";

	return 0;
}