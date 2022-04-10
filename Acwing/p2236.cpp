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
const int maxn = 500 + 10;

const int inf = 0x3f3f3f3f;
int n, m, S, T, d[maxn], cur[maxn];

struct edge{
    ll eid, to, f;
    int nid, rid;
};
vector<edge> edges[maxn];

void AddEdge(int eid, int fm, int to, int c){
    int fmrid = edges[to].size(), torid = edges[fm].size();
    edges[fm].push_back({eid * 2, to, c, torid, fmrid});
    edges[to].push_back({eid * 2 + 1, fm, 0, fmrid, torid});    
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

int visfroms[maxn], visfromt[maxn];

void bfs1(int now){
    queue<int> q;
    q.push(now);
    while(!q.empty()){
        int now = q.front();
        visfroms[now] = 1;
        for(auto &iter : edges[now]){
            int nto = iter.to, nf = iter.f, neid = iter.eid;
            if(nf > 0 && neid % 2 == 0 && !visfroms[nto]){
                q.push(nto);
            }
        }
        q.pop();
    }
}

vector<int> ReverseEdges[maxn];
void BuildReverseGraph(){
    for (int i = 0; i < n; i++){
        for(auto &iter : edges[i]){
            int nto = iter.to, nf = iter.f, neid = iter.eid;
            if(nf > 0 && neid % 2 == 0){
                ReverseEdges[nto].push_back(i);
            }
        }
    }
}

void bfs2(int now){
    queue<int> q;
    q.push(now);
    while(!q.empty()){
        int now = q.front();
        visfromt[now] = 1;
        for(auto &iter : ReverseEdges[now]){
            if(!visfromt[iter]){
                q.push(iter);
            }
        }
        q.pop();
    }
}

int tot = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int fm, to, c;
        cin >> fm >> to >> c;
        AddEdge(tot++, fm, to, c);
    }
    S = 0, T = n - 1;
    dinic();
    bfs1(S);
    BuildReverseGraph();
    bfs2(T);
    int ans = 0;
    for (int i = 0; i < n; i++){
        for(auto &iter : edges[i]){
            int nfm = i, nto = iter.to, nf = iter.f, neid = iter.eid;
            if(visfroms[nfm] && visfromt[nto] && !nf && neid % 2 == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}