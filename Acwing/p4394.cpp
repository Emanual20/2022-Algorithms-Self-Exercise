/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int n, k, a[maxn];
map<int, int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = -1, st = 0, indexl = -1;
    for (int l = 1, r = 1; l <= n && r <= n; r++){
        if(!mp.count(a[r])){
            st++;
        }
        mp[a[r]]++;
        if(st > k){
            for (int j = l; j <= r; j++){
                if(mp[a[j]] == 1){
                    mp.erase(a[j]);
                    l = j + 1;
                    break;
                }
                else
                    mp[a[j]]--;
            }
            st--;
        }
        if(st <= k && r - l + 1 >= ans){
            ans = r - l + 1, indexl = l;
        }
    }
    cout << indexl << " " << indexl + ans - 1 << endl;
    return 0;
}