/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e4 + 10;
const int inf = 0x3f3f3f3f;

#define fa(x) ((x)>>1)
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)

int n, dis[maxn], w[maxn], res[maxn], lazy[maxn], maxi_num = 0;

void bfs(){
    queue<int> q;
    dis[1] = 0, q.push(1);
    while(!q.empty()){
        int now = q.front();
        dis[now] = dis[fa(now)] + w[now];
        if(lson(now) < maxi_num){
            q.push(lson(now));
        }
        if(rson(now) < maxi_num){
            q.push(rson(now));
        }
        q.pop();
    }
}

void dfs(int now, int fm){
    if(now >= maxi_num) return;
    dfs(lson(now), now);
    dfs(rson(now), now);
    if(now < (1 << n)){
        res[now] = min(res[lson(now)], res[rson(now)]);
    }
}

int ans = 0;
void bfs2(int now){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        ans += res[now];
        res[lson(now)] -= lazy[now], res[rson(now)] -= lazy[now];
        if(lson(now) < maxi_num){
            q.push(lson(now));
        }
        if(rson(now) < maxi_num){
            q.push(rson(now));
        }
        q.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    maxi_num = (1 << (n + 1));
    for (int i = 2; i < maxi_num; i++){
        cin >> w[i];
    }
    bfs();
    int maxi = -inf;
    for (int i = (1 << n); i < maxi_num; i++){
        maxi = max(maxi, dis[i]);
    }
    for (int i = (1 << n); i < maxi_num; i++){
        res[i] = maxi - dis[i];
    }
    dfs(1, -1);
    memcpy(lazy, res, sizeof(res));
    bfs2(1);
    cout << ans << endl;
    return 0;
}