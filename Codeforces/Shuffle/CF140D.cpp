/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n;
vector<int> a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    int rem = 0, ans = 0, res = 0;
    for (int i = 0; i < n; i++){
        rem += a[i];
        if(rem > 710){
            break;
        }
        ans += 1;
        res += (max(350, rem) - 350);
    }

    cout << ans << " " << res << endl;
    return 0;
}