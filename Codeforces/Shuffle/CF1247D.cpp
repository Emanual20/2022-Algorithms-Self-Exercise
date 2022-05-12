/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 10;
int n, k, a[maxn];

struct item{
    int prime, tot;
    bool operator < (const item x) const {
        if(prime != x.prime){
            return prime < x.prime;
        }
        else if(tot != x.tot){
            return tot < x.tot;
        }
        return false;
    }
};

map<vector<item>, int> mp;
vector<item> items[maxn];
vector<item> Prime_Factorization(int x){
    vector<item> ret;
    for (int i = 2; i <= x / i; i++){
        if(x % i == 0){
            int tot = 0;
            while(x % i == 0){
                x /= i, tot++;
            }

            if(tot % k != 0)
                ret.push_back({i, tot % k});
        }
    }
    if(x > 1) ret.push_back({x, 1});
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for (int i = n; i >= 1; i--){
        items[i] = Prime_Factorization(a[i]);
        vector<item> tmp = items[i];
        for (int j = 0; j < tmp.size(); j++){
            tmp[j].tot = k - tmp[j].tot;
        }
        if(mp.find(tmp) != mp.end()){
            ans += mp[tmp];
        }
        
        if(mp.find(items[i]) != mp.end()){
            mp[items[i]] += 1;
        }
        else
            mp[items[i]] = 1;
    }
    cout << ans << endl;
    return 0;
}