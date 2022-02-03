/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e4 + 10;

int f[maxn], g[maxn], q[maxn], n, m;
// f for ith layer,g for i-1th layer, q for indexes of array f,g;
// deque won't pass...
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g,f,sizeof(f));
        for(int r = 0; r < v; r++){                                        // enumerate remainder
            int tt = -1, hh = 0;
            for(int j = r; j <= m; j+=v){
                while(hh<=tt&&q[hh]<j-s*v)
                    ++hh;                                                  // pop front
                while(hh<=tt&&g[q[tt]]-(q[tt]-r)/v*w<=g[j]-(j-r)/v*w)
                    --tt;                                                  // repeat pop back
                q[++tt] = j;                                               // push back
                f[j] = g[q[hh]] + (j - q[hh]) / v * w;                     // udpate ans
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}