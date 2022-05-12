/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, m, a[maxn];

struct item{
    int h, tag;
};
vector<item> v[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 1; i < n; i++){
            cin >> a[i];
        }
        a[n] = 1e6 + 1;
        for (int i = 1; i <= m; i++){
            int nq, nh, ntag;
            cin >> nq >> nh >> ntag;
            v[nq].push_back({nh, ntag});
        }

        int ans = 0;
        for (int i = 1; i <= n; i++){
            int lbound = a[i - 1], rbound = a[i];
            vector<int> vec0, vec1;
            for(auto &it : v[i]){
                int nh = it.h, ntag = it.tag;
                if(!ntag)
                    vec0.push_back(nh);
                else
                    vec1.push_back(nh);
            }
            int tmp = vec0.size();
            sort(vec0.begin(), vec0.end());
            sort(vec1.begin(), vec1.end());
            for (int j = lbound; j <= rbound; j++){
                int pos0 = vec0.end() - lower_bound(vec0.begin(), vec0.end(), j);
                int pos1 = lower_bound(vec1.begin(), vec1.end(), j) - vec1.begin();
                tmp = max(tmp, pos0 + pos1);
            }
            ans += tmp;
        }

        cout << ans << endl;

        for (int i = 1; i <= n; i++){
            v[i].clear();
        }
    }
    return 0;
}