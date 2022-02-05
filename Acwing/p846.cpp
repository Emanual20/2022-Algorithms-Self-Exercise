/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
vector<int> edges[maxn], centers;
int n, sz[maxn], mss[maxn];
void dfs(int now, int fm){
    sz[now] = 1, mss[now] = 0;
    for(auto &to : edges[now]){
        if(to != fm){
            dfs(to, now);
            sz[now] += sz[to];
            mss[now] = max(mss[now], sz[to]);
        }
    }
    mss[now] = max(mss[now], n - sz[now]);
    if(mss[now] <= n / 2)
        centers.push_back(now);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back(to);
        edges[to].push_back(fm);
    }
    dfs(1, -1);
    cout << mss[centers[0]] << endl;
    return 0;
}