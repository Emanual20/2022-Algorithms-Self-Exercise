#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll t, ans;
ll f(ll x){
    return x * x + 2 * x + 3;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    cout << f(f(f(t) + t) + f(f(t))) << endl;

    return 0;
}