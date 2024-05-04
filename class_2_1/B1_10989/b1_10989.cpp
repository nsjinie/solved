// 시간 복잡도 : O(n)

#include <iostream>
using namespace std;
int arr[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr[a]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (arr[i] != 0)
        {
            for (int j = 0; j < arr[i]; j++)
            {
                cout << i << '\n';
            }
        }
    }

    return 0;
}