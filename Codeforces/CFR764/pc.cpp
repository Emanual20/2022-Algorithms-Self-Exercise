#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 51;
int a[maxn], vis[maxn], res[maxn];
int T, n;
int dict[maxn][maxn];
void init(){
    for (int i = 1; i < maxn; i++){
        int now = i;
        while(now){
            dict[i][now] = 1;
            now >>= 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    cin >> T;
    while(T--){
        memset(vis, 0, sizeof(vis));
        memset(res, 0, sizeof(res));
        int flag = 0;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            int now = a[i];
            while(now >= maxn){
                now /= 2;
            }
            res[i] = now;
            for (int j = 1; j < maxn; j++){
                vis[j] += dict[now][j];
            }
        }
        for (int i = n; i >= 1; i--){
            if(vis[i]){
                for (int j = 1; j < maxn; j++){
                    vis[j] -= dict[i][j];
                }
                if(i == 1)
                    flag = 1;
            }
            else{
                break;
            }
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}