// N^3 = 1,000,000

#include <iostream>
using namespace std;

int arr[100];

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, m, max = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
            {
                int tmp = arr[i] + arr[j] + arr[k];
                if (m >= tmp && max < tmp)
                {
                    max = tmp;
                }
            }

    cout << max;

    return 0;
}