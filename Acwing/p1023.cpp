/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
int n;
vector<int> vec;
int dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(50);
    vec.push_back(100);

    dp[0] = 1;
    cin >> n;
    for (int i = 0; i < vec.size(); i++){
        for (int j = vec[i]; j <= n; j++){
            dp[j] += dp[j - vec[i]];
        }
    }
    cout << dp[n] << endl;
    return 0;
}