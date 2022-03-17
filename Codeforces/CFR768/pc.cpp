/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t, n, k, vis[maxn];
int log2(int x){
    int ret = 0;
    while(x){
        ret++, x >>= 1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k == 0){
            for (int i = 0; i < n / 2; i++){
                cout << i << " " << n - 1 - i << "\n";
            }
        }
        else if(k == n - 1){
            if(n == 4){
                cout << -1 << "\n";
            }
            else{
                memset(vis, 0, sizeof(vis));
                int round = log2(k);
                // cout << "debugging" << round << endl;
                for (int i = 0; i < round; i++){
                    cout << (1 << i) << " " << ((n - 1) ^ (1 << (i + 1) % round)) << "\n";
                    vis[1 << i] = 1, vis[(n - 1) ^ (1 << (i + 1) % round)] = 1;
                }
                for (int i = 0; i < n / 2; i++){
                    if(!vis[i]){
                        cout << i << " " << n - 1 - i << "\n";
                    }
                }
            }
        }
        else{
            memset(vis, 0, sizeof(vis));
            cout << k << " " << n - 1 << "\n";
            cout << (n - 1 - k) << " " << 0 << "\n";
            vis[k] = 1, vis[n - 1 - k] = 1, vis[0] = 1, vis[n - 1] = 0;
            for (int i = 0; i < n / 2; i++){
                if(!vis[i]){
                    cout << i << " " << n - 1 - i << "\n";
                }
            }
        }
    }
    return 0;
}