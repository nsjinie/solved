#include <iostream>
using namespace std;

int abc[26];

int main()
{
    freopen("input.txt", "rt", stdin);
    string a;
    cin >> a;
    int ascii;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'a')
            abc[a[i] - 'a']++;
        else
            abc[a[i] - 'A']++;
    }

    int max = 0;
    string ans;

    for (int i = 0; i < 26; i++)
    {
        if (abc[i] == max)
        {
            ans = '?';
        }
        else if (abc[i] > max)
        {
            max = abc[i];
            ans = 'A' + i;
        }
    }
    cout << ans;

    return 0;
}