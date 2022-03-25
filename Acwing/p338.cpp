/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a, b, dp[14][10][10], dp_num[14];

void prepare_dp(){
    dp_num[0] = 1;
    for (int i = 1; i < 14; i++){
        dp_num[i] = dp_num[i - 1] * 10;
    }

    for (int i = 0; i < 10; i++){
        dp[1][i][i] = 1;
    }
    for (int i = 2; i < 14; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < 10; k++){
                for (int p = 0; p < 10; p++){
                    dp[i][j][k] += dp[i - 1][p][k];
                }
            }
            dp[i][j][j] += dp_num[i - 1];
        }
    }
}

vector<ll> solve(ll tmp){
    vector<ll> ret(10, 0), vec;
    if(tmp == 0) {ret[0] = 0; return ret;}
    while(tmp) { vec.push_back(tmp % 10), tmp /= 10;}

    for(int i = vec.size() - 1; i >= 0; i--){
        // putting 0 only if i == vec.size() - 1
        if(i == vec.size() - 1)
            for (int digit_num = 1; digit_num <= i; digit_num++){
                for (int j = 1; j < 10; j++){
                    for (int digit_type = 0; digit_type < 10; digit_type++){
                        ret[digit_type] += dp[digit_num][j][digit_type];
                    }
                }
            }
        // putting 1 - vec[i] - 1
        for (int j = (i == vec.size() - 1 ? 1 : 0); j < vec[i]; j++){
            for (int k = 0; k < 10; k++){
                ret[k] += dp[i + 1][j][k];
            }
        }
        // putting vec[i], we will calculate in the end
        // when coming to an end
        if(!i){
            ll res = 0;
            for (int j = 0; j < vec.size(); j++){
                ret[vec[j]] += (res + 1);
                res += vec[j] * dp_num[j];
            }
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    prepare_dp();
    while(cin >> a >> b){
        if(a >= b) swap(a, b);
        auto ansl = solve(a - 1), ansr = solve(b);
        for (int i = 0; i < 10; i++){
            cout << ansr[i] - ansl[i] << " ";
        }
        cout << endl;
        break;
    }
    return 0;
}