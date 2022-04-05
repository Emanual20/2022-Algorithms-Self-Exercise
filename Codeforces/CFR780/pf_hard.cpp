/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
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
        set<pii> st[3];
        st[0].insert(make_pair(0, -1));
        int tot = 0, ans = 0;
        for (int i = 0; i < n; i++){
            tot += (s[i] == '+' ? +1 : -1);
            int rem = (tot % 3 + 3) % 3;
            auto key = make_pair(-rem, i);
            ans += st[rem].order_of_key(key);
            st[rem].insert(key);
        }
        cout << ans << endl;
    }
    return 0;
}