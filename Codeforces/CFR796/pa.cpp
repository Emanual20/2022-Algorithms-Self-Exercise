/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
int t, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int tot = 0, mini = -1;
        for (int i = 0; i <= 30; i++){
            if(n & (1 << i)){
                tot += 1;
                if(mini == -1)
                    mini = i;
            }
        }

        if(n == 1){
            cout << 3 << "\n";
        }
        else if(tot == 1){
            cout << (1 << mini) + 1 << "\n";
        }
        else{
            cout << (1 << mini) << "\n";
        }
    }
    return 0;
}