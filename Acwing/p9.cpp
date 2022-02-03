/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
vector<int> s;
vector<vector<int>> v, w;
int n, V, dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> V;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.push_back(x);
        vector<int> vec_vtmp, vec_wtmp;
        for (int i = 0; i < x; i++){
            int vtmp, wtmp;
            cin >> vtmp >> wtmp;
            vec_vtmp.push_back(vtmp);
            vec_wtmp.push_back(wtmp);
        }
        v.push_back(vec_vtmp);
        w.push_back(vec_wtmp);
    }

    for (int i = 0; i < n; i++){
        for (int j = V; j >= 0; j--){
            for (int k = 0; k < s[i]; k++){
                dp[j] = j >= v[i][k] ? max(dp[j], dp[j - v[i][k]] + w[i][k]) : dp[j];
            }
        }
    }

    cout << dp[V] << endl;
    return 0;
}