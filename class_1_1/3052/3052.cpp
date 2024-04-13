#include <iostream>
using namespace std;

int arr[42];
int main()
{
    // freopen("input.txt", "rt", stdin);
    int a, res = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> a;
        arr[a % 42]++;
    }
    for (int i = 0; i < 42; i++)
    {
        if (arr[i] != 0)
            res++;
    }

    cout << res;

    return 0;
}