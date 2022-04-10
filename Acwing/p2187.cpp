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

typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m, k, S, T, d[maxn], cur[maxn];

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

vector<int> trips_c;
vector<int> trips[20];

int dayoff2node(int day, int off){
    return (day + 1) * (n + 2) + off;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    vector<int> trips_now(m + 10, 0);
    
    for (int i = 0; i < m; i++){
        int c, r, x;
        cin >> c >> r;
        trips_c.push_back(c);
        for (int j = 0; j < r; j++){
            cin >> x;
            trips[i].push_back(x);
        }
    }

    S = 0, T = 1;
    AddEdge(S, dayoff2node(0, 0), inf);
    int res = 0;
    for (int day = 1; day <= 1000; day++){
        for (int i = 0; i <= n + 1; i++){
            AddEdge(dayoff2node(day - 1, i), dayoff2node(day, i), inf);
        }
        for (int i = 0; i < m; i++){
            int nfm = trips[i][trips_now[i]];
            trips_now[i] = (trips_now[i] + 1) % trips[i].size();
            int nto = trips[i][trips_now[i]], nf = trips_c[i];
            nfm = (nfm == -1 ? n + 1 : nfm), nto = (nto == -1 ? n + 1 : nto);
            AddEdge(dayoff2node(day - 1, nfm), dayoff2node(day, nto), nf);
        }
        AddEdge(dayoff2node(day, n + 1), T, inf);
        
        res += dinic();
        if(res >= k){
            cout << day << endl;
            return 0;
        }

        RemoveLastEdge(dayoff2node(day, n + 1), T);
    }

    cout << 0 << endl;
    return 0;
}