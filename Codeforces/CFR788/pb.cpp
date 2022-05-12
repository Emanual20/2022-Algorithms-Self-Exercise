/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, k;
string s;
set<char> st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s >> k;
        st.clear();
        for (int i = 1; i <= k; i++){
            char x;
            cin >> x;
            st.insert(x);
        }

        int last = 0, ans = 0, lens = s.length();
        for (int i = 0; i < lens; i++){
            if(st.find(s[i]) != st.end()){
                ans = max(ans, i - last);
                last = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}