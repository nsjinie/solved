#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, sum = 1, add = 0, result = 1;

    cin >> n;

    while (sum < n)
    {
        add = 6 * result;
        sum += add;
        result++;
    }

    cout << result;
    return 0;
}