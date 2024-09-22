#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int n, sum = 0;
    string str;
    cin >> n >> str;

    for (int i = 0; i < n; i++)
    {
        sum += str[i] - 48;
    }

    cout << sum;

    return 0;
}