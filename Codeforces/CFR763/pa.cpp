#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, rb, cb, rd, cd;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> rb >> cb >> rd >> cd;
		int i = 0, x = rb, y = cb, dx = 1, dy = 1;
		if (dx == 1 && x == n) dx = -dx;
		if (dy == 1 && y == m) dy = -dy;
		for (i = 0; ; i++) {
			if (x == rd || y == cd) {
				break;
			}
			x = x + dx;
			y = y + dy;
			if ((dx == -1 && x == 1) || (dx == 1 && x == n)) dx = -dx;
			if ((dy == -1 && y == 1) || (dy == 1 && y == m)) dy = -dy;
		}
		cout << i << endl;
	}

	return 0;
}