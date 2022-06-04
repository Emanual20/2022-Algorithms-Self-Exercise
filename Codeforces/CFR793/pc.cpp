/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-22
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
const int inf = 0x3f3f3f3f;
int t, n, a[maxn];
map<int, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        mp.clear();
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            mp[a[i]] += 1;
        }
        int mini = inf, tot = 0;
        for(auto &it : mp){
            int nf = it.second;
            tot += min(nf, 2);
            mini = min(mini, nf);
        }
        tot += (2 - min(2, mini));
        ll ans = tot / 2;
        cout << ans << "\n";
    }
    return 0;
}