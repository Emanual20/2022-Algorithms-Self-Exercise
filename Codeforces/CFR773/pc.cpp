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
const int maxn = 2e5 + 10;
ll t, n, x, a[maxn];
map<ll, ll> mp;
vector<ll> vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        mp.clear(), vec.clear();
        cin >> n >> x;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if(!mp.count(a[i])){
                vec.push_back(a[i]);
                mp[a[i]] = 1;
            }
            else mp[a[i]]++;
        }
        sort(vec.begin(), vec.end());
        int tot = 0;
        for (int i = 0; i < vec.size(); i++){
            ll tmp = min(mp[vec[i]], mp[vec[i] * x]);
            if(tmp){
                mp[vec[i]] -= tmp, mp[vec[i] * x] -= tmp;
                tot += tmp * 2;
            }
        }
        cout << n - tot << endl;
    }
    return 0;
}