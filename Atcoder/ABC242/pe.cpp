/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int maxn = 1e6 + 10;
int t, n;
ll pow26[maxn];
string s;

void initpow26(){
    pow26[0] = 1;
    for (int i = 1; i < maxn; i++){
        pow26[i] = pow26[i - 1] * 26 % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initpow26();

    cin>>t;
    while(t--){
        cin >> n >> s;
        int round = (n + 1) / 2;

        ll ans = 0;
        for (int i = 0; i < round; i++){
            ans += (s[i] - 'A') * pow26[round - 1 - i];
        }

        string tmp_s = s;
        for (int i = 0; i < round; i++){
            tmp_s[n - i - 1] = tmp_s[i];
        }
        ans += (tmp_s <= s);
        cout << (ans + MOD) % MOD << '\n';
    }
    return 0;
}