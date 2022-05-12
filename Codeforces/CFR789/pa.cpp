/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int t, n, a[maxn], tot[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            tot[a[i]] += 1;
        }

        int ans = 0;
        if(tot[0] > 0){
            ans = n - tot[0];
        }
        else{
            int flag = 0;
            for (int i = 1; i <= 100; i++){
                flag = flag || (tot[i] >= 2);
            }
            if(flag){
                ans = n;
            }
            else{
                ans = n + 1;
            }
        }
        cout << ans << endl;
        memset(tot, 0, sizeof(tot));
    }
    return 0;
}