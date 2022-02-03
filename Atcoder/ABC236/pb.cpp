/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int tot[maxn], n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < 4 * n; i++){
        int x;
        cin >> x;
        tot[x]++;
    }

    for (int i = 1; i <= n; i++){
        if(tot[i]==3){
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}