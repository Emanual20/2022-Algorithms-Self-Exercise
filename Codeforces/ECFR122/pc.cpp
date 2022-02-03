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
ll t, hc, dc, hm, dm, k, w, a;
bool check(ll nhc, ll ndc, ll nhm, ll ndm){
    ll times_res = nhc / ndm - (nhc % ndm == 0 ? 1 : 0) + 1;
    ll times_need = ceil(nhm * (long double)1.0 / ndc);
    // cout << nhc<<" "<<ndc<<" "<<nhm<<" "<<ndm<<" :"<<times_res << " " << times_need << endl;
    return times_res >= times_need;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin >> hc >> dc;
        cin >> hm >> dm;
        cin >> k >> w >> a;
        int ans = 0;
        for (ll i = 0; i <= k; i++){
            ans = ans || check(hc + i * a, dc + (k - i) * w, hm, dm);
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}