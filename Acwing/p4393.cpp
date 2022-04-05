/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll w[4], tot[4], ans = 0;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++){
        cin >> w[i];
    }
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        tot[s[i] - '1']++;
    }
    for (int i = 0; i < 4; i++){
        ans += w[i] * tot[i];
    }
    cout << ans << endl;
    return 0;
}