/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
int n = 0, tot = 0, x, a[maxn], dp[maxn], vis[maxn], ans = 0;
vector<vector<int>> vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    a[0] = inf;
    while(cin >> x){
        a[++n] = x;
    }

    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            if(!vis[j] && a[i] <= a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;

    for (int i = 1; i <= n; i++){
        int index = -1, res = inf;
        for (int j = 0; j < vec.size(); j++){
            int nlen = vec[j].size();
            if(nlen && vec[j][nlen - 1] >= a[i] && vec[j][nlen - 1] < res){
                index = j, res = vec[j][nlen - 1];
            }
        }

        if(index != -1){
            vec[index].push_back(a[i]);
        }
        else{
            vec.push_back(vector<int>{a[i]});
        }
    }

    cout << vec.size() << endl;
    return 0;
}