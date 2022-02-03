#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
const int MAX = 2e5 + 5;
const int inf = 0x7fffffff;
struct Edge {
	int u,v;
	int w;
} e[MAX];
int n,m;
bool cmp(Edge a,Edge b) {
	return a.w > b.w;
}
int f[MAX];
int getf(int v) {
	return f[v] == v ? v : f[v] = getf(f[v]);
}
void merge(int u,int v) {
	int t1 = getf(u),t2 = getf(v);
	f[t2] = t1;
}
int main()
{
	int t;
	cin>>t;
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i = 1; i<=n; i++) f[i] = i;
		for(int a,b,i = 1; i<=m; i++) {
			int w;
			scanf("%d%d%d",&a,&b,&w);
            w = (~w) & inf;
            e[i].u = a;e[i].v = b;e[i].w = w;
		}
		sort(e+1,e+m+1,cmp);
		int ans = 1<<31;ans--;
		int no = ans;
		int cnt = 0;
		for(int i = 1; i<=m; i++) {
			if(getf(e[i].u) != getf(e[i].v)) {
				ans = ans & e[i].w;
				merge(e[i].u,e[i].v);
				cnt++;
			}
		}
		if(cnt != n-1)
            printf("0\n");
        else
            printf("%d\n", ((~ans) & inf));
    } 
 
	return 0;
}