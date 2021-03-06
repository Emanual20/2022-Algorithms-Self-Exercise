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
struct item{
    int v, w;
};
vector<item> items;
int n, v, dp[maxn][maxn];
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

    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j <= v; j++){
            dp[i][j] = dp[i + 1][j];
            if(j>=items[i].v)
                dp[i][j] = max(dp[i][j], dp[i + 1][j - items[i].v] + items[i].w);
        }
    }

    // cout << dp[0][v] << endl;
    int now_ans = dp[0][v], now_v = v;
    for (int i = 0; i < n; i++){
        if(now_v >= items[i].v && now_ans == dp[i+1][now_v-items[i].v] + items[i].w){
            now_ans -= items[i].w;
            now_v -= items[i].v;
            cout << i + 1 << " ";
        }
    }
    return 0;
}