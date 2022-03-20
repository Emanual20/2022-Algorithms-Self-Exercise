/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, tot = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            for (int k = j; k <= n; k++){
                if(i ^ j ^ k == 0 && (i + j > k && i + k > j && k + j > i)){
                    tot++;
                }
            }
        }
    }
    cout << tot << endl;
    return 0;
}