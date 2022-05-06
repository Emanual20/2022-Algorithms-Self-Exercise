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
int t, n, k;
string s;
int a[128];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k >> s;
        int lens = s.length();
        for (int i = 'a'; i <= 'z'; i++){
            a[i] = i;
        }
        int pos = n, res = 'a';
        for (int i = 0; i < lens; i++){
            if(s[i] - 'a' > k){
                pos = i;
                k -= res - 'a';
                break;
            }
            else
                res = max(res, (int)s[i]);
        }

        for (int i = 0; i < lens; i++){
            if(s[i] <= res){
                s[i] = 'a';
            }
        }

        
        if(pos != n){
            res = s[pos];
            int tmp = s[pos] - k;

            for (int i = 0; i < lens; i++){
                if(s[i] >= tmp && s[i] <= res){
                    s[i] = tmp;
                }
            }
        }

        cout << s << "\n";
    }
    return 0;
}