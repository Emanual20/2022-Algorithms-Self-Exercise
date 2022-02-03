#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll n, a[maxn], b[maxn], sum = 0;
bool check(ll x) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	
	for (int i = n - 1; i >= 2; i--) {
		if (b[i] < x) return false;
		ll res = min(a[i] / 3, (b[i] - x) / 3);
		b[i] -= res * 3;
		b[i - 1] += res;
		b[i - 2] += res * 2;
	}

	return b[0] >= x && b[1] >= x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		ll left = 0, right = sum;
		while (left <= right) {
			ll mid = (left + right) / 2;
			if (!check(mid)) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		cout << left - 1 << endl;
	}

	return 0;
}