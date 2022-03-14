/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int sum = 0;
    for (int i = 0; i < 7; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + 7);
    cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << endl;
    return 0;
}