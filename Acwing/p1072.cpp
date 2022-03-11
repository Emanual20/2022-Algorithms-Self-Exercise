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

struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int n, ans = 0;

int dfs(int now, int fm){
    int res1 = 0, res2 = 0;
    for(auto iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(nto != fm){
            int tmp = dfs(nto, now) + nw;
            if(tmp > res1) res2 = res1, res1 = tmp;
            else if(tmp > res2) res2 = tmp;
        }
    }
    ans = max(ans, res1 + res2);
    return res1;
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
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}