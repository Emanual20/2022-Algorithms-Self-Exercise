/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, l;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l;
    vector<int> vec(n);
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end());
    int tot = 0, index = -1;
    for (int i = n - 1; i >= 0; i--){
        if(vec[i] >= tot + 1)
            tot++;
        else{
            index = vec[i]; break;
        }
    }

    auto iter = upper_bound(vec.begin(), vec.end(), index);
    tot = 0;
    for (iter--; iter >= vec.begin() && tot < l; iter--, tot++){
        (*iter) += 1;
    }
    
    int ans = 0;
    for (int i = n - 1; i >= 0; i--){
        if(vec[i] >= ans + 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}   