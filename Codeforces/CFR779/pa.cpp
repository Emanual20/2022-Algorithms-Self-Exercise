/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s;
        int tot = 2, ans = 0;
        for (int i = 0; i < n; i++){
            if(s[i] == '0'){
                ans += (2 - min(tot, 2));
                tot = 0;
            }
            else if(s[i] == '1'){
                tot++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}