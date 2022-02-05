/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const int MOD = 1e9 + 7;
struct item{
    int v, w;
};
vector<item> items;
int n, v, dp[maxn][maxn], ways[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> v;
    for (int i = 0; i < n; i++){
        int now_v, now_w;
        cin >> now_v >> now_w;
        items.push_back({now_v, now_w});
    }

    ways[n][0] = 1;
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j <= v; j++){
            if(j >= items[i].v){
                dp[i][j] = dp[i + 1][j];
                dp[i][j] = max(dp[i][j], dp[i + 1][j - items[i].v] + items[i].w);
                ways[i][j] += (dp[i][j] == dp[i + 1][j] ? ways[i + 1][j] : 0);
                ways[i][j] %= MOD;
                ways[i][j] += (dp[i][j] == dp[i + 1][j - items[i].v] + items[i].w ? ways[i + 1][j - items[i].v] : 0);
                ways[i][j] %= MOD;
            }
            else{
                dp[i][j] = dp[i + 1][j];
                ways[i][j] += ways[i + 1][j];
                ways[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < v; i++){
        if(dp[0][i] == dp[0][v]){
            ans += ways[0][i];
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}