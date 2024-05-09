#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int n, a, max, min;
    cin >> n >> a;
    max = min = a;

    for (int i = 1; i < n; i++)
    {
        cin >> a;
        if (a > max)
            max = a;
        else if (a < min)
            min = a;
    }

    cout << min << " " << max;

    return 0;
}