/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, m, dynamic_ind[maxn], in_d[maxn], out_d[maxn];
vector<int> edges[maxn];
int dp[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back(to);
        in_d[to] += 1, out_d[fm] += 1;
    }

    memcpy(dynamic_ind, in_d, sizeof(in_d));
    queue<int> q;
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        if(in_d[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        auto now = q.front();
        for(auto &nto : edges[now]){
            if(out_d[now] > 1 && in_d[nto] > 1){
                dp[nto] = max(dp[nto], dp[now] + 1);
            }
            dynamic_ind[nto] -= 1;
            if(dynamic_ind[nto] == 0){
                q.push(nto);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++){
        res = max(res, dp[i]);
    }
    cout << res << "\n";
    return 0;
}