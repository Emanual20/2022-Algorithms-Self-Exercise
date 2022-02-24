/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;
bool prime[maxn];
void init_prime(){
    prime[1] = 1, prime[2] = 0;
    for (int i = 2; i <= 200; i++){
        if(prime[i]){
            continue;
        }
        for (int j = i * i; j <= 200; j += i){
            prime[j] = 1;
        }
    }
}
int a, b, c, d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init_prime();
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int i = a; i <= b; i++){
        int now = 1;
        for (int j = c; j <= d; j++){
            now = now && prime[i + j];
        }
        ans = ans || now;
    }
    if(ans){
        cout << "Takahashi" << endl;
    }
    else
        cout << "Aoki" << endl;
    return 0;
}