/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-15
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
int t, n;
string sa, sb;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> sa >> sb;

        int tota = 0, totb = 0;
        char res = -1;
        for (int i = 0; i < n; i++){
            if(res != sa[i])
                res = sa[i], tota += 1;
        }
        res = -1;
        for (int i = 0; i < n; i++){
            if(res != sb[i])
                res = sb[i], totb += 1;
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++){
            if(sa[i] != sb[i]){
                ans += (sa[i - 1] == sb[i - 1] && sa[i + 1] == sb[i + 1] ? 3 : 1);
            }
        }
        cout << (tota == totb && sa[0] == sb[0] && sa[n - 1] && sb[n - 1] ? ans : -1) << "\n";
    }
    return 0;
}