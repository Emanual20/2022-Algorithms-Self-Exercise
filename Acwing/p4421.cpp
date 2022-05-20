/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 1e3 + 10;
int n, r, a[maxn], dp[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> r;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[n + 1] = 0;
    for (int i = n; i >= 1; i--){
        if(a[i] == 1){
            int left = max(1, i - r + 1), right = min(n, i + r - 1);
            for (int j = left; j <= right; j++){
                dp[j] = min(dp[j], dp[right + 1] + 1);
            }
        }
    }
    cout << dp[1] << endl;
    return 0;
}