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
const int maxn = 2e5 + 10;

int n, m, dp[12][10];

void prepare_dp(){
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 10; i++){
        if(i != 4) dp[1][i] = 1;
    }

    for (int i = 2; i < 12; i++){
        for (int j = 0; j < 9; j++){
            if(j == 4) continue;
            for (int k = 0; k < 9; k++){
                if(k == 4 || (j == 2 && k == 6)) continue;
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
}

int solve(int tmp){
    if(!tmp) return 0;
    vector<int> vec;
    while(tmp) vec.push_back(tmp % 10), tmp /= 10;

    int ret = 0, last = 0;
    for (int i = vec.size() - 1; i >= 0; i--){
        // putting 0 ~ vec[i] - 1
        for (int j = 0; j < vec[i]; j++){
            if(j == 4 || (last == 6 && j == 2)) continue;
            ret += dp[i + 1][j];
        }
        // putting vec[i]
        if(last == 6 && vec[i] == 2) break;
        last = vec[i];
        // check i == 0
        if(!i) ret++;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    prepare_dp();
    while(cin >> n >> m, n || m){
        auto ansl = solve(n - 1), ansr = solve(m);
        cout << ansr - ansl << endl;
    }
    return 0;
}