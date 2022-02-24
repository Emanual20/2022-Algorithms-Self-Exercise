/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll MOD = 1e9 + 7;
int a[maxn], f[maxn], n, p;
ll dp[maxn];
map<string, int> mapp;
string s[maxn];
string int2string(int x){
    string ret = "";
    while(x){
        ret += ((x % 2) + '0');
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = int2string(a[i]);
        mapp[s[i]] = 1;
    }

    for (int i = 1; i <= n; i++){
        int tot0 = 0;
        string tmp = s[i];
        for (int j = tmp.length() - 1; j >= 0; j--){
            if(tmp[j] == '0'){
                tot0++;
                if(tot0 == 2){
                    tot0 = 0;
                    if(mapp.count(tmp.substr(0, j))){
                        f[i] = 1;
                        break;
                    }
                }
            }
            else{
                if(tot0 == 1){
                    break;
                }
                if(tot0 == 0 && mapp.count(tmp.substr(0, j))){
                    f[i] = 1;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if(!f[i]){
            dp[s[i].length()]++;
        }
    }

    for (int i = 1; i <= p; i++){
        dp[i + 1] += dp[i];
        dp[i + 1] %= MOD;
        dp[i + 2] += dp[i];
        dp[i + 2] %= MOD;
    }

    ll tot = 0;
    for (int i = 1; i <= p; i++){
        tot += dp[i];
    }
    tot %= MOD;
    cout << tot << endl;
    return 0;
}