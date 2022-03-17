/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, a[maxn], lastpos[maxn], ans = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        lastpos[a[i]] = i;
    }

    // int last = -1;
    // for (int i = 1; i <= n; i++){
    //     if(lastpos[a[i]] == last){
    //         last = -1;
    //         continue;
    //     }
        
    //     if(lastpos[a[i]] > last + 1){
    //         last = lastpos[a[i]];
    //     }
    //     else
    //         ans++;
    // }
}