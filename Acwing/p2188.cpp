/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m, S, T, d[maxn], cur[maxn];

struct edge{
    int eid;
    ll to, f, lc;
    int nid, rid;
};
vector<edge> edges[maxn];

void AddEdge(int eid, int fm, int to, int lc, int uc){
    int fmrid = edges[to].size(), torid = edges[fm].size();
    edges[fm].push_back({eid * 2, to, uc - lc, lc, torid, fmrid});
    edges[to].push_back({eid * 2 + 1, fm, 0, lc, fmrid, torid});    
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

int etot = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<int> tot(n + 1, 0);
    for (int i = 1; i <= m; i++){
        int fm, to, lc, uc;
        cin >> fm >> to >> lc >> uc;
        AddEdge(etot++, fm, to, lc, uc);
        tot[fm] += lc, tot[to] -= lc;
    }

    S = 0, T = n + 1;
    for (int i = 1; i <= n; i++){
        if(tot[i] > 0){
            AddEdge(etot++, i, T, 0, tot[i]);
        }
        else if(tot[i] < 0)
            AddEdge(etot++, S, i, 0, -tot[i]);
    }

    int ans = dinic(), flag = 1;
    for (auto &iter : edges[S]){
        int nto = iter.to, nf = iter.f;
        if(nf != 0){
            flag = 0;
        }
    }

    vector<pii> ans_vec;
    if(flag){
        cout << "YES" << "\n";
        for (int i = 1; i <= n; i++){
            for(auto &iter : edges[i]){
                int nto = iter.to, nf = iter.f, nid = iter.eid, nrid = iter.rid;
                if(nto >= 1 && nto <= n && nid % 2 == 0)
                    ans_vec.push_back(make_pair(nid, edges[nto][nrid].f + iter.lc));
            }
        }
        sort(ans_vec.begin(), ans_vec.end());
        for (auto &iter : ans_vec){
            cout << iter.second << "\n";
        }
    }
    else{
        cout << "NO" << "\n";
    }
}