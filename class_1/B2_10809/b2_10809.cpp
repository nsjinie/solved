#include <iostream>
using namespace std;

int abc[26];

int main()
{
    freopen("input.txt", "rt", stdin);
    for (int i = 0; i < 26; i++)
    {
        abc[i] = -1;
    }
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        int abcIdx = a[i] - 'a';
        if (abc[abcIdx] == -1)
            abc[abcIdx] = i;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << abc[i] << " ";
    }

    return 0;
}