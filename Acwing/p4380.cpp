#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], m, n;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int i = 1, j = 1, k = 0, sum_a = a[0], sum_b = b[0];
    while(i < n && j < m)
    {
        if(sum_a > sum_b)
            sum_b += b[j++];
        else if(sum_a < sum_b)
            sum_a += a[i++];
        else
        {
            k++;
            sum_a = a[i++];
            sum_b = b[j++];
        }
    }
    k++;
    cout << k << endl;
    return 0;
}