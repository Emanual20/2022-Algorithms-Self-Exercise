/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, x;
vector<int> vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        vec.clear();
        for (int i = 1; i <= n; i++){
            cin >> x;
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        if(n == 1){
            if(vec[0] == 1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            if(vec[n - 1] - vec[n - 2] <= 1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}