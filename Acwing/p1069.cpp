#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef __int128 ll;

ll s[maxn];
int n;
ll f[maxn][maxn];

inline __int128 read(){
    __int128 x = 0,f = 1;
    char ch = getchar();
    while(ch < '0'||ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0'&&ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        s[i] = read();
        s[i + n] = s[i];
    }

    memset(f, 0x3f, sizeof f);

    for (int len = 1; len <= n; len++){
        for (int i = 1; i + len - 1 <= 2 * n; i++){
            int l = i, r = len + i - 1;
            if(len<=2)
                f[l][r] = 0;
            else if(len==3)
                f[l][r] = s[l] * s[l + 1] * s[l + 2];
            else
                for(int k=l;k<=r;k++){
                    f[l][r] = min(f[l][r], f[l][k] + f[k][r] + s[l] * s[k] * s[r]);
                }
        }
    }
    ll u = 1e31;
    for (int i = 1; i <= n; i++)
        u = min(u, f[i][i + n - 1]);
    print(u);

    return 0;
}