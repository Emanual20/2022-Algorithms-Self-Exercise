/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e4 + 10;
int t, n;
ll dp[maxn];

bool check(int tmp){
    return dp[tmp] >= n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    for (int i = 1; i <= 40000; i++){
        ll tmp = i - ceil(i * 1.0 / 3);
        dp[i] = dp[i - 1] + tmp * 2;
    }

    cin >> t;
    while(t--){
        cin >> n;
        int left = 0, right = 40000;
        while(left < right){
            int mid = left + right >> 1;
            if(check(mid)){
                right = mid;
            }
            else
                left = mid + 1;
        }
        cout << right << "\n";
    }
    return 0;
}