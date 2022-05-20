/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e5 + 10;
int t, l1, r1, l2, r2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = l1 + l2;
        for (int i = 1; i <= 50; i++){
            if(l1 <= i && i <= r1 && l2 <= i && i <= r2){
                ans = min(ans, i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}