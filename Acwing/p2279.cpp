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
const long double eps = 1e-8;

const int inf = 0x3f3f3f3f;
int n, m, S, T, d[maxn], cur[maxn];

struct edge{
    ll to;
    double f;
    int nid, rid;
};
vector<edge> edges[maxn];

void AddEdge(int fm, int to, double c){
    int fmrid = edges[to].size(), torid = edges[fm].size();
    edges[fm].push_back({to, c, torid, fmrid});
    // notice that given flow network is a direct graph
    edges[to].push_back({fm, c, fmrid, torid});    
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
            int nto = iter.to;
            double nf = iter.f;
            if(d[nto] == -1 && nf > eps){
                d[nto] = d[now] + 1, cur[nto] = 0;
                q.push(nto);
                if(nto == T) return true;
            }
        }
        q.pop();
    }
    return false;
}

double FindAugmentation(int now, double limit){
    if(now == T) return limit;
    double flow = 0;
    for (int i = cur[now]; i < edges[now].size() && flow < limit; i++){
        auto iter = edges[now][i];
        ll nto = iter.to, nnid = iter.nid, nrid = iter.rid;
        double nf = iter.f;
        cur[now] = i;
        if(d[nto] == d[now] + 1 && nf > 0){
            double tmp = FindAugmentation(nto, min(nf, limit - flow));
            if(tmp < eps) d[nto] = -1;
            edges[now][nnid].f -= tmp, edges[nto][nrid].f += tmp;
            flow += tmp;
        }
    }
    return flow;
}

double dinic(){
    double ret = 0;
    while(dilaminate()){
        double tmp = 0;
        while(tmp = FindAugmentation(S, inf))
            ret += tmp;
    }
    return ret;
}

struct item{
    int fm, to;
    int w;
};
vector<item> items[maxn];

bool check(long double tmp){
    double res = 0;
    for (int i = 1; i <= n; i++){
        for(auto &iter : items[i]){
            int nfm = iter.fm, nto = iter.to, nw = iter.w;
            long double nc = nw * 1.0f - tmp;
            if(nc <= 0){
                res += nc;
            }
            else{
                AddEdge(nfm, nto, nc);
            }
        }
    }
    res += dinic();

    for (int i = 1; i <= n; i++){
        edges[i].clear();
    }

    return res <= 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> S >> T;
    for (int i = 1; i <= m; i++){
        int nfm, nto, nw;
        cin >> nfm >> nto >> nw;
        items[nfm].push_back({nfm, nto, nw});
        // items[nto].push_back({nto, nfm, nw});
    }

    long double left = 0, right = 1e7;
    while(right - left > eps){
        long double mid = (left + right) / 2;
        if(check(mid)){
            right = mid;
        }
        else left = mid;
    }

    cout << fixed << setprecision(2) << right << endl;
    return 0;
}