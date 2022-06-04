/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-21
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

const int maxn = 2e6 + 10;
int t, n, tot = 0;
string a[maxn];

struct item{
    string s;
    int idx;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    queue<item> q;
    q.push({"", 0});
    while(!q.empty()){
        auto now = q.front();
        string nows = now.s;
        int nidx = now.idx;
        a[nidx] = nows;
        if(tot < 1920000)
            for (char i = 'A'; i <= 'Z'; i++){
                auto tmps = nows + i;
                tot += 1;
                if(tot < 1920000){
                    q.push({tmps, tot});
                }
                else
                    break;
            }
        q.pop();
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << a[n] << "\n";
    }
    return 0;
}