/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
ll n, q;
ll a[maxn], timestamp[maxn], last = 0, rem = 0, res = -1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rem += a[i];
        timestamp[i] = 0;
    }

    for (int i = 1; i <= q; i++){
        int type;
        cin >> type;
        if(type == 1){
            ll pos, x;
            cin >> pos >> x;
            if(timestamp[pos] < res){
                rem += (x - last);
                a[pos] = x, timestamp[pos] = i;
            }
            else{
                rem += (x - a[pos]);
                a[pos] = x, timestamp[pos] = i;
            }
            cout << last * n + rem << "\n";
        }
        else{
            ll x;
            cin >> x;
            rem = 0, last = x, res = i;
            cout << last * n << "\n";
        }
    }
    return 0;
}