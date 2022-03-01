/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int n, m;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
stack<int> s;
int dfn[maxn], low[maxn], timestamp, vis[maxn];
int scc_cnt, scc_sz[maxn], scc_id[maxn];

void tarjan_scc(int src){
    dfn[src] = low[src] = ++timestamp;
    s.push(src), vis[src] = 1;

    for(auto &iter : edges[src]){
        int nw = iter.w, nto = iter.to;
        if(!dfn[nto]){
            tarjan_scc(nto);
            low[src] = min(low[src], low[nto]);
        }
        else if(vis[nto]){
            low[src] = min(low[src], dfn[nto]);
        }
    }

    if(low[src] == dfn[src]){
        int y;
        scc_cnt++;
        do{
            y = s.top();
            s.pop(), vis[y] = 0, scc_id[y] = scc_cnt;
        } while (y != src);
    }
}

void tarjan(){
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    memset(scc_id, 0, sizeof(scc_id));
    memset(scc_sz, 0, sizeof(scc_sz));
    timestamp = 0, scc_cnt = 0;
    for (int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan_scc(i);
        }
    }
}

vector<edge> new_edges[maxn];
int ind[maxn], outd[maxn];
void BuildNewGraph(){
    for (int i = 1; i <= n; i++){
        for(auto &iter : edges[i]){
            int nto = iter.to;
            if(scc_id[i] != scc_id[nto]){
                new_edges[scc_id[i]].push_back({scc_id[nto], 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        while(cin>>x, x){
            edges[i].push_back({x, 1});
        }
    }

    tarjan();
    BuildNewGraph();

    for (int i = 1; i <= scc_cnt; i++){
        for(auto &iter : new_edges[i]){
            ind[iter.to]++, outd[i]++;
        }
    }

    int cntin = 0, cntout = 0;
    for (int i = 1; i <= scc_cnt; i++){
        cntin += !ind[i], cntout += !outd[i];
    }

    cout << cntin << endl;
    cout << (cntin == 1 && cntout == 1 && scc_cnt == 1 ? 0 : max(cntin, cntout)) << endl;
    return 0;
}