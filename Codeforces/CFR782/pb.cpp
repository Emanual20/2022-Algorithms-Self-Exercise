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
int t, n, k, a[maxn];
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k >> s;
        int res = k;
        if(k % 2 == 0){
            for (int i = 0; i < n - 1 && k > 0; i++){
                if(s[i] == '0')
                    k--, a[i]++;
            }
            a[n - 1] += k;
        }
        else{
            for (int i = 0; i < n - 1 && k > 0; i++){
                if(s[i] == '1')
                    k--, a[i]++;
            }
            a[n - 1] += k;
        }

        for (int i = 0; i < n; i++){
            if((res - a[i]) % 2 != 0){
                s[i] = (s[i] == '0' ? '1' : '0');
            }
        }

        cout << s << "\n";
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";

        for (int i = 0; i <= n; i++){
            a[i] = 0;
        }
    }
    return 0;
}