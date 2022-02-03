/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
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
const int MOD = 1e9 + 7;
int dp[maxn];
vector<int> items;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        items.push_back(i);
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n; j++){
            dp[j] = j >= items[i] ? (dp[j - items[i]] + dp[j]) % MOD : dp[j];
        }
    }

    cout << dp[n] << endl;
    return 0;
}