/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n, a[maxn], dp[maxn], vis[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= 15; i++){
        for (int j = 0; j < 32768; j++){
            if(!dp[j]){
                int q1 = (j + 1) % 32768, q2 = j * 2 % 32768;
                if(dp[q1] == i)
                    dp[j] = i + 1;
                if(dp[q2] == i)
                    dp[j] = i + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << dp[a[i]] - 1 << " ";
    }
    cout << endl;
    return 0;
}