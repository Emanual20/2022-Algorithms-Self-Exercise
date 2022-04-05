/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int t, dp[maxn];
vector<int> vec[26];
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        cin >> s;
        for (int i = 0; i < s.length(); i++){
            vec[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < s.length(); i++){
            dp[i] = s.length() - i;
        }
        for (int i = s.length() - 1; i >= 0; i--){
            int nch = s[i] - 'a';
            dp[i] = min(dp[i], dp[i + 1] + 1);
            auto iter = upper_bound(vec[nch].begin(), vec[nch].end(), i);
            if(iter != vec[nch].end()){
                dp[i] = min(dp[i], dp[*iter + 1] + (*iter - i - 1));
            }
        }
        for (int i = 0; i < 26; i++){
            vec[i].clear();
        }
        cout << dp[0] << endl;
    }
    return 0;
}