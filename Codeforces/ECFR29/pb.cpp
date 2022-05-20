/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 50 + 10;
const int inf = 0x3f3f3f3f;
int n, a[maxn * 2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    n = n * 2;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    int ans = inf;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int f0 = i, f1 = j;
            int tot = 0, last = -1;
            for (int k = 1; k <= n; k++){
                if(k != f0 && k != f1){
                    if(last != -1){
                        tot += abs(a[k] - last);
                        last = -1;
                    }
                    else{
                        last = a[k];
                    }
                }
            }
            // cout << i << " " << j << " " << tot << endl;
            ans = min(ans, tot);
        }
    }
    cout << ans << endl;
    return 0;
}