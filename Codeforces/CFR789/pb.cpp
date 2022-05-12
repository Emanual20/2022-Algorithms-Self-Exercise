/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s;
        vector<int> vec;
        int last = -1, tot = 0;
        for (int i = 0; i <= n; i++){
            if(i == n){
                vec.push_back(tot);
                break;
            }
            if(last == -1){
                last = s[i], tot += 1;
            }
            else if(last == s[i]){
                tot += 1;
            }

            if(s[i] != last){
                vec.push_back(tot), tot = 1, last = s[i];
            }
        }
        
        last = -1;
        int ans = 0;
        for (int i = 0; i < vec.size(); i++){
            if(vec[i] % 2 != 0){
                if(last != -1){
                    ans += (i - last), last = -1;
                }
                else
                    last = i;
            }
        }
        cout << ans << " ";
    }
    return 0;
}