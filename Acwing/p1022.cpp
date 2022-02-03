/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const int maxm = 5e2 + 10;
const int maxk = 1e2 + 10;
int dp[maxm][maxn];
int n, m, k;
struct item{
    int ball, damage;
};
vector<item> items;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    m -= 1;
    for (int i = 0; i < k; i++){
        int now_ball, now_damage;
        cin >> now_ball >> now_damage;
        items.push_back({now_ball, now_damage});
    }

    int ans = 0;
    for (int index = 0; index < k; index++){
        for (int i = m; i >= items[index].damage; i--){
            for (int j = n; j >= items[index].ball; j--){
                dp[i][j] = max(dp[i][j], dp[i - items[index].damage][j - items[index].ball] + 1);
                ans = max(ans, dp[i][j]);
            }
        }
    }

    int pos = 0;
    for (int j = 0; j <= n; j++){
        for (int i = 0; i <= m; i++){
            if(dp[i][j] == ans){
                pos = max(pos, m - i);
                break;
            }
        }
    }

    cout << ans << " " << (pos + 1) << endl;
    return 0;
}