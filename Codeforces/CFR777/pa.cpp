/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int tot1 = 0, tot2 = 0;
        tot1 = tot2 = n / 3;
        if(n % 3 == 1)
            tot1++;
        else if(n % 3 == 2)
            tot2++;
        if(tot1 > tot2){
            cout << 1;
            for (int i = 1; i <= tot2; i++){
                cout << "21";
            }
            cout << endl;
        }
        else if(tot2 > tot1){
            cout << 2;
            for (int i = 1; i <= tot1; i++){
                cout << "12";
            }
            cout << endl;
        }
        else{
            for (int i = 1; i <= tot1; i++){
                cout << "21";
            }
            cout << endl;
        }
    }
    return 0;
}