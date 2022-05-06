/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> s;
        int lens = s.length();
        int last1 = 0, first0 = lens - 1;
        for (int i = 0; i < lens; i++){
            if(s[i] == '1')
                last1 = max(last1, i);
            else if(s[i] == '0')
                first0 = min(first0, i);
        }
        int ans = first0 - last1 + 1;
        cout << ans << "\n";
    }
    return 0;
}