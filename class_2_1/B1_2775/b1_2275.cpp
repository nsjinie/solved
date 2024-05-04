// 시간 복잡도 : k*n

#include <iostream>
using namespace std;

int arr[15][15];

int main()
{
    freopen("input.txt", "rt", stdin);

    int t, k, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k >> n;

        for (int j = 0; j <= k; j++)
        {
            for (int m = 1; m <= n; m++)
            {
                if (j == 0)
                {
                    arr[j][m] = m;
                }
                else if (m == 1)
                {
                    arr[j][1] = 1;
                }
                else
                {
                    arr[j][m] = arr[j][m - 1] + arr[j - 1][m];
                }

                // cout << arr[j][m] << " ";
            }
            // cout << '\n';
        }

        cout << arr[k][n] << '\n';
    }
}