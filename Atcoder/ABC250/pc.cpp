/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, q, val[maxn], pos[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        val[i] = i, pos[i] = i;
    }
    while(q--){
        int x;
        cin >> x;
        int p0 = pos[x], p1 = pos[x];
        p1 += (p0 == n ? -1 : 1);
        int v0 = val[p0], v1 = val[p1];
        swap(val[p0], val[p1]);
        swap(pos[v0], pos[v1]);
    }
    for (int i = 1; i <= n; i++){
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}