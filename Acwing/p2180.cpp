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

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m, S, T, d[maxn], cur[maxn];

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

int a[maxn], dp[maxn], ans = 0;

int idx2inid(int x){
    return x * 2;
}
int idx2outid(int x){
    return x * 2 + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    // question 1: LIS
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            if(a[j] <= a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    
    // question 2: How many LIS
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            if(dp[j] + 1 == dp[i] && a[j] <= a[i]){
                AddEdge(idx2outid(j), idx2inid(i), 1);
            }
        }
    }
    S = 2 * (n + 1) + 1, T = S + 1;
    for (int i = 1; i <= n; i++){
        if(dp[i] == 1) AddEdge(S, idx2inid(i), 1);
        if(dp[i] == ans) AddEdge(idx2outid(i), T, 1);
        AddEdge(idx2inid(i), idx2outid(i), 1);
    }
    int res = dinic();
    cout << res << endl;

    // question 3: How many LIS again
    edges[S].clear(), edges[T].clear();
    for (int i = 1; i <= n * 2; i++){
        edges[i].clear();
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            if(dp[j] + 1 == dp[i] && a[j] <= a[i]){
                AddEdge(idx2outid(j), idx2inid(i), 1);
            }
        }
    }
    S = 2 * (n + 1) + 1, T = S + 1;
    for (int i = 1; i <= n; i++){
        if(dp[i] == 1) AddEdge(S, idx2inid(i), (i == 1 ? inf : 1));
        if(dp[i] == ans) AddEdge(idx2outid(i), T, (i == n ? inf : 1));
        AddEdge(idx2inid(i), idx2outid(i), (i == 1 || i == n ? inf : 1));
    }
    res = dinic();
    cout << (n == 1 ? 1 : res) << endl;
    return 0;
}