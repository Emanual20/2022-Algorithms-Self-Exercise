/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

struct edge{
    int to;
};
vector<edge> edges[maxn];

int n, m;
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
void build_reverse_SCCDAG(){
    for (int i = 1; i <= n; i++){
        for(auto &iter : edges[i]){
            int nfm = i, nto = iter.to;
            if(scc_id[nfm] != scc_id[nto]){
                new_edges[scc_id[nto]].push_back({scc_id[nfm]});
            }
        }
    }
}

void bfs_reverse_SCCDAG(){
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= scc_cnt; i++){
        if(scc_sz[i] > 1 && !vis[i]){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int now = q.front();
                vis[now] = 1;
                for(auto &iter : new_edges[now]){
                    if(!vis[iter.to]){
                        q.push(iter.to);
                    }
                }
                q.pop();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back({to});
    }

    Calc_SCC();
    build_reverse_SCCDAG();
    bfs_reverse_SCCDAG();

    int ans = 0;
    for (int i = 1; i <= scc_cnt; i++){
        if(vis[i]){
            ans += scc_sz[i];
        }
    }
    cout << ans << endl;
    return 0;
}