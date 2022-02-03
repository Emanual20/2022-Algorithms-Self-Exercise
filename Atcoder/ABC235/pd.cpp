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
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
int dp[maxn];
ll a, n, maxneed = 0, maxtry = 0, tot = 0;
ll digits(ll x){
    if(x==0)
        return 1;
    ll ret = 0, now = x;
    while(now){
        now /= 10;
        ret++;
    }
    return ret;
}
ll isvalid(ll x){
    return x > 10 && x % 10 != 0;
}
ll isneed(ll des, ll src){
    return des <= maxneed && dp[des] > dp[src] + 1;
}
ll poww(ll base, ll index){
    ll ret = 1;
    while(index--){
        ret *= base;
    }
    return ret;
}
queue<ll> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> n;
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0, maxneed = poww(10, digits(n)), maxtry = n * log(n) * 2;
    // cout << maxneed << " " << maxtry << endl;
    q.push(1);

    while (!q.empty()){
        tot++;
        ll now = q.front();
        if(now == n || tot > maxtry)
            break;
        if(isneed(now * a, now)){
            dp[now * a] = min(dp[now * a], dp[now] + 1);
            q.push(now * a);
        }
        if(isvalid(now)){
            ll trans = now / 10 + now % 10 * poww(10, digits(now) - 1);
            if(isneed(trans, now)){
                dp[trans] = min(dp[trans], dp[now] + 1);
                q.push(trans);
            }
        }
        q.pop();
    }

    if(dp[n] == inf){
        cout << -1 << endl;
    } 
    else{
        cout << dp[n] << endl;
    }
    
    return 0;
}