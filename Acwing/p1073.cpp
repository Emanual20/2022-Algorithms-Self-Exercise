/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const int inf = 0x3f3f3f3f;

struct edge{
    int to, w, ans;
};
vector<edge> edges[maxn];
int n, ans = inf;

int dfs1(int now, int fm){
    int res = 0;
    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(nto != fm){
            int tmp = dfs1(nto, now) + nw;
            res = max(res, tmp);
            iter.ans = tmp;
        }
    }
    return res;
}

void dfs2(int now, int fm, int fmmaxw){
    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(nto == fm){
            iter.ans = fmmaxw;
        }
    }

    int res1 = 0, res2 = 0, idx1 = -1, idx2 = -1;
    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(iter.ans > res1) res2 = res1, idx2 = idx1, res1 = iter.ans, idx1 = nto;
        else if(iter.ans > res2) res2 = iter.ans, idx2 = nto;
    }

    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w, nans = iter.ans;
        if(nto != fm){
            if(nto != idx1) dfs2(nto, now, res1 + nw);
            else dfs2(nto, now, res2 + nw);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w}), edges[to].push_back({fm, w});
    }
    
    dfs1(1, -1);
    dfs2(1, -1, 0);

    for (int i = 1; i <= n; i++){
        int tmp = 0;
        for(auto &iter : edges[i]){
            tmp = max(tmp, iter.ans);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}