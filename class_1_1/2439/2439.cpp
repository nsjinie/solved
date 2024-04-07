#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > 0; j--)
        {
            if (j > i)
                cout << " ";
            else
                cout << "*";
        }
        cout << endl;
    }
    return 0;
}