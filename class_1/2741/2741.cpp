#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << i << "\n";
    }
    return 0;
}