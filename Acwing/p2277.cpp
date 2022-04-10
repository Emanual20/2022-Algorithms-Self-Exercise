/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;
const int inf = 0x3f3f3f3f;
int n, m, k, S, T, d[maxn], cur[maxn];

struct preedge{
    ll to, w;
};
vector<preedge> preedges[maxn];

struct edge{
    ll to, f;
    int nid, rid;
};
vector<edge> edges[maxn];

void AddEdge(int fm, int to, int c){
    int fmrid = edges[to].size(), torid = edges[fm].size();
    edges[fm].push_back({to, c, torid, fmrid});
    edges[to].push_back({fm, 0, fmrid, torid});    
}

bool dilaminate(){
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S), d[S] = 0, cur[S] = 0;
    while(!q.empty()){
        int now = q.front();
        for(auto &iter : edges[now]){
            int nto = iter.to, nf = iter.f;
            if(d[nto] == -1 && nf){
                d[nto] = d[now] + 1, cur[nto] = 0;
                q.push(nto);
                if(nto == T) return true;
            }
        }
        q.pop();
    }
    return false;
}

ll FindAugmentation(int now, ll limit){
    if(now == T) return limit;
    ll flow = 0;
    for (int i = cur[now]; i < edges[now].size() && flow < limit; i++){
        auto iter = edges[now][i];
        ll nto = iter.to, nf = iter.f, nnid = iter.nid, nrid = iter.rid;
        cur[now] = i;
        if(d[nto] == d[now] + 1 && nf){
            ll tmp = FindAugmentation(nto, min(nf, limit - flow));
            if(!tmp) d[nto] = -1;
            edges[now][nnid].f -= tmp, edges[nto][nrid].f += tmp;
            flow += tmp;
        }
    }
    return flow;
}

ll dinic(){
    ll ret = 0;
    while(dilaminate()){
        ll tmp = 0;
        while(tmp = FindAugmentation(S, inf))
            ret += tmp;
    }
    return ret;
}

bool check(int para){
    for (int i = 1; i <= n; i++){
        edges[i].clear();
    }

    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++){
        for(auto &iter : preedges[i]){
            int nto = iter.to, nw = iter.w;
            if(nw <= para){
                mp[make_pair(i, nto)]++;
            }
        }
    }

    for(auto &iter : mp){
        int fm = iter.first.first, to = iter.first.second, nf = iter.second;
        AddEdge(fm, to, nf);
    }

    S = 1, T = n;
    return dinic() >= k;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        preedges[fm].push_back({to, w}), preedges[to].push_back({fm, w});
    }

    int left = 1, right = 1e6;
    while(left < right){
        int mid = left + right >> 1;
        if(check(mid)){
            right = mid;
        }
        else
            left = mid + 1;
    }

    cout << right << endl;
    return 0;
}