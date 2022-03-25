/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, n, dp[12][10][100];

void prepare_dp(){
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 10; i++){
        dp[1][i][i % n]++;
    }
    
    for (int i = 2; i < 12; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < 10; l++){
                    dp[i][j][k] += dp[i - 1][l][(k - j + 10 * n) % n];
                }
            }
        }
    }
}

int solve(int tmp){
    if(tmp == 0) return 1;
    vector<int> vec;
    while(tmp) vec.push_back(tmp % 10), tmp /= 10;

    int ret = 0, res = 0;
    for (int i = vec.size() - 1; i >= 0; i--){
        // try 0 ~ vec[i] - 1
        for (int j = 0; j < vec[i]; j++){
            ret += dp[i + 1][j][(n - res) % n];
        }
        // try vec[i]
        res = (res + vec[i]) % n;
        // when coming to end
        if(!i && !res) ret++;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> a >> b >> n){
        prepare_dp();
        auto ansl = solve(a - 1), ansr = solve(b);
        cout << ansr - ansl << endl;
    }
    return 0;
}