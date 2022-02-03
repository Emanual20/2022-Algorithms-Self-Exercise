#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 10;
char s[maxn];
ll cnt[256];
ll dp[26][maxn];
const ll MOD = 998244353;
ll fac_prev[maxn], inv[maxn];
ll quickpow(ll base, ll exp){
    ll ret = 1, now_base = base;
    while(exp){
        if(exp & 1)
            ret = ret * now_base % MOD;
        now_base = now_base * now_base % MOD;
        exp >>= 1;
    }
    return ret;
}
void init_prev(){
    fac_prev[0] = fac_prev[1] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= 5000; i++){
        fac_prev[i] = fac_prev[i - 1] * i % MOD;
    }
    for (int i = 2; i <= 5000; i++){
        inv[i] = quickpow(fac_prev[i], MOD - 2);
    }
}
/*
* C(x, y) = A(x, y)/A(x, x) = y!/x!(y-x)! = y! * inv(x!) * inv((y-x)!)
*/
ll C(ll x, ll y){
    if(x > y || x < 0 || y < 0)
        return 0;
    return (fac_prev[y] * inv[x] % MOD)* inv[y - x] % MOD;
}
int main(){
    init_prev();
    cin >> s;
    ll len = strlen(s);

    for (int i = 0; i < len; i++){
        cnt[s[i] - 'a']++;
    }

    for (ll i = 'a'; i <= 'z'; i++){
        for (ll j = 1; j <= len; j++){
            for (ll k = 0; k <= min(cnt[i - 'a'], j); k++){
                if(i - 'a' > 0 && k != j)
                    dp[i - 'a'][j] = (dp[i - 'a'][j] + dp[i - 'a' - 1][j - k] * C(k, j) % MOD) % MOD;
                else if(k == j)
                    dp[i - 'a'][j] = (dp[i - 'a'][j] + C(k, j) % MOD) % MOD;
                // cout << i - 'a' << " " << j << " " << k << " " << dp[i - 'a'][j] << endl;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= len; i++){
        ans = (ans + dp['z' - 'a'][i]) % MOD;
    }

    cout << ans % MOD << endl;
    return 0;
}
