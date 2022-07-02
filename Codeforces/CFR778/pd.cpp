/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-04
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

const ll MOD = 998244353;
const int maxn = 2e5 + 10;
int t, n;
ll ans = 0;

struct edge{
    int to, x, y;
};
vector<edge> edges[maxn];

int prime[maxn];
vector<int> pm_res;
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
            pm_res.push_back(i);
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
    for (int i = 0; i < pm_res.size(); i++){
        int npm = pm_res[i];
        if(x % npm == 0){
            int tot = 0;
            while(x % npm == 0){
                x /= npm, tot++;
            }
            ret.push_back({npm, tot});
        }
    }
    if(x > 1) ret.push_back({x, 1});
    return ret;
}

vector<item> merge(vector<item> vec1, vector<item> vec2){
    vector<item> ret;
    int n1 = vec1.size(), n2 = vec2.size();
    int it1 = 0, it2 = 0;
    while(it1 < n1 && it2 < n2){
        int pm1 = vec1[it1].prime, pm2 = vec2[it2].prime;
        int tt1 = vec1[it1].tot, tt2 = vec2[it2].tot;
        if(pm1 == pm2){
            ret.push_back({pm1, max(tt1, tt2)});
            it1 += 1, it2 += 1;
        }
        else if(pm1 < pm2){
            ret.push_back({pm1, tt1}), it1 += 1;
        }
        else{
            ret.push_back({pm2, tt2}), it2 += 1;
        }
    }
    while(it1 < n1){
        int pm1 = vec1[it1].prime, tt1 = vec1[it1].tot;
        ret.push_back({pm1, tt1}), it1 += 1;
    }
    while(it2 < n2){
        int pm2 = vec2[it2].prime, tt2 = vec2[it2].tot;
        ret.push_back({pm2, tt2}), it2 += 1;
    }
    return ret;
}

vector<item> insert(vector<item> vec1, vector<item> vec2){
    vector<item> ret;
    int n1 = vec1.size(), n2 = vec2.size();
    int it1 = 0, it2 = 0;
    while(it1 < n1 && it2 < n2){
        int pm1 = vec1[it1].prime, pm2 = vec2[it2].prime;
        int tt1 = vec1[it1].tot, tt2 = vec2[it2].tot;
        if(pm1 == pm2){
            ret.push_back({pm1, tt1 + tt2});
            it1 += 1, it2 += 1;
        }
        else if(pm1 < pm2){
            ret.push_back({pm1, tt1}), it1 += 1;
        }
        else{
            ret.push_back({pm2, tt2}), it2 += 1;
        }
    }
    while(it1 < n1){
        int pm1 = vec1[it1].prime, tt1 = vec1[it1].tot;
        ret.push_back({pm1, tt1}), it1 += 1;
    }
    while(it2 < n2){
        int pm2 = vec2[it2].prime, tt2 = vec2[it2].tot;
        ret.push_back({pm2, tt2}), it2 += 1;
    }
    return ret;
}

vector<item> remove(vector<item> vec1, vector<item> vec2){
    vector<item> ret;
    int n1 = vec1.size(), n2 = vec2.size();
    int it1 = 0, it2 = 0;
    while(it1 < n1 && it2 < n2){
        int pm1 = vec1[it1].prime, pm2 = vec2[it2].prime;
        int tt1 = vec1[it1].tot, tt2 = vec2[it2].tot;
        if(pm1 == pm2){
            if(tt1 - tt2 > 0)
                ret.push_back({pm1, max(tt1 - tt2, 0)});
            it1 += 1, it2 += 1;
        }
        else if(pm1 < pm2){
            ret.push_back({pm1, tt1}), it1 += 1;
        }
        else{
            it2 += 1;
        }
    }
    while(it1 < n1){
        int pm1 = vec1[it1].prime, tt1 = vec1[it1].tot;
        ret.push_back({pm1, tt1}), it1 += 1;
    }
    return ret;
}

ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1) ret *= base, ret %= MOD;
        base *= base, base %= MOD;
        index >>= 1;
    }
    return ret;
}

vector<item> dfs(int now, int fm){
    vector<item> ret;
    for(auto &iter : edges[now]){
        int nto = iter.to, nx = iter.x, ny = iter.y;
        if(nto != fm){
            auto tmp = dfs(nto, now);
            tmp = insert(tmp, Prime_Factorization(nx));
            tmp = remove(tmp, Prime_Factorization(ny));
            ret = merge(ret, tmp);
        }
    }
    return ret;
}

void dfs2(int now, int fm, ll res){
    ans += res, ans %= MOD;
    for(auto &iter : edges[now]){
        int nto = iter.to, nx = iter.x, ny = iter.y;
        if(nto != fm){
            ll tmpv = res * ny % MOD;
            tmpv = tmpv * quickpow(nx, MOD - 2) % MOD;
            dfs2(nto, now, tmpv);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        pm_res.clear(), Eratothenes(ceil(sqrt(n * 1.0f)));
        for (int i = 1; i < n; i++){
            int nfm, nto, nx, ny;
            cin >> nfm >> nto >> nx >> ny;
            edges[nfm].push_back({nto, nx, ny});
            edges[nto].push_back({nfm, ny, nx});
        }
        auto res = dfs(1, -1);

        ll rt = 1;
        for(auto &it : res)
            rt *= quickpow(it.prime, it.tot), rt %= MOD;

        dfs2(1, -1, rt);
        cout << ans << "\n";
        ans = 0;
        for (int i = 1; i <= n; i++){
            edges[i].clear(), prime[i] = 0;
        }
    }
    return 0;
}