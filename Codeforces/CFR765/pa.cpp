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
const int maxn = 100 + 10;
int t, n, l, a[maxn], calc[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> l;
        memset(calc, 0, sizeof(calc));
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            int now = a[i];
            for (int j = 0; j < l; j++){
                calc[j] += now % 2;
                now /= 2;
            }
        }
        int ans = 0;
        for (int i = l - 1; i >= 0; i--){
            ans *= 2;
            ans += calc[i] > n - calc[i];
        }
        cout << ans << endl;
    }
    
    return 0;
}