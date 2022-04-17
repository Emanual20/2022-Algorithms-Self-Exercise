typedef long long ll;
const int maxn = 1e5 + 10;
class Solution {
public:
    ll f[maxn], n, dp[maxn];
    void getfail(string s) {
        f[0] = f[1] = 0;
        for (int i = 1; i < n; ++i) {
            int j = f[i];
            while (j && s[i] != s[j]) j = f[j];
            f[i+1] = s[i] == s[j] ? j+1 : 0;
        }
    }
    long long sumScores(string s) {
        ll ans = 0;
        n = s.length();
        getfail(s);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[f[i]] + 1;
            ans += dp[i];
        }
        return ans;
    }
};