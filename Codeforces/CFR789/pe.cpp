/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t, n, a[maxn], b[maxn], vis[maxn];
vector<int> edges[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
            edges[a[i]].push_back(b[i]);
            edges[b[i]].push_back(a[i]);
        }

        int left = 1, right = n;
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            if(!vis[i]){
                int tot = 0;
                queue<int> q;
                q.push(i), vis[i] = 1;
                while(!q.empty()){
                    auto now = q.front();
                    tot += 1;
                    for(auto &nto : edges[now]){
                        if(!vis[nto]){
                            q.push(nto), vis[nto] = 1;
                        }
                    }
                    q.pop();
                }

                if(tot == 1)
                    continue;
        
                vector<int> tmp;
                while(tot > 1){
                    tot -= 2;
                    tmp.push_back(left++);
                    tmp.push_back(right--);
                }
                for (int i = 1; i < tmp.size(); i++){
                    ans += abs(tmp[i] - tmp[i - 1]);
                }
                ans += abs(tmp[0] - tmp[tmp.size() - 1]);
            }
        }

        cout << ans << endl;

        for (int i = 1; i <= n; i++){
            edges[i].clear();
            vis[i] = 0;
        }
    }
    return 0;
}