/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, w[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> w[i];
        }
        int ans = 0;
        int left = 0, right = n + 1, w1 = 0, w2 = 0;
        while(left < right){
            if(w1 == w2){
                ans = max(ans, left + n + 1 - right); 
            }

            if(w1 < w2)
                w1 += w[++left];
            else
                w2 += w[--right];
        }
        cout << ans << "\n";
    }
    return 0;
}