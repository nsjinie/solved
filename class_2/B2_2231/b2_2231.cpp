#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        string str = to_string(i);
        int tmp = i;
        int sum = i;
        while (tmp != 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }

        if (sum == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}