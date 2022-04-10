/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
 
int t, n, tot[maxn];
vector<int> vec;
 
bool comp(int it1, int it2){
    return it1 > it2;
}
 
bool check(int tmp){
    int ret = 0;
    for (int i = 0; i < vec.size(); i++){
        ret += max(0, vec[i] - (tmp - i));
    }
    return ret >= (tmp - vec.size());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    cin >> t;
    while(t--){
        int x;
 
        cin >> n;
        for (int i = 2; i <= n; i++){
            cin >> x;
            tot[x]++;
        }
        for (int i = 1; i <= n; i++){
            if(tot[i] > 0){
                vec.push_back(tot[i]);
            }
        }
        vec.push_back(1);
        sort(vec.begin(), vec.end(), comp);

        int left = 1, right = n;
        while(left < right){
            int mid = left + right >> 1;
            if(check(mid)){
                right = mid;
            }
            else
                left = mid + 1;
        }
        cout << right << endl;

        for (int i = 1; i <= n; i++){
            tot[i] = 0;
        }
        vec.clear();
    }
    return 0;
}