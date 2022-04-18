/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, a, b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> b >> a;
        int tmp = b / (a + 1);
        int tot1 = b - b / (a + 1) * (a + 1);
        int tot0 = a + 1 - tot1;
        string ans = "";
        for (int i = 1; i <= tot0; i++){
            for (int j = 1; j <= tmp; j++){
                ans += "R";
            }
            ans += "B";
        }

        for (int i = 1; i <= tot1; i++){
            for (int j = 1; j <= tmp + 1; j++){
                ans += "R";
            }
            ans += "B";
        }
        ans = ans.substr(0, ans.length() - 1);
        cout << ans << endl;
    }
    return 0;
}