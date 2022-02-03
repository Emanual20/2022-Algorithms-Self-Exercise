#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x7fffffff;
int n;
struct line {
	int index;
	int used;
	int l;
	int r;
	int type;
};
typedef pair<line, int> pli;
vector<line> vl;
vector<pli> vtmp;
bool comp(pli pli1, pli pli2) {
	return pli1.second < pli2.second;
}
void dfs(int left, int right) {
	if (left == right) {
		cout << left << " " << right << " " << left << endl;
		return;
	}

	vtmp.clear();
	for (int i = 0; i < vl.size(); i++) {
		if (!vl[i].used && vl[i].l == left && vl[i].r != right) {
			vl[i].type = 1;
			vtmp.push_back(make_pair(vl[i], vl[i].r));
		}
		else if (!vl[i].used && vl[i].l != left && vl[i].r == right) {
			vl[i].type = 2;
			vtmp.push_back(make_pair(vl[i], vl[i].l));
		}
	}

	line vll, vlr; 
	vll.index = -1; vll.used = 0; vll.l = -inf; vll.r = left - 1; vll.type = 1; vtmp.push_back(make_pair(vll, left - 1));
	vlr.index = -1; vlr.used = 0; vlr.l = right + 1; vlr.r = inf; vlr.type = 2; vtmp.push_back(make_pair(vlr, right + 1));

	sort(vtmp.begin(), vtmp.end(), comp);
	int index = -1;
	for (int i = 0; i < vtmp.size() - 1; i++) {
		if (vtmp[i].second - vtmp[i + 1].second == -2 && vtmp[i].first.type != vtmp[i+1].first.type) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "SHIT" << endl;
	}
	int mid = (vtmp[index].second + vtmp[index + 1].second) / 2;
	cout << left << " " << right << " " << mid << endl;
	if (vtmp[index].first.index != -1) vl[vtmp[index].first.index].used = 1;
	if (vtmp[index + 1].first.index != -1) vl[vtmp[index + 1].first.index].used = 1;
	if (left <= mid - 1) {	
		dfs(left, mid - 1);
	}
	if (mid + 1 <= right) {
		dfs(mid + 1, right);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int	T;
	cin >> T;
	while (T--) {
		cin >> n;
		vl.clear();
		for (int i = 0; i < n; i++) {
			line myline; cin >> myline.l >> myline.r;
			myline.used = false; myline.type = 0; myline.index = i;
			if (myline.l == 1 && myline.r == n) myline.used = true;
			vl.push_back(myline);
		}

		dfs(1, n);
	}

	return 0;
}