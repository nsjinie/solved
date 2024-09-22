#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    long a, b, x = 1;
    cin >> a >> b;

    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
            x = i;
    }
    cout << x << '\n';
    cout << a * b / x << '\n';
    return 0;
}