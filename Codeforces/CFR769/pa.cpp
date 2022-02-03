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
const int maxn = 100 + 10;
int t, n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s;
        int tot0 = 0, tot1 = 0;
        for (int i = 0; i < n; i++){
            if(s[i] == '0')
                tot0++;
            else
                tot1++;
        }
        if(tot0 > 1 || tot1 > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}