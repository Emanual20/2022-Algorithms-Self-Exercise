#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
const ll MOD = 998244353;
ll n, a[maxn], dp[maxn];
stack<ll> maxx, minn, max_v, min_v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0] = 1;

    ll max_sum = 0, min_sum = 0;
    for (int i = 0; i < n; i++){
        ll sum_v = dp[i];
        while(!maxx.empty() && maxx.top() < a[i]){
            max_sum -= max_v.top() * maxx.top();
            sum_v += max_v.top();
            max_sum %= MOD;
            sum_v %= MOD;
            maxx.pop();
            max_v.pop();
        }
        max_sum = (max_sum + sum_v * a[i]) % MOD;
        maxx.push(a[i]);
        max_v.push(sum_v);

        sum_v = dp[i];
        while(!minn.empty() && minn.top() > a[i]){
            min_sum += min_v.top() * minn.top();
            sum_v += min_v.top();
            min_sum %= MOD;
            sum_v %= MOD;
            minn.pop();
            min_v.pop();
        }
        min_sum = (min_sum - sum_v * a[i]) % MOD;
        minn.push(a[i]);
        min_v.push(sum_v);

        // cout << i << " " << max_sum << " " << min_sum << " " << dp[i + 1] << endl;
        dp[i + 1] = (max_sum + min_sum) % MOD;
    }

    cout << (dp[n] + MOD) % MOD << endl;
    return 0;
}