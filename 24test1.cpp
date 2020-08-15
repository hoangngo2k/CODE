#include <bits/stdc++.h>
using namespace std;
int n, k, a[10000], X[10000];
bool check1 = false;
void Display()
{
    vector<int> ans;
    //ans.clear();
    for (int i = 0; i < n; i++)
    {
        if (X[i] == 1)
        {
            ans.push_back(a[i]);
        }
    }
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << ans[ans.size() - 1] << "] ";
}
void check()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (X[i] == 1)
        {
            sum += a[i];
        }
    }
    if (sum == k)
        check1 = true;
    if (sum == k)
        Display();
}
void Try(int i)
{
    for (int j = 1; j >= 0; j--)
    {
        X[i] = j;
        if (i == n - 1)
        {
            check();
        }
        else
        {
            Try(i + 1);
        }
    }
}
void Solve()
{
    for (int i = 0; i < 10000; i++)
    {
        // for(int j=0;j<10000;j++){
        a[i] = 0;
        X[i] = 0;
        // }
    }
    check1 = false;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    Try(0);
    if (!check1)
        cout << "-1";
    cout << endl;
}

int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        Solve();
    }
    return 0;
}
