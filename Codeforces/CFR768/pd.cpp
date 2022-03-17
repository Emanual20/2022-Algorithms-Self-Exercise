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
const int inf = 0x3f3f3f3f;
int t, n, k, x;
vector<int> a, b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        a.clear(), b.clear();
        for (int i = 1; i <= n; i++){
            cin >> x;
            a.push_back(x);
        }

        b = a;
        sort(b.begin(), b.end());

        int mini = inf, tmp_l = -1, tmp_r = -1;
        for (int L = 1; L <= n; L++){
            auto iter = lower_bound(b.begin(), b.end(), L);
            int off_l = iter - b.begin();
            int off_r = off_l + (n + k - 1) / 2;
            if (off_l >= 0 && off_l < n && off_r >= 0 && off_r < n && mini > b[off_r] - L){
                mini = min(mini, b[off_r] - L);
                tmp_l = off_l, tmp_r = off_r;
            }
        }

        int now = 0, last = 0, tot = 0;
        cout << b[tmp_l] << " " << b[tmp_r] << '\n';
        for (int i = 0; i < n && tot < k; i++){
            if(a[i] >= b[tmp_l] && a[i] <= b[tmp_r]) now++;
            else now--;
            
            if(now > 0){
                cout << last + 1 << " " << (tot == k - 1 ? n : i + 1) << "\n";
                now = 0, last = i + 1, tot++;
            }
        }
    }
    return 0;
}