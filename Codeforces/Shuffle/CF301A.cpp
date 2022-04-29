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
const int maxn = 200 + 10;

int n, a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int tot = 0, ans = 0;
    for (int i = 1; i <= (2 * n - 1); i++){
        cin >> a[i];
        tot += (a[i] < 0), a[i] = abs(a[i]), ans += a[i];
    }

    sort(a + 1, a + 2 * n);

    if((tot % 2 == 0) || (tot >= n && (tot - n) % 2 == 0) || (n > 2 && tot % (n - 2) == 0)){
        cout << ans << endl;
    }
    else{
        cout << ans - 2 * a[1] << endl;
    }

    return 0;
}