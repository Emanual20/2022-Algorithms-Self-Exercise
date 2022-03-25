/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int tot1 = 0, tot02 = 0, flagabs1 = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] == 1)
                tot1++;
            if(a[i] == 0 || a[i] == 2)
                tot02++;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i < n; i++){
            if(a[i + 1] - a[i] == 1){
                flagabs1 = 1;
            }
        }
        if((tot1 > 0 && tot02 == 0 && !flagabs1) || tot1 == 0){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}