#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    string str;
    while (true)
    {
        cin >> str;
        int len = str.length();
        if (str == "0")
            break;
        int start = 0, end = len - 1;
        bool isSame = true;
        for (int i = 0; i < len / 2; i++)
        {
            if (str[start] != str[end])
            {
                isSame = false;
                break;
            }
            start++;
            end--;
        }
        if (isSame)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}