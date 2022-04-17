/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-12
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
const long double eps = 1e-8;
int t, n, m, S, T, d[maxn], cur[maxn];
long double bond;

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

struct ice{
    int x, y, n, m;
};
vector<ice> ices;
ll SquareDist(ice i1, ice i2){
    long double ret = 0;
    return ret = (i1.x - i2.x) * (i1.x - i2.x) + (i1.y - i2.y) * (i1.y - i2.y);
}

int trans_inno(int off){
    return off * 2;
}

int trans_outno(int off){
    return off * 2 + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> bond;
        vector<ice> ices(n + 1);
        int anti = 0, tot = 0;
        for(int i = 1; i <= n; i++){
            int nx, ny, nn, nm;
            cin >> nx >> ny >> nn >> nm;
            ices[i] = {nx, ny, nn, nm}, anti += nn;
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(i != j){
                    if(SquareDist(ices[i], ices[j]) - bond * bond <= eps){
                        AddEdge(trans_outno(i), trans_inno(j), inf);
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++){
            AddEdge(0, trans_inno(i), ices[i].n);
            AddEdge(trans_inno(i), trans_outno(i), ices[i].m);
        }

        vector<edge> res[maxn];
        for (int i = 0; i <= trans_outno(n); i++){
            res[i] = edges[i];
        }

        S = 0;
        for (int i = 1; i <= n; i++){
            T = trans_inno(i);
            int now_ans = dinic();
            if(now_ans == anti){
                tot++;
                cout << i - 1 << " ";
            }
            for (int j = 0; j <= trans_outno(n); j++){
                edges[j] = res[j];
            }
        }
        if(tot == 0){
            cout << -1;
        }
        cout << endl;

        for (int i = 0; i <= trans_outno(n); i++){
            edges[i].clear();
        }
    }
    return 0;
}