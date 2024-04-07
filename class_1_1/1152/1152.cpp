#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    string s;
    int wordCnt = 1;
    getline(cin, s);

    if (s.length() == 1 && s[0] == ' ')
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] == ' ')
            wordCnt++;
    }

    cout << wordCnt;
    return 0;
}