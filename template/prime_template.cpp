#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int n, prime[maxn];
/*
 * Initalize a Prime Table by Eratothenes.
 * if prime(i) == 1 means i is **not** a prime.
 * Complexity: O(nloglogn)
 */
void Eratothenes(int up_bound){
    for (ll i = 2; i <= up_bound; i++){
        if(!prime[i]){
            for (ll j = i * i; j <= up_bound; j += i){
                prime[j] = 1;
            }
        }
    }
}

/*
 * Factorize a number by 'The Fundamental Theorem of Arithmetic'.
 * Items are stored in increasing order of prime.
 * Complexity: O(n^(1/2))
 */
struct item{
    ll prime, tot;
};
vector<item> Prime_Factorization(int x){
    vector<item> ret;
    for (int i = 2; i <= x / i; i++){
        if(x % i == 0){
            int tot = 0;
            while(x % i == 0){
                x /= i, tot++;
            }
            ret.push_back({i, tot});
        }
    }
    if(x > 1) ret.push_back({x, 1});
    return ret;
}

/*
 * Factorize a number's factorial.
 * You shall call Eratothenes to initialize prime table before calling this function.
 * Items are stored in increasing order of prime.
 * Complexity: O(nlogn)
 */
vector<item> Factorial_Factorization(int x){
    vector<item> ret;
    for (int i = 2; i <= x; i++){
        if(!prime[i]){
            ll tot = 0, base = i;
            while(x / base){
                tot += x / base;
                base *= i;
            }
            ret.push_back({i, tot});
        }
    }
    return ret;
}
