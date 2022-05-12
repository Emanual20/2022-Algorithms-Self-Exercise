#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int prime[maxn];
// if prime(i) == 1 means i is **not** a prime.
void Eratothenes(int up_bound){
    for (ll i = 2; i <= up_bound; i++){
        if(!prime[i]){
            for (ll j = i * i; j <= up_bound; j += i){
                prime[j] = 1;
            }
        }
    }
}

struct item{
    int prime, tot;
};
vector<item> items;
void Prime_Factorization(int x){
    for (int i = 2; i <= x / i; i++){
        if(x % i == 0){
            int tot = 0;
            while(x % i == 0){
                x /= i, tot++;
            }
            items.push_back({i, tot});
        }
    }
    if(x > 1) items.push_back({x, 1});
}