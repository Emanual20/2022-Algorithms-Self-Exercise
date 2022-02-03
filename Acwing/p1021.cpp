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
const int maxn = 3e3 + 10;
int n, m;
vector<int> vec;
ll dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    dp[0] = 1;
    for (int i = 0; i < vec.size(); i++){
        for (int j = vec[i]; j <= m; j++){
            dp[j] += dp[j - vec[i]];
        }
    }
    cout << dp[m] << endl;
    return 0;
}