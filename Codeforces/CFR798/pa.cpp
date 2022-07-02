/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
int t, n, m, k;
string ss, st, ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m >> k >> ss >> st;
        ans = "";
        sort(ss.begin(), ss.end()), sort(st.begin(), st.end());
        int its = 0, itt = 0, last = -1, res = 0, lens = ss.length(), lent = st.length();
        while(its < lens && itt < lent){
            if(res == k){
                if(last == 0)
                    ans += st[itt], itt += 1, last = 1, res = 1;
                else
                    ans += ss[its], its += 1, last = 0, res = 1;
            }
            
            else if(ss[its] < st[itt]){
                ans += ss[its], its += 1;
                if(last != 0){
                    last = 0, res = 1;
                }
                else
                    res += 1;
            }
            else{
                ans += st[itt], itt += 1;
                if(last != 0){
                    last = 0, res = 1;
                }
                else
                    res += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}