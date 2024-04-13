#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);

    int n, a, res;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        a = 0;
        res = 0;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == 'O')
            {
                a++;
                res += a;
            }
            else
            {
                a = 0;
            }
        }
        cout << res << '\n';
    }
    return 0;
}