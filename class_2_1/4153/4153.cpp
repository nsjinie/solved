#include <iostream>

using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    long int a, b, c, tmp;

    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            return 0;

        if (a > b)
        {
            tmp = a;
            a = b;
            b = tmp;
        }
        if (b > c)
        {
            tmp = c;
            c = b;
            b = tmp;
        }

        c *c == a *a + b *b ? cout << "right" << '\n' : cout << "wrong" << '\n';
    }

    return 0;
}