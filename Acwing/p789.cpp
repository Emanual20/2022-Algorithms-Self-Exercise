/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, q, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int x;
    while(q--){
        cin >> x;
        int left = 1, right = n;
        while(left < right){
            int mid = left + right >> 1;
            if(a[mid] >= x){
                right = mid;
            }
            else
                left = mid + 1;
        }
        if(a[right] != x){
            cout << -1 << " " << -1 << "\n";
            continue;
        }
        cout << right - 1 << " ";

        left = 1, right = n;
        while(left < right){
            int mid = left + right + 1 >> 1;
            if(a[mid] <= x){
                left = mid;
            }
            else
                right = mid - 1;
        }
        cout << right - 1 << endl;
    }
    return 0;
}