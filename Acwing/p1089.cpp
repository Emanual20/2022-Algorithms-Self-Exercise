/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-26
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
int n, m, a[maxn], dp[maxn];

struct item{
    int index;
    ll val;
};
deque<item> dq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dq.push_back({0, 0});
    for (int i = 1; i <= n; i++){
        if(!dq.empty() && dq.front().index < i - m)
            dq.pop_front();
        dp[i] = (dq.size() == 0 ? 0 : dq.front().val) + a[i];
        while(!dq.empty() && dq.back().val >= dp[i])
            dq.pop_back();
        dq.push_back({i, dp[i]});
    }

    int ans = inf;
    for (int i = n; i >= max(1, n - m + 1); i--){
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}