/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10 + 10;
ll dp[maxn][12], x, y;

void init(){
    for (int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }
    for (int i = 2; i < 12; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < 10; k++){
                if(abs(j - k) >= 2)
                    dp[i][j] += dp[i - 1][k];
            }
        }
    }
}

ll solve(int tmp){
    if(tmp == 0) return 0;
    vector<ll> vec;
    while(tmp) vec.push_back(tmp % 10), tmp /= 10;

    ll ret = 0, res = -2;
    for (int i = vec.size() - 1; i >= 0; i--){
        // putting 0 when i == vec.size() - 1
        if(res == -2)
            for (int j = 1; j <= i; j++){
                for (int k = 1; k < 10; k++){
                    ret += dp[j][k];
                }
            }
        // putting 1 - vec[i] - 1
        for (int j = (res == -2 ? 1 : 0); j < vec[i]; j++){
            if(abs(res - j) >= 2){
                ret += dp[i + 1][j];
            }
        }
        
        // putting vec[i]
        if(abs(vec[i] - res) < 2) break;
        res = vec[i];
        // when facing the last one
        if(!i) ret++;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    while(cin >> x >> y){
        auto ansr = solve(y), ansl = solve(x - 1);
        cout << ansr - ansl << endl;
    }
    return 0;
}