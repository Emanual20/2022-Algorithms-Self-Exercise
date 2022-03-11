/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 10;
int pos[maxn], t, n;
int a[maxn];
vector<int> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(pos, 0, sizeof(pos));
        memset(a, 0, sizeof(a));
        ans.clear();

        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            pos[a[i]] = i;
        }
        for (int i = n; i >= 1; i--){
            int now = (pos[i] == i ? 0 : pos[i]);
            ans.push_back(now);
            for (int j = 1; j <= i; j++){
                pos[j] = pos[j] - now;
                if(pos[j] <= 0) pos[j] += i;
            }
        }
        for (int i = n - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}