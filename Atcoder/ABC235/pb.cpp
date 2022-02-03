/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = a[0];
    for (int i = 1; i < n; i++){
        if(a[i] > a[i-1]){
            ans = a[i];
        }
        else
            break;
    }
    cout << ans << endl;
    return 0;
}