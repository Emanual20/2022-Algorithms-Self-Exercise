/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t, n, a[maxn];
map<int, int> mp;

int solve(int k, int need){
    int ret = 0;
    while(need > 0){
        need -= k;
        k *= 2;
        ret++;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        mp.clear();

        cin >> n;
        int res = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            mp[a[i]]++;
            res = max(res, mp[a[i]]);
        }
        int need = n - res;
        int tmp = solve(res, need);
        int ans = need + tmp;
        cout << ans << endl;
    }
    return 0;
}