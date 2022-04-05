/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e3 + 10;
int t, n;

struct item{
    int totr, res, absnum;
};
item dp[maxn];

string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s;
        memset(dp, 0, sizeof(dp));

        int ans = 0;
        for (int nlen = 1; nlen <= n; nlen++){
            item ndp[maxn];
            memcpy(ndp, dp, sizeof(dp));
            for (int j = 0; j + nlen - 1 < n; j++){
                int right = j + nlen - 1;
                // dp[i][j] begin with j, len = nlen
                // ndp[j] <= dp[j][nlen], dp[j] <= dp[j][nlen - 1]
                // dp[i][j] <= dp[i][j - 1]
                ndp[j].absnum = dp[j].absnum + (s[right] == '+' ? +1 : -1);
                if(s[right] == '-'){
                    ndp[j].totr++;
                    if(ndp[j].totr % 2 == 0)
                        ndp[j].res++;
                }
                else{
                    ndp[j].totr = 0;
                }

                int tmp = -(ndp[j].absnum / 3);
                if(tmp >= 0 && tmp <= ndp[j].res && tmp * 3 == -ndp[j].absnum)
                    ans++;
            }
            memcpy(dp, ndp, sizeof(dp));
        }
        cout << ans << endl;
    }
    return 0;
}