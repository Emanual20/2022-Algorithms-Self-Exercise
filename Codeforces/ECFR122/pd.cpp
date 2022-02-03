/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxv = 1e3 + 10;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
int t, n, k;
vector<int> b, c;
struct item{
    int v, w;
};
vector<item> items;
int dp[maxn], cost[maxv];
queue<int> q;
void init(){
    q.push(1);
    cost[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 1; i <= now; i++){
            if(i > now / 2)
                i = now;
            if(now + now / i < maxv && !cost[now + now/i]){
                cost[now + now / i] = cost[now] + 1;
                q.push(now + now / i);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        b.clear();
        c.clear();
        items.clear();

        cin >> n >> k;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            b.push_back(x);
        }
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            c.push_back(x);
        }

        for (int i = 0; i < n; i++){
            items.push_back({cost[b[i]], c[i]});
        }

        int sum_v = 0;    
        for (int i = 0; i < items.size(); i++){
            sum_v += items[i].v;
        }
        int v = min(k, sum_v);
        for (int i = 0; i < n; i++){
            for (int j = v; j >= items[i].v; j--){
                dp[j] = max(dp[j], dp[j - items[i].v] + items[i].w);
            }
        }

        int ans = 0;
        for (int i = 0; i <= min(k, v); i++){
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}