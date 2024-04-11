#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);

    int n, a;
    string str;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> str;
        for (int j = 0; j < str.length(); j++)
            for (int k = 0; k < a; k++)
            {
                cout << str[j];
            }
        cout << endl;
    }

    return 0;
}