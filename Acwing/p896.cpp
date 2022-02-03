/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief O(N^2) algorithm longest upgrading sequence
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int dp[maxn], n, logg[maxn];
vector<int> v;
bool check(int x, int now){
    return v[x] > logg[now];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++){
        dp[i] = 1;
    }
    for (int i = 0; i < n; i++){
        logg[i] = inf;
    }

    int ans = 0;
    logg[0] = -inf;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = i - 1;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(check(i - 1, mid)){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        // cout << i << " " << l << " " << r << " " << endl;
        ans = max(ans, ((l + r) >> 1) + 1);
        logg[((l + r) >> 1) + 1] = v[i - 1];
        // for (int j = 0; j < n; j++){
        //     cout << logg[j] << " ";
        // }
        // cout << endl;
    }

    cout << ans << endl;
    return 0;
}