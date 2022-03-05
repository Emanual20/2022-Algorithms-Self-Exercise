/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const int maxv = 1e4 + 10;

struct item{
    int c, w;
};
vector<item> items;

int n, m, v;
int c[maxn], w[maxn], dp[maxv];

int f[maxn], sz[maxn], vis[maxn];
// remember to call dsu_init
void dsu_init(){
    for (int i = 1; i <= n; i++)
        f[i] = i;
}
int find(int k){
    if(f[k] == k)
        return k;
    return f[k] = find(f[k]);
}
void merge(int dst, int src){
    int ds = find(dst), sr = find(src);
    f[sr] = ds;
    if(ds != sr) w[ds] += w[sr], c[ds] += c[sr];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> v;
    dsu_init();
    for (int i = 1; i <= n; i++){
        cin >> c[i] >> w[i];
    }
    for (int i = 1; i <= m; i++){
        int fm, to;
        cin >> fm >> to;
        merge(fm, to);
    }

    for (int i = 1; i <= n; i++){
        if(!vis[find(i)]){
            items.push_back({c[find(i)], w[find(i)]});
            vis[find(i)] = 1;
        }
    }

    memset(dp, 0, sizeof(dp));
    for (auto &iter : items){
        int nc = iter.c, nw = iter.w;
        for (int j = v; j >= nc; j--){
            dp[j] = max(dp[j], dp[j - nc] + nw);
        }
    }
    cout << dp[v] << endl;
    return 0;
}