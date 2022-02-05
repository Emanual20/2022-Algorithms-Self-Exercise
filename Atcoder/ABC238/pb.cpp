/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const int MOD = 360;
int n, now = 0, a[maxn], vis[maxn];
vector<int> vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vis[now] = 1;
    vec.push_back(now);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        now += a[i];
        now %= MOD;
        if(!vis[now]){
            vis[now] = 1;
            vec.push_back(now);
        }
    }

    sort(vec.begin(), vec.end());
    int ans = 0;
    for (int i = 0; i < vec.size(); i++){
        ans = max(ans, (i == 0 ? 360 - vec[vec.size()-1] : vec[i] - vec[i - 1]));
    }
    cout << ans << endl;
    return 0;
}