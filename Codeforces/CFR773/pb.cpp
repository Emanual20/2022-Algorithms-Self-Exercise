/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int t, n, a[maxn];
set<int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        mp.clear();
        cin >> n;
        int ans = 0;
        
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if(!mp.count(a[i]))
                ans++, mp.insert(a[i]);
        }
        for (int i = 1; i <= ans; i++){
            cout << ans << " ";
        }
        for (int i = ans + 1; i <= n; i++){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}