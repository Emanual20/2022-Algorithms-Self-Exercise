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
const int maxn = 2e5 + 10;

const int inf = 0x3f3f3f3f;
int x, n, m, S, T, d[maxn], cur[maxn];
int NumOfCage, NumOfCustomer;

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

int trans_cageno(int day, int off){
    return 1 + day * NumOfCage + off;
}

int trans_customerno(int off){
    return 1 + (NumOfCustomer + 1) * NumOfCage + off;
}

int trans_intervalno(int off){
    return 1 + (NumOfCustomer + 1) * NumOfCage + (NumOfCustomer + 1) + off;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> NumOfCage >> NumOfCustomer;
    S = 0, T = trans_intervalno(NumOfCustomer) + 1;
    for (int i = 0; i < NumOfCage; i++){
        cin >> x;
        AddEdge(S, trans_cageno(0, i), x);
    }
    for (int i = 1; i <= NumOfCustomer; i++){
        // edges from yesterday to today
        for (int j = 0; j < NumOfCage; j++){
            AddEdge(trans_cageno(i - 1, j), trans_cageno(i, j), inf);
        }

        // rearrange all the cages today could open
        int NumOfKeys;
        cin >> NumOfKeys;
        vector<int> keys;
        for (int i = 0; i < NumOfKeys; i++){
            cin >> x;
            keys.push_back(x);
        }
        for (int iter1 = 0; iter1 < keys.size(); iter1++){
            AddEdge(trans_cageno(i - 1, keys[iter1] - 1), trans_intervalno(i), inf);
        }
        for (int iter2 = 0; iter2 < keys.size(); iter2++){
            AddEdge(trans_intervalno(i), trans_cageno(i, keys[iter2] - 1), inf);
        }

        // buy items from yesterday
        for (int j = 0; j < NumOfKeys; j++){
            AddEdge(trans_cageno(i - 1, keys[j] - 1), trans_customerno(i), inf);
        }

        // link customers to T
        cin >> x;
        AddEdge(trans_customerno(i), T, x);
    }

    ll ans = dinic();
    cout << ans << endl;
    return 0;
}