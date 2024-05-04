// 시간복잡도 : O(NlogN)

#include <iostream>
#include <algorithm>
using namespace std;

string arr[20001];

int cmp(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main()
{
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, cmp);

    cout << arr[0] << '\n';
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] != arr[i])
            cout << arr[i] << '\n';
    }

    return 0;
}