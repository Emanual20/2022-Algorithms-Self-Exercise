/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
ll a[maxn], pre[maxn], ans[maxn], n, k;

struct item{
    int index;
    ll val;
};
deque<item> dq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    
    if(k != 1) dq.push_back({-1, 0});
    for (int i = 1; i <= n; i++){
        if(dq.front().index < i - k - 1)
            dq.pop_front();
        
        ans[i] = a[i];    
        ans[i] = max(ans[i], (dq.size() == 0 ? pre[i] - pre[i - k] : dq.front().val + pre[i]));
        while(!dq.empty() && dq.back().val < ans[i] - pre[i + 1])
            dq.pop_back();
        dq.push_back({i, ans[i] - pre[i + 1]});
    }
    cout << ans[n] << endl;
    return 0;
}