/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int s[maxn], a[maxn], n;
bool check(int x){
    memset(a, 0, sizeof(a));
    a[1] = x;
    for (int i = 1; i <= n; i++){
        a[i + 1] = s[i] - a[i] - a[i - 1];
        if(a[i + 1] < 0){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }

    if(n == 1){
        cout << "Yes" << endl
             << 0 << " " << 0 << " " << s[1] << endl;
        return 0;
    }

    int left = 0, right = s[1];
    while(left < right){
        int mid = (left + right) >> 1;
        if(check(mid)){
            cout << "Yes" << endl;
            for (int i = 0; i < n + 2; i++){
                cout << a[i] << " ";
            }
            cout << endl;
            return 0;
        }
        else{
            if(left == right - 1 && left == 0 && !check(mid)){
                break;
            }
            right = mid - 1;
        }
    }
    cout << "No" << endl;
    return 0;
}