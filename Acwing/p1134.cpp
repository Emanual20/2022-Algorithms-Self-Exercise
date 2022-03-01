/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int MOD = 1e5 + 3;
int n, m;
vector<int> edges[maxn];
int dist[maxn], dp[maxn];
void bfs(int src){
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    q.push(src), dist[src] = 0, dp[src] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto &iter : edges[now]){
            if(dist[iter] > dist[now] + 1){
                q.push(iter);
                dist[iter] = dist[now] + 1, dp[iter] = dp[now];
            }
            else if(dist[iter] == dist[now] + 1){
                dp[iter] += dp[now], dp[iter] %= MOD;
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
        edges[fm].push_back(to), edges[to].push_back(fm);
    }
    bfs(1);
    for (int i = 1; i <= n; i++){
        cout << dp[i] << '\n';
    }
    return 0;
}