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
int t, n, k, x;
vector<int> vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> x;
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        int flag = 1;
        for (int i = 0; i < n; i++){
            int chk = vec[i];
            auto iter = lower_bound(vec.begin(), vec.end(), chk - k);
            if(*iter == chk - k){
                flag = 0;
                cout << "YES" << endl;
                break;
            }
        }

        if(flag){
            cout << "NO" << endl;
        }
        vec.clear();
    }
    return 0;
}