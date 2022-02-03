#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll k;
stack<int> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    while(k > 0){
        k % 2 == 1 ? s.push(2) : s.push(0);
        k /= 2;
    }

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}