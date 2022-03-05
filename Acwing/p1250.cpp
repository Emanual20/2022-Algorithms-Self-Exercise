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
const int maxn = 5e4 + 10;

int f[maxn], sz[maxn], n, m;
// remember to call dsu_init
void dsu_init(){
    for (int i = 1; i <= n * n; i++)
        f[i] = i, sz[i] = 1;
}
int find(int k){
    if(f[k] == k)
        return k;
    return f[k] = find(f[k]);
}

void merge(int dst, int src){
    int ds = find(dst), sr = find(src);
    f[sr] = ds;
    if(ds != sr) sz[ds] += sz[sr];
}

int trans(int x, int y){
    return (x - 1) * n + y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    dsu_init();
    for (int i = 1; i <= m; i++){
        int x1, y1, x2, y2; char ch;
        cin >> x1 >> y1 >> ch;
        x2 = x1, y2 = y1;
        
        if(ch == 'D')
            x2++;
        else
            y2++;

        int hash1 = trans(x1, y1), hash2 = trans(x2, y2);
        if(find(hash1) == find(hash2)){
            cout << i << endl;
            return 0;
        }
        merge(hash1, hash2);
    }
    cout << "draw" << endl;
    return 0;
}