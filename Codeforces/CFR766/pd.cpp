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
const int maxn = 1e6 + 10;
int a[maxn], vis[maxn], n, maxi = 1, tot = 0;
int ggcd[maxn];

ll ex_gcd(ll a, ll b) {
	return b == 0 ? a : ex_gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        vis[a[i]] = 1;
        maxi = max(maxi, a[i]);
    }

    for (int i = 1; i <= maxi; i++){
        if(vis[i]){
            tot++; continue;
        }
        for (int j = i + i; j <= maxi; j += i){
            if(vis[j]){
                ggcd[i] = ex_gcd(ggcd[i], j);
            }
        }
        // cout << i << " " << ggcd[i] << endl;
        tot += ggcd[i] == i;
    }

    cout << tot - n << endl;
    return 0;
}