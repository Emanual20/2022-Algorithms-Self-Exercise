/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500 + 10;
const int inf = 0x3f3f3f3f;
int n, m, a[maxn][maxn], vis[maxn], dist[maxn];
int prim(){
    memset(vis, 0, sizeof(vis)), memset(dist, 0x3f, sizeof(dist));
    vis[1] = 1, dist[1] = 0;
    for (int i = 1; i <= n; i++){
        dist[i] = min(dist[i], a[1][i]);
    }

    int ret = 0;
    for (int i = 1; i < n; i++){
        int index = -1, now = inf;
        for (int j = 1; j <= n; j++){
            if(!vis[j] && dist[j] < now){
                index = j, now = dist[j];
            }
        }
        if(index == -1){
            return -1;
        }
        vis[index] = 1, ret = ret + now;
        for (int j = 1; j <= n; j++){
            if(!vis[j]){
                dist[j] = min(dist[j], a[index][j]);
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    memset(a, 0x3f, sizeof(a));
    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        a[fm][to] = a[to][fm] = min(a[fm][to], w);
    }

    int ret = prim();
    if(ret == -1){
        cout << "impossible" << endl;
    }
    else{
        cout << ret << endl;
    }
    return 0;
}