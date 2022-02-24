/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll MOD = 998244353;
ll t, n, m, k, q;
int row[maxn], col[maxn], cnt_row = 0, cnt_col = 0;
struct oper{
    ll x, y;
};
vector<oper> opers;
bool check(ll x, ll y){
    if(cnt_row >= n || cnt_col >= m){
        return false;
    }

    if(!row[x] || !col[y]){
        if(!row[x]){
            row[x] = 1, cnt_row++;
        }
        if(!col[y]){
            col[y] = 1, cnt_col++;
        }
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        opers.clear();
        cnt_row = 0, cnt_col = 0;

        cin >> n >> m >> k >> q;
        for (int i = 1; i <= q; i++){
            int x, y;
            cin >> x >> y;
            opers.push_back({x, y});
        }

        ll now = 0;
        for (int i = q - 1; i >= 0; i--){
            now += check(opers[i].x, opers[i].y);
        }
        ll ans = 1;
        for (int i = 1; i <= now; i++){
            ans *= k;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}