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
int dp[maxn][maxn];
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
        int nv, nw;
        cin >> nv >> nw;
        items.push_back({nv, nw});
    }

    for (int i = 0; i < n; i++){
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
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}