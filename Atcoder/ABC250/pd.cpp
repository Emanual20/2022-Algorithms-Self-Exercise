/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n;

int prime[maxn];
vector<int> vec;
// if prime(i) == 1 means i is **not** a prime.
void Eratothenes(int up_bound){
    for (ll i = 2; i <= up_bound; i++){
        if(!prime[i]){
            vec.push_back(i);
            for (ll j = i * i; j <= up_bound; j += i){
                prime[j] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    Eratothenes(1e6 + 1);
    int ans = 0;
    for (int i = 0; i < vec.size(); i++){
        ll now = vec[i];
        for (int j = i + 1; j < vec.size(); j++){
            ll tmp = n / j / j / j;
            if(now < tmp){
                ans += 1;
            }
            else
                break;
        }
    }
    cout << ans << endl;
    return 0;
}