#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);

    int a, b;
    string result;
    cin >> a;
    if (a == 1)
        result = "ascending";
    else if (a == 8)
        result = "descending";
    else
    {
        cout << "mixed" << '\n';
        return 0;
    }
    for (int i = 1; i < 8; i++)
    {
        cin >> b;
        if (result == "descending" && a < b || result == "ascending" && a > b)
        {
            cout << "mixed" << '\n';
            return 0;
        }
        a = b;
    }
    cout << result;
    return 0;
}