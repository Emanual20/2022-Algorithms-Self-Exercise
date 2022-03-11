/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;

int prime[maxn], l, r;
// if prime(i) == 1 means i is **not** a prime.
vector<int> prms;
void Eratothenes(int up_bound){
    for (ll i = 2; i <= up_bound; i++){
        if(!prime[i]){
            for (ll j = i * i; j <= up_bound; j += i){
                prime[j] = 1;
            }
            prms.push_back(i);
        }
    }
}

bool check(int x){
    if(x == 1) return false;
    for (int i = 0; i < prms.size(); i++){
        if(prms[i] >= x / prms[i]) break;
        if(x % prms[i] == 0){
            return false;
        }
    }
    return true;
}
vector<int> validations;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Eratothenes(5e4);
    while (cin >> l >> r){
        validations.clear();
        
        for (ll i = l; i <= r; i++){
            if(check(i)){
                validations.push_back(i);
            }
        }

        if(validations.size() < 2){
            cout << "There are no adjacent primes.\n";
            continue;
        }

        int maxi = -inf, maxi_index = -1;
        int mini = inf, mini_index = -1;
        for (int i = 1; i < validations.size(); i++){
            int tmp = validations[i] - validations[i - 1];
            if(tmp > maxi){
                maxi = max(maxi, tmp);
                maxi_index = i;
            }
            if(tmp < mini){
                mini = min(mini, tmp);
                mini_index = i;
            }
        }

        cout << validations[mini_index - 1] << "," << validations[mini_index] << " are closest, ";
        cout << validations[maxi_index - 1] << "," << validations[maxi_index] << " are most distant.\n";
    }
    return 0;
}
/*
1 100
1000000000 1001000000
1000000000 1000000008
2147483587 2147483647
2147481000 2147483646
1 2
2 3
*/