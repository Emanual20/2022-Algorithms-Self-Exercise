/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e1 + 10;
const int inf = 0x3f3f3f3f;
string s;
vector<string> vs;
int dp[maxn][maxn], n, m, res;
void solve(string sa, string sb){
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= sa.length(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= sb.length(); i++){
        dp[0][i] = i;
    }
    
    for (int i = 1; i <= sa.length(); i++)
    {
        for (int j = 1; j <= sb.length(); j++)
        {
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i-1][j-1] + (sa[i-1] != sb[j-1]));
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        vs.push_back(tmp);
    }

    while(m--){
        cin >> s >> res;
        int ans = 0;
        for (int i = 0; i < n; i++){
            solve(vs[i], s);
            ans += dp[vs[i].length()][s.length()] <= res;
        }
        cout << ans << endl;
    }
    return 0;
}