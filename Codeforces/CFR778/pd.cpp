/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-19
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

const int maxn = 2e5 + 10;
int t, n, vis[maxn];

struct item{
    int to, x, y;
};
vector<item> edges[maxn];

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

vector<item> dfs(int now, int fm){
    vector<item> ret;
    for(auto &iter : edges[now]){
        int nto = iter.to, nx = iter.x, ny = iter.y;
        if(nto != fm){
            auto tmp = dfs(nto, now);
            merge(ret, tmp);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i < n; i++){
            int nfm, nto, nx, ny;
            cin >> nfm >> nto >> nx >> ny;
            edges[nfm].push_back({nto, nx, ny});
            edges[nto].push_back({nfm, ny, nx});
        }
        dfs(1, -1);
    }
}