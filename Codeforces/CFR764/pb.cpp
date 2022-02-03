#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--){
        cin >> a >> b >> c;
        ll a1 = 2 * b - c, b1 = b, c1 = c;
        if(a1 / a * a == a1 && a1 / a >= 1){
            cout << "YES" << endl;
            continue;
        }
        ll a2 = a, b2 = b, c2 = 2 * b - a;
        if(c2 / c * c == c2 && c2 / c >= 1){
            cout << "YES" << endl;
            continue;
        }
        ll b3 = (a + c) / 2;
        if((a + c) % 2 == 0 && b3 / b * b == b3 && b3 / b >= 1){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }

    return 0;
}