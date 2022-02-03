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
const int maxm = 21 + 10, maxn = 79 + 10;
struct item{
    int v1, v2, w;
};
vector<item> items;
int m, n, k, dp[maxm][maxn];
/*
* A very good problem to identify status.
*   dp[i][j]: whether j represents greater(or equal) to j or just strictly equal to j?
*             which always refers to different status transfer boundary, but always the same transfer formula.
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++){
        int nv1, nv2, nk;
        cin >> nv1 >> nv2 >> nk;
        items.push_back({nv1, nv2, nk});
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < items.size(); i++){
        for (int v1_iter = m; v1_iter >= 0; v1_iter--){
            for (int v2_iter = n; v2_iter >= 0; v2_iter--){
                dp[v1_iter][v2_iter] = min(dp[v1_iter][v2_iter], 
                                           dp[max(0, v1_iter - items[i].v1)][max(0, v2_iter - items[i].v2)] + items[i].w);
            }
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}