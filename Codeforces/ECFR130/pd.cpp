/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-13
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

const int maxn = 1e3 + 10;
int n, pre[maxn];
char s[maxn];

struct item{
    int pos;
    char ch;
};
vector<item> wd;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int last = 0;
    for (int i = 1; i <= n; i++){
        int tmp;
        cout << "? 2 1 " << i << endl;
        cin >> tmp;
        if(tmp != last){
            cout << "? 1 " << i << endl;
            cin >> s[i];
            last = tmp;
            pre[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++){
        pre[i] += pre[i - 1];
    }

    for (int i = 1; i <= n; i++){
        if(!s[i]){
            int l = 0, r = min((int)wd.size(), 26) - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                cout << "? 2 " << wd[mid].pos << " " << i << endl;
                int res;
                cin >> res;
                if(res == wd.size() - mid){
                    l = mid;
                }
                else
                    r = mid - 1;
            }
            s[i] = wd[l].ch, wd.push_back({i, wd[l].ch});
            wd.erase(wd.begin() + l);
        }
        else{
            wd.push_back({i, s[i]});
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}