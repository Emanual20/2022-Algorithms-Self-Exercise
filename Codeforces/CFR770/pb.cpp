/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int dxor[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
int dplus[4][4] = {{0, 1, 2, 3}, {1, 2, 3, 0}, {2, 3, 0, 1}, {3, 0, 1, 2}};
ll t, n, x, y, a[maxn];
int avis[4], bvis[4], avisg[4], bvisg[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        memset(avis, 0, sizeof(avis));
        memset(bvis, 0, sizeof(bvis));
        cin >> n >> x >> y;
        avis[x % 4] = 1, bvis[(x + 3) % 4] = 1;
        y %= 4;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            a[i] %= 4;
        }
        for (int i = 0; i < n; i++){
            memset(avisg, 0, sizeof(avisg));
            memset(bvisg, 0, sizeof(bvisg));
            for (int j = 0; j < 4; j++){
                if(avis[j]){
                    avisg[dxor[j][a[i]]] = 1;
                    avisg[dplus[j][a[i]]] = 1;
                }
                if(bvis[j]){
                    bvisg[dxor[j][a[i]]] = 1;
                    bvisg[dplus[j][a[i]]] = 1;
                }
            }
            memcpy(avis, avisg, sizeof(avis));
            memcpy(bvis, bvisg, sizeof(bvis));
        }
        if(avis[y]){
            cout << "Alice" << endl;
        }
        else
            cout << "Bob" << endl;
    }
}