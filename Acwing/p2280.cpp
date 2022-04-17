/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

const int inf = 0x3f3f3f3f;
int n, m, k, S, T, d[maxn], cur[maxn];

struct edge{
    ll to, f;
    int nid, rid;
};

vector<edge> edges[maxn];

void AddEdge(int fm, int to, int trac, int revc){
    int fmrid = edges[to].size(), torid = edges[fm].size();
    edges[fm].push_back({to, trac, torid, fmrid});
    edges[to].push_back({fm, revc, fmrid, torid});    
}

void RemoveLastEdge(int fm, int to){
    edges[fm].pop_back(), edges[to].pop_back();
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

vector<int> items[maxn];
int p[maxn];

ll solve(int x){
    for (int i = 0; i <= n + 1; i++){
        edges[i].clear();
    }

    for (int i = 1; i <= n; i++){
        if(p[i] != -1){
            if((p[i] >> x) & 1)
                AddEdge(i, T, inf, 0);
            else
                AddEdge(S, i, inf, 0);
        }
    }

    for (int i = 1; i <= n; i++){
        for(auto &iter : items[i]){
            AddEdge(i, iter, 1, 1);
        }
    }

    return dinic();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    S = 0, T = n + 1;
    for (int i = 1; i <= m; i++){
        int nfm, nto;
        cin >> nfm >> nto;
        items[nfm].push_back(nto);
    }

    cin >> k;
    memset(p, 0xff, sizeof(p));
    for (int i = 1; i <= k; i++){
        int nkey, nvalue;
        cin >> nkey >> nvalue;
        p[nkey] = nvalue;
    }

    ll ans = 0;
    for (int i = 0; i <= 30; i++){
        ans += solve(i) * pow(2, i);
    }
    cout << ans << endl;
    return 0;
}