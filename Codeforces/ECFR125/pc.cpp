/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int t, n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s;
        int tot = 0, res = n;
        for (int i = 0; i < n; ){
            if(i == n - 1) break;
            if(i <= n - 2){
                if(s[i] == '('){
                    tot++, res -= 2;
                    i += 2;
                }
                else if (s[i] == ')' && s[i + 1] == ')'){
                    tot++, res -= 2;
                    i += 2;
                }
                else{
                    int now = i;
                    for (i = i + 2; i < n; i++){
                        if(s[i] == ')'){
                            tot++, res -= (i - now + 1);
                            i += 1;
                            break;
                        }
                    }
                }
            }

        }
        cout << tot << " " << res << endl;
    }
    return 0;
}