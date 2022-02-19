/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t, n, a[maxn];
vector<int> odd, even;
vector<int> ori_odd, ori_even;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        odd.clear();
        even.clear();
        ori_odd.clear();
        ori_even.clear();

        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 2){
                odd.push_back(a[i]);
            }
            else{
                even.push_back(a[i]);
            }
        }

        ori_odd = odd, ori_even = even;
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int flag = 1;
        for (int i = 0; i < ori_odd.size(); i++){
            flag = flag && (ori_odd[i] == odd[i]);
        }
        for (int i = 0; i < ori_even.size(); i++){
            flag = flag && (ori_even[i] == even[i]);
        }

        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}