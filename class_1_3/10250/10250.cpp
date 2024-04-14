#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int tc, h, w, n;

    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> h >> w >> n;
        if (n % h == 0)
            cout << (h * 100) + (n / h) << '\n';
        else
            cout << (n % h * 100) + (n / h + 1) << '\n';
    }
    return 0;
}