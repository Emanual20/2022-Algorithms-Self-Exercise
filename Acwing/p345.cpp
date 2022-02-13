#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int k, m, src, dst, n = 0;
map<int, int> trans;
struct matrix{
    int w[maxn][maxn];
}a;
void print_mat(matrix m){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << m.w[i][j] << " ";
        }
        cout << endl;
    }
}
matrix matrix_mul(matrix a, matrix b){
    matrix ret;
    memset(ret.w, 0x3f, sizeof(ret.w));
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                ret.w[i][j] = min(ret.w[i][j], a.w[i][k] + b.w[k][j]);
            }
        }
    }
    return ret;
}
matrix quickpow(matrix base, int index){
    matrix ret;
    memset(ret.w, 0x3f, sizeof(ret.w));
    for (int i = 1; i <= n; i++)
        ret.w[i][i] = 0;

    while(index){
        if(index & 1){
            ret = matrix_mul(ret, base);
        }
        base = matrix_mul(base, base);
        index >>= 1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> m >> src >> dst;
    if(!trans.count(src))
        trans[src] = ++n;
    if(!trans.count(dst))
        trans[dst] = ++n;
    src = trans[src], dst = trans[dst];

    memset(a.w, 0x3f, sizeof(a.w));
    for (int i = 0; i < m; i++){
        int w, fm, to;
        cin >> w >> fm >> to;
        if(!trans.count(fm))
            trans[fm] = ++n;
        if(!trans.count(to))
            trans[to] = ++n;
        fm = trans[fm], to = trans[to];
        a.w[fm][to] = a.w[to][fm] = min(a.w[fm][to], w);
    }

    a = quickpow(a, k);
    cout << a.w[src][dst] << endl;
    return 0;
}