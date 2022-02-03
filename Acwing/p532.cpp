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
const int maxn = 25000 + 10;
int n, t, v;
ll dp[maxn];
vector<int> vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        vec.clear();
        v = 0;
        cin >> n;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            v = max(v, x);
            vec.push_back(x);
        }

        dp[0] = 1;
        for (int i = 0; i < vec.size(); i++){
            for (int j = vec[i]; j <= v; j++){
                dp[j] = dp[j] + dp[j - vec[i]];
            }
        }

        int tot = 0;
        for (int i = 0; i < vec.size(); i++){
            if(dp[vec[i]] == 1){
                tot++;
            }
        }
        cout << tot << endl;
    }
    return 0;
}