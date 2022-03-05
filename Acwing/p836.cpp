/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int f[maxn], sz[maxn], n, m;
// remember to call dsu_init
void dsu_init(){
    for (int i = 1; i <= n; i++)
        f[i] = i, sz[i] = 1;
}
int find(int k){
    if(f[k] == k)
        return k;
    return f[k] = find(f[k]);
}
void merge(int dst, int src){
    int ds = find(dst), sr = find(src);
    f[sr] = ds, sz[ds] += sz[sr];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    dsu_init();
    while(m--){
        char c;
        int fm, to;
        cin >> c >> fm >> to;
        if(c == 'M'){
            merge(fm, to);
        }
        else{
            cout << (find(fm) == find(to) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}