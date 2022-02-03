/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6e3 + 10;
vector<vector<int>> edges;
int a[maxn], dp[2][maxn], n, vis[maxn];
void dfs(int now){
    if(vis[now])
        return;
    for(auto &to : edges[now]){
        if(!vis[to])
            dfs(to);
        dp[0][now] += max(0, max(dp[0][to], dp[1][to]));
        dp[1][now] += dp[0][to] > 0 ? dp[0][to] : 0;
    }
    dp[1][now] += a[now];
    vis[now] = 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        edges.push_back(vector<int>());
    }
    for (int i = 0; i < n - 1; i++){
        int fm, to;
        cin >> fm >> to;
        edges[to - 1].push_back(fm - 1);
    }

    for (int i = 0; i < n; i++){
        dfs(i);
    }

    int ans = -0x3f3f3f3f;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            ans = max(ans, dp[j][i]);
        }
    }
    cout << ans << endl;
    return 0;
}