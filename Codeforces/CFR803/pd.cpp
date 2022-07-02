/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-28
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

const int maxn = 1e5 + 10;
int t, n, a[maxn];
int l, r;

bool check(int tmp){
    cout << "? " << l << " " << tmp << endl;
    int res = 0, x;
    for (int i = l; i <= tmp; i++){
        cin >> x;
        res += (x < l || x > tmp);
    }
    return (tmp - l + 1 - res) % 2 == 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        l = 1, r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid)){
                r = mid;
            }
            else
                l = mid + 1;
        }
        cout << "! " << r << endl;
    }
    return 0;
}