/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, a, b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin >> a >> b;
        int ans = b - a;
        for (int a_delta = a; a_delta <= b; a_delta++){
            int b_delta = 0;
            for (int i = 22; i >= 0; i--){
                int bita = (a_delta) & (1 << i), bitb = b & (1 << i);
                if(bita != 0 || bitb != 0)
                    b_delta ^= (1 << i);
                if(bita && !bitb)
                    break;
            }
            ans = min(ans, a_delta + (a_delta | b_delta) + (1 - a - b));
        }
        cout << ans << endl;
    }
}