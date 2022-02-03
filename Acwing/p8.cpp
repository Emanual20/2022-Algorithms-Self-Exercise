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
const int maxn = 1e2 + 10;
const int inf = 0x3f3f3f3f;
int n, v, m;
struct item{
    int v, m, w;
};
int dp[maxn][maxn];
vector<item> items;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> v >> m;
    for (int i = 0; i < n; i++){
        int now_v, now_m, now_w;
        cin >> now_v >> now_m >> now_w;
        items.push_back({now_v, now_m, now_w});
    }

    int ans = -inf;
    for (int i = 0; i < items.size(); i++){
        for (int j = v; j >= items[i].v; j--){
            for (int k = m; k >= items[i].m; k--){
                dp[j][k] = max(dp[j][k], dp[j - items[i].v][k - items[i].m] + items[i].w);
                ans = max(ans, dp[j][k]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}