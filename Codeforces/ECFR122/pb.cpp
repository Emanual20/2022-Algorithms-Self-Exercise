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
int t;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> s;
        int n = s.length();
        vector<int> tot;
        tot.push_back(0);
        tot.push_back(0);
        for (int i = 0; i < n; i++){
            tot[s[i] - '0']++;
        }
        sort(tot.begin(), tot.end());
        if(tot[0] == tot[1]){
            cout << max(0, tot[0] - 1) << endl;
        }
        else
            cout << tot[0] << endl;
    }
}