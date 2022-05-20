/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
ll n, m, k;
int mini = inf, a[maxn], d[maxn];
vector<int> edges[maxn];

bool check(int tmp){
    for (int i = 1; i <= n; i++){
        d[i] = 0;
    }
    queue<int> q;
    vector<int> seq;
    int tot = 0;
    for (int i = 1; i <= n; i++){
        for(auto &nto : edges[i]){
            if(a[i] <= tmp && a[nto] <= tmp){
                d[nto] += 1;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if(d[i] == 0){
            q.push(i), seq.push_back(i), tot += 1;
        }
    }

    while(!q.empty()){
        auto now = q.front();
        for(auto &nto : edges[now]){
            if(a[now] <= tmp && a[nto] <= tmp){
                d[nto] -= 1;
                if(d[nto] == 0){
                    q.push(nto), seq.push_back(nto), tot += 1;
                }
            }
        }
        q.pop();
    }

    if(tot < n){
        // cout << "FIND cycle for tmp = " << tmp << endl;
        return 1;
    }

    vector<int> dp(n + 1, 1);
    for (int i = 0; i < seq.size(); i++){
        int now = seq[i];
        for(auto &nto : edges[now]){
            if(a[now] <= tmp && a[nto] <= tmp){
                dp[nto] = max(dp[nto], dp[now] + 1);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        res = max(res, dp[i]);
    }
    // cout << "res = " << res << " for tmp = " << tmp << endl;
    return res >= k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mini = min(a[i], mini);
    }
    for (int i = 1; i <= m; i++){
        int nfm, nto;
        cin >> nfm >> nto;
        edges[nfm].push_back(nto);
    }
    
    if(m == 0 && k == 1){
        cout << mini << endl;
        return 0;
    }
    
    int left = 1, right = 1e9 + 7;
    while(left < right){
        int mid = left + right >> 1;
        if(check(mid)){
            right = mid;
        }
        else
            left = mid + 1;
    }

    if(right > 1e9 && !check(right)){
        cout << -1 << "\n";
    }
    else{
        cout << right << "\n";
    }
    return 0;
}