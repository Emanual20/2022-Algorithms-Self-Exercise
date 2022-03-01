/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
struct edge{
    int to;
};
vector<edge> edges[maxn];

int n, m, MOD;
int TimeStamp = 0, dfn[maxn], low[maxn], vis[maxn];
int scc_id[maxn], scc_sz[maxn], scc_cnt = 0;
stack<int> s;

void tarjan_scc(int now){
    dfn[now] = low[now] = ++TimeStamp;
    s.push(now), vis[now] = 1;

    for(auto &iter : edges[now]){
        int nto = iter.to;
        if(!dfn[nto]){
            tarjan_scc(nto);
            low[now] = min(low[now], low[nto]);
        }
        else if(vis[nto]){
            low[now] = min(low[now], dfn[nto]);
        }
    }

    if(dfn[now] == low[now]){
        scc_cnt++;
        int x;
        do{
            x = s.top();
            s.pop(), vis[x] = 0, scc_id[x] = scc_cnt, scc_sz[scc_cnt]++;
        } while (x != now);
    }
}

void Calc_SCC(){
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    memset(scc_id, 0, sizeof(scc_id));
    memset(scc_sz, 0, sizeof(scc_sz));
    while(!s.empty()) s.pop();
    TimeStamp = 0, scc_cnt = 0;
    for (int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan_scc(i);
        }
    }
}

vector<edge> new_edges[maxn];
set<ll> new_edge_vis;
ll hash_edge(int fm, int to){
    ll ret = 1ll * scc_cnt * fm + to;
    return ret;
}
void build_SCCDAG(){
    for (int i = 1; i <= n; i++){
        for(auto &iter : edges[i]){
            int nfm = i, nto = iter.to;
            if(scc_id[nfm] != scc_id[nto]){
                ll hash_code = hash_edge(scc_id[nfm], scc_id[nto]);
                if(!new_edge_vis.count(hash_code))
                    new_edges[scc_id[nfm]].push_back({scc_id[nto]}), new_edge_vis.insert(hash_code);
            }
        }
    }
}

ll ans[maxn], ways[maxn], ind[maxn];
void bfs(){
    memset(ind, 0, sizeof(ind));
    memset(ans, 0, sizeof(ans));
    memset(ways, 0, sizeof(ways));
    for (int i = 1; i <= scc_cnt; i++){
        for(auto &iter : new_edges[i]){
            ind[iter.to]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= scc_cnt; i++){
        if(!ind[i])
            q.push(i), ans[i] = scc_sz[i], ways[i] = 1;
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : new_edges[now]){
            int nto = iter.to;
            if(ans[now] + scc_sz[nto] > ans[nto]){
                ans[nto] = ans[now] + scc_sz[nto];
                ways[nto] = ways[now];
            }
            else if(ans[now] + scc_sz[nto] == ans[nto]){
                ways[nto] += ways[now], ways[nto] %= MOD;
            }
            ind[iter.to]--;
            if(!ind[iter.to]){
                q.push(iter.to);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> MOD;
    for (int i = 1; i <= m; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back({to});
    }

    Calc_SCC();
    build_SCCDAG();
    bfs();

    ll max_ans = -1, max_ways = 0;
    for (int i = 1; i <= scc_cnt; i++){
        if(ans[i] > max_ans){
            max_ans = ans[i], max_ways = ways[i];
        }
        else if(ans[i] == max_ans){
            max_ways += ways[i], max_ways %= MOD;
        }
    }
    cout << max_ans << endl;
    cout << max_ways << endl;
    return 0;
}