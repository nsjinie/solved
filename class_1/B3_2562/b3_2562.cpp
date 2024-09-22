#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);

    int maxValue = 0, pos = 0, n;

    for (int i = 1; i <= 9; i++)
    {
        cin >> n;
        if (n > maxValue)
        {
            maxValue = n;
            pos = i;
        }
    }
    cout << maxValue << endl;
    cout << pos << endl;
    return 0;
}