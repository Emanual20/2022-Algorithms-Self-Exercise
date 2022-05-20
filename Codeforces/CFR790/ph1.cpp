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

const int maxn = 5e5 + 10;
int t, n, a[maxn];

ll mergesort(int left, int right){
    if(left == right) return 0;
    ll ret = 0;
    int mid = left + right >> 1;
    if(left <= mid)
        ret += mergesort(left, mid);
    if(mid + 1 <= right)
        ret += mergesort(mid + 1, right);

    int i = left, j = mid + 1;
    for (i = left; i <= mid; i++){
        while(j <= right && a[i] >= a[j])
            j += 1;
        ret += (j - mid - 1);
    }

    vector<int> tmp;
    i = left, j = mid + 1;
    while(i <= mid && j <= right){
        while(a[i] < a[j] && i <= mid && j <= right)
            tmp.push_back(a[i]), i += 1;
        while(a[i] >= a[j] && i <= mid && j <= right)
            tmp.push_back(a[j]), j += 1;
    }
    while(i <= mid)
        tmp.push_back(a[i]), i += 1;
    while(j <= right)
        tmp.push_back(a[j]), j += 1;

    for (int i = 0; i < tmp.size(); i++){
        a[left + i] = tmp[i];
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ll ans = mergesort(1, n);
        cout << ans << "\n";
    }
    return 0;
}