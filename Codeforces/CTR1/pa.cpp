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
struct item{
    int index, val;
};
vector<item> vec;

bool comp(item it1, item it2){
    return it1.val < it2.val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            vec.push_back({i, a[i]});
        }
        sort(vec.begin(), vec.end(), comp);
        cout << vec[0].index << " " << vec[n - 1].index << endl;
        vec.clear();
    }
    return 0;
}