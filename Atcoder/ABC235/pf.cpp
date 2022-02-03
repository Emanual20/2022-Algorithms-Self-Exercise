/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const ll MOD = 998244353;
string n;
struct item {
    ll v;
    ll num;
};
item dp[maxn][1024], dp_noleeding[maxn][1024];
ll m, ans = 0, ans_v = 0, need = 0;
vector<int> needs;
ll poww10[maxn];
void initpow10(){
    /*
    * if p is prime, a * a^(p-2) === 1 (modp)
    */
    poww10[0] = 1;
    for (int i = 1; i < n.length(); i++){
        poww10[i] = (poww10[i - 1] * 10) % MOD;
    }
}
ll fpoww10(ll x){
    return x >= 0 ? poww10[x] : 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        needs.push_back(x);
    }
    initpow10();
    for (int i = 0; i < needs.size(); i++) {
        need = need | (1 << needs[i]);
    }

    {
        // compute dp with leeding zero  [0-9]*[0-9]
        dp[0][0].num = 1;
        for (int i = 0; i <= 9; i++) {
            dp[1][1 << i].v = i, dp[1][1 << i].num = 1;
        }

        /* 
        * Q: How to status transfer?
        * A: dp[i+1][...|(1<<j)].v += 1 * dp[i][...].v +
        *                             j * pow(10, i) * dp[i][...].num 
        */
        for (int i = 1; i < n.length(); i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k < (1 << 10); k++) {
                    dp[i + 1][k | (1 << j)].num = (dp[i + 1][k | (1 << j)].num + dp[i][k].num) % MOD;
                    dp[i + 1][k | (1 << j)].v = (dp[i+1][k | (1 << j)].v + 
                                                1 * dp[i][k].v +
                                                j * fpoww10(i) % MOD * dp[i][k].num % MOD) % MOD;
                }
            }
        }
    }

    {
        // compute dp without leeding zero [1-9][0-9]*
        dp_noleeding[0][0].num = 1;
        for (int i = 1; i <= 9; i++) {
            dp_noleeding[1][1 << i].v = i, dp_noleeding[1][1 << i].num = 1;
        }

        /* 
        * Q: How to status transfer?
        * A: dp_noleeding[i+1][...|(1<<j)].v += 10ll * dp_noleeding[i][...].v + 
        *                                       j * dp_noleeding[i][...].num 
        */
        for (int i = 1; i < n.length(); i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k < (1 << 10); k++) {
                    dp_noleeding[i + 1][k | (1 << j)].num = (dp_noleeding[i + 1][k | (1 << j)].num + dp_noleeding[i][k].num) % MOD;
                    (dp_noleeding[i][k].num)
                        ? dp_noleeding[i + 1][k | (1 << j)].v = (dp_noleeding[i + 1][k | (1 << j)].v 
                                                                + 10ll * dp_noleeding[i][k].v % MOD 
                                                                + j * dp_noleeding[i][k].num) % MOD
                        : 0;
                }
            }
        }
        /*
         * dp_noleeding[i][j] represents cases which digit is **exactly** i;
         * but we need digit le than i;
         * so we need transfer.
         */
        for (int i = 1; i < n.length(); i++){
            for (int k = 0; k < (1 << 10); k++){
                dp_noleeding[i + 1][k].num = (dp_noleeding[i + 1][k].num + dp_noleeding[i][k].num) % MOD;
                dp_noleeding[i + 1][k].v = (dp_noleeding[i + 1][k].v + dp_noleeding[i][k].v) % MOD;
            }
        }
    }

    int res = 0;
    ll now = 0;
    for (int i = 0; i <= n.length(); i++) {
        // i means the number of keep digits, we enumerate from the highest digit of n
        if(i == n.length()){
            if((res & need) == need){
                ans += 1;
                ans_v += now;
            }
            break;
        }

        int left = 0, right = (n[i] - '0');
        // cout << need << " " << res << " " << ans << " " << left << " " << right << endl;
        for (int j = left; j < right; j++) {
            int now_res = (i == 0 && j == 0) ? 0 : (res | (1 << j));
            ll now_now = now + j * fpoww10(n.length() - i - 1);
            // cout << now_res << " " << now_now << " " << ans << endl;
            int RemNumDigits = n.length() - i - 1;
            for (int k = 0; k < (1 << 10); k++) {
                if ((need & (k | now_res)) == need) {
                    if (dp[RemNumDigits][k].num) {
                        // cout << "?:" << k << " " << RemNumDigits << " " << dp[k][RemNumDigits].num << " "<<j<<" "<<left<<" "<<right<<endl;
                        (i == 0 && j == 0) 
                            ? ans = (ans + dp_noleeding[RemNumDigits][k].num) % MOD
                            : ans = (ans + dp[RemNumDigits][k].num) % MOD;
                        (i == 0 && j == 0)
                            ? ans_v = (ans_v + now_now * dp_noleeding[RemNumDigits][k].num % MOD+ dp_noleeding[RemNumDigits][k].v) % MOD
                            : ans_v = (ans_v + now_now * dp[RemNumDigits][k].num % MOD + dp[RemNumDigits][k].v) % MOD;
                    }
                }
            }
        }
        res = res | (1 << (n[i] - '0'));
        now = (now + (n[i] - '0') * fpoww10(n.length() - i - 1) % MOD) % MOD;
        // cout << "? " << res << " " << now << " " << ans << " " << ans_v << endl;
    }

    // cout << ans % MOD << " " << ans_v << endl;
    cout << ans_v << endl;

    return 0;
}
/*
223
2
0 1
*/