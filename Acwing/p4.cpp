/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const int maxv = 2e3 + 10;
int dp[maxn * 16][maxv];
int n, v;
struct item{
    int v, w;
};
vector<item> items;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> v;
    for (int i = 0; i < n; i++){
        int nv, nw, ns, upper = 0, now = 1;
        cin >> nv >> nw >> ns;
        // 64 -> 32, 16, 8, 4, 2, 1, 1(true) -> 64(false)
        // 7 -> 4, 2, 1
        // ..., 255, 127, 63, 31, 15, 7, 3, 1, 0
        while(upper < ns){
            upper = upper << 1 | 1;
        }
        upper /= 2;
        items.push_back({(ns - upper) * nv, (ns - upper) * nw});
        while(upper){
            items.push_back({now * nv, now * nw});
            now <<= 1;
            upper >>= 1;
        }
    }

    for (int i = 0; i < items.size(); i++){
        for (int j = v; j >= 0; j--){
            /*
            * Notice that when j < items[i].v, the status can also transfer.
            */
            dp[i + 1][j] = (j >= items[i].v 
                            ? max(dp[i][j], dp[i][j - items[i].v] + items[i].w)
                            : dp[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= v; i++){
        ans = max(ans, dp[items.size()][i]);
    }
    cout << ans << endl;
    return 0;
}