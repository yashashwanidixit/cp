#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<long double> a(1000001);
    a[0] = 0;
    long double dp_sum = 0;
    for (int i = 1; i <= 1000000; i++)
    {

        a[i] = 1 + (dp_sum) / i;
        dp_sum += a[i];
    }
    while (t--)
    {
        int x;
        cin >> x;
        cout << (int)a[x] << endl;
    }
}