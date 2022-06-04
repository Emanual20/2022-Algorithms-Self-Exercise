/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-03
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

const int maxn = 2e5 + 10;
int t;
ll n, k, a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ll res = 0, maxi = 0, wdsize = min(n, k);
        for (int i = 1; i <= n; i++){
            res += a[i];
            if(i >= wdsize)
                res -= a[i - wdsize], maxi = max(maxi, res);
        }
        for (int i = 1; i <= wdsize; i++){
            maxi += (k - i);
        }
        cout << maxi << "\n";
    }
    return 0;
}