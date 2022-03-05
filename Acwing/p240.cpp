/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
int f[maxn], dis[maxn], n, m;

// remember to call dsu_init
void dsu_init(){
    for (int i = 1; i <= n; i++)
        f[i] = i, dis[i] = 0;
}
int find(int k){
    if(f[k] == k) return k;
    int ori_fat = find(f[k]);
    dis[k] = dis[k] + dis[f[k]];
    return f[k] = ori_fat;
}

bool isvalid(int x){
    return x <= n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    dsu_init();

    int ans = 0;
    while(m--){
        int type, x, y;
        cin >> type >> x >> y;
        if(!isvalid(x) || !isvalid(y)){
            ans++;
            continue;
        }
        
        int px = find(x), py = find(y);
        if(type == 1){
            if(px != py){
                dis[find(x)] = dis[y] - dis[x];
                // i don't know why here must be f[px], but cannot be f[find(x)]
                f[px] = find(y);
            }
            else{
                if((dis[x] - dis[y]) % 3 != 0){
                    ans++;
                }
            }
        }
        else if(type == 2){
            if(x == y){
                ans++;
                continue;
            }

            if(px != py){
                dis[find(x)] = dis[y] - dis[x] + 1;
                // i don't know why here must be f[px], but cannot be f[find(x)]
                f[px] = find(y);
            }
            else{
                if((dis[x] - dis[y] - 1) % 3 != 0){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}