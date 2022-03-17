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
const int maxn = 100 + 10;
const int inf = 0x3f3f3f3f;
int t, n, a[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }

        int tmp_min = 0, tmp_max = 0;
        for (int i = 1; i <= n; i++){
            int mini = min(a[i], b[i]), maxi = max(a[i], b[i]);
            a[i] = mini, b[i] = maxi;
            tmp_min = max(tmp_min, a[i]);
            tmp_max = max(tmp_max, b[i]);
        }
        cout << tmp_min * tmp_max << endl;
    }
    return 0;
}