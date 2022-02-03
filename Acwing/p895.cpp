/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief O(N^2) algorithm longest upgrading sequence
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
int dp[maxn], n;
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++){
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] = v[i] > v[j] ? max(dp[j] + 1, dp[i]) : dp[i];
        }
        // for (int j = 0; j < n; j++)
        // {
        //     cout << dp[j] << " ";
        // }
        // cout << endl;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}