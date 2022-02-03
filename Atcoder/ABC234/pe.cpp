#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
vector<ll> v;
void init(){
    for (int head = 1; head <= 9; head++){
        for (int cd = -9; cd <= 9; cd++){
            ll now = 0, nowc = head - cd;
            for (int l = 1; l <= 18; l++){
                nowc += cd;
                if(0 <= nowc && nowc <= 9){
                    now *= 10;
                    now += nowc;
                    v.push_back(now);
                }
                else
                    break;
            }
        }
    }
    sort(v.begin(), v.end());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    ll n;
    while(cin>>n){
        cout << (*lower_bound(v.begin(), v.end(), n)) << endl;
    }

    return 0;
}