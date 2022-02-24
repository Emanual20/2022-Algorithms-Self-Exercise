/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll inf = 1e18;
ll n, t, a[maxn];
struct item{
    ll x, y, z;
};
vector<item> ans_vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        ans_vec.clear();

        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int flag = 1;
        for (int i = 1; i < n; i++){
            flag = flag && (a[i] <= a[i + 1]);
        }
        if(flag){
            cout << 0 << '\n';
            continue;
        }

        if(a[n - 1] > a[n]){
            cout << -1 << '\n';
            continue;
        }

        int tot = 0, flag2 = 1;
        for (int i = n - 2; i > 0; i--){
            if(a[i] > a[i + 1]){
                if(a[n] >= 0){
                    tot++;
                    a[i] = a[i + 1] - a[n];
                    ans_vec.push_back({i, i + 1, n});
                }
                else{
                    flag2 = 0;
                    break;
                }
            }
        }

        if(flag2){
            cout << tot << '\n';
            for (int i = 0; i < tot; i++){
                cout << ans_vec[i].x << " " << ans_vec[i].y << " " << ans_vec[i].z << '\n';
            }
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}