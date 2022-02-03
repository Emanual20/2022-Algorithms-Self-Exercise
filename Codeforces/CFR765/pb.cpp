/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 150000 + 10;
const int inf = 0x7fffffff;
int t, n, a[maxn], last[maxn], times[maxn], ans = inf;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        ans = inf;
        memset(times, 0, sizeof(times));
        memset(last, 0, sizeof(last));
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if(last[a[i]]){
                ans = min(ans, i - last[a[i]]);
            }
            last[a[i]] = i;
        }
        ans == inf ? ans = n + 1 : ans = ans;
        cout << n - ans << endl;
    }

    return 0;
}