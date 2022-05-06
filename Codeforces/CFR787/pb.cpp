/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 30 + 10;
int t, n, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int last = a[n] - 1, ans = 0;

        for (int i = n - 1; i >= 1; i--){
            if(last < 0){
                ans = -1;
                break;
            }
            while(a[i] > last){
                a[i] /= 2, ans += 1;
            }
            last = a[i] - 1;
        }

        cout << ans << "\n";
    }
    return 0;
}