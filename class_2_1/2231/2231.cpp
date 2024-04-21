#include <iostream>
#include <string>

using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);

    int n, result = 0;
    cin >> n;

    for (int i = n - 1; i > 0; i--)
    {
        string str = to_string(i);
        int tmp = i;
        for (int j = 0; j < str.length(); j++)
        {
            tmp += (str[j] - '0');
        }
        if (tmp == n)
        {
            result = i;
        }
    }

    cout << result;

    return 0;
}