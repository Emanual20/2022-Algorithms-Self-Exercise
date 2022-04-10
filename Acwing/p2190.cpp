/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f;
ll n, m, S, T, s, t, d[maxn], cur[maxn];

struct edge{
    ll to, f;
    int nid, rid;
};
vector<edge> edges[maxn];

void AddEdge(int fm, int to, ll c){
    int fmrid = edges[to].size(), torid = edges[fm].size();
    edges[fm].push_back({to, c, torid, fmrid});
    edges[to].push_back({fm, 0, fmrid, torid});    
}

void RemoveLastEdge(int fm, int to){
    edges[fm].pop_back();
    edges[to].pop_back();
}

bool dilaminate(){
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(S), d[S] = 0, cur[S] = 0;
    while(!q.empty()){
        int now = q.front();
        for(auto &iter : edges[now]){
            ll nto = iter.to, nf = iter.f;
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

ll e_tot = 0, anti = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> s >> t;
    vector<ll> ctot(n + 1, 0);
    for (int i = 1; i <= m; i++){
        ll fm, to, lc, uc;
        cin >> fm >> to >> lc >> uc;
        AddEdge(fm, to, uc - lc);
        ctot[fm] += lc, ctot[to] -= lc;
    }

    S = 0, T = n + 1;
    for (int i = 1; i <= n; i++){
        if(ctot[i] > 0){
            AddEdge(i, T, ctot[i]), anti += ctot[i];
        }
        else if(ctot[i] < 0){
            AddEdge(S, i, -ctot[i]);
        }
    }
    AddEdge(t, s, inf);

    ll ans_1 = dinic();
    if(ans_1 != anti){
        cout << "No Solution" << endl;
    }
    else{
        ll res = edges[s].back().f;
        RemoveLastEdge(t, s);
        S = t, T = s;
        ll ans_2 = dinic();
        cout << res - ans_2 << endl;
    }
    return 0;
}