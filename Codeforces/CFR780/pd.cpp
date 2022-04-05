/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, a[maxn];

struct item{
    int left, right;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        a[n + 1] = 0;

        int last = 1, maxi = -1, index = -1;
        item ans = {-1, -1};

        for (int i = 1; i <= n + 1; i++){
            if(a[i] == 0){
                int minus_tot = 0, calc2_tot = 0;
                item now_ans;
                for (int j = last; j < i; j++){
                    minus_tot += (a[j] < 0);
                    calc2_tot += (a[j] == 2 || a[j] == -2);
                }

                if(minus_tot % 2 != 0){
                    int calc2_tot1 = 0;
                    item ans_tmp1;
                    for (int j = last; j < i; j++){
                        calc2_tot1 += (a[j] == 2 || a[j] == -2);
                        if(a[j] < 0){
                            ans_tmp1 = {j, n - i + 1};
                            break;
                        }
                    }

                    int calc2_tot2 = 0;
                    item ans_tmp2;
                    for (int j = i - 1; j >= last; j--){
                        calc2_tot2 += (a[j] == 2 || a[j] == -2);
                        if(a[j] < 0){
                            ans_tmp2 = {last - 1, n - j + 1};
                            break;
                        }
                    }

                    if(calc2_tot1 < calc2_tot2){
                        now_ans = ans_tmp1;
                    }
                    else
                        now_ans = ans_tmp2;
                    calc2_tot = calc2_tot - min(calc2_tot1, calc2_tot2);
                }
                else{
                    now_ans = {last - 1, n - i + 1};
                }

                if(i != last && calc2_tot > maxi){
                    maxi = calc2_tot, index = last;
                    ans = now_ans;
                }

                last = i + 1;
            }
        }

        if(index == -1){
            cout << 0 << " " << n << endl;
        }
        else{
            cout << ans.left << " " << ans.right << endl;
        }
    }
    return 0;
}