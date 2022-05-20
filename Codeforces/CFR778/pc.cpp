/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-19
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
int t, n;
ll x;
map<ll, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        ll sum = 0, tot = 0;
        mp.clear();
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> x;
            sum += x;
            if(mp.find(x) == mp.end()){
                mp[x] = 1;
            }
            else mp[x] = mp[x] + 1;
        }

        queue<ll> q;
        q.push(sum), tot += 1;
        while(!q.empty() && tot < n){
            ll now = q.front(), left, right;
            left = now / 2, right = now - left, tot += 1;
            if(mp.find(left) != mp.end()){
                mp[left] -= 1;
                if(mp[left] <= 0)
                    mp.erase(left);
            }
            else{
                q.push(left);
            }

            if(mp.find(right) != mp.end()){
                mp[right] -= 1;
                if(mp[right] <= 0)
                    mp.erase(right);
            }
            else{
                q.push(right);
            }
            q.pop();
        }

        cout << (tot == n && q.empty() ? "YES\n" : "NO\n");
    }
    return 0;
}