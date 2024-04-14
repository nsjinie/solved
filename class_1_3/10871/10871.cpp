#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "rt", stdin);
    int n, lt, a;
    cin >> n >> lt;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a < lt)
            cout << a << " ";
    }
    return 0;
}