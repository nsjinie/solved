// 시간복잡도 : N

#include <iostream>
using namespace std;

int arr[1001];

int main()
{
    freopen("input.txt", "rt", stdin);
    int n;
    double max = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += arr[i] / max * 100;
    }

    cout << res / n;

    return 0;
}