#include <iostream>

using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int n, a, npn = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
        {
            npn++;
            continue;
        }
        for (int j = 2; j < a; j++)
        {
            if (a % j == 0)
            {
                npn++;
                break;
            }
        }
    }

    cout << n - npn;
    return 0;
}