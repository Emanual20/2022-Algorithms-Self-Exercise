/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
const ll inf = 0x3f3f3f3f3f3f;
ll n, m;
ll a[maxn], pre[maxn];

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
        pre[i] = pre[i - 1] + a[i];
    }

    ll ans = -inf;
    dq.push_back({0, 0});
    for (int i = 1; i <= n; i++){
        ans = max(ans, pre[i] - (dq.size() == 0 ? 0 : dq.front().val));
        if(dq.front().index <= i - m)
            dq.pop_front();
        while(!dq.empty() && dq.back().val >= pre[i])
            dq.pop_back();
        dq.push_back({i, pre[i]});
    }
    cout << ans << endl;
    return 0;
}