// 시간 복잡도 : O(N^2)
// 알고리즘 : 브루트포스

#include <iostream>
using namespace std;

pair<int, int> arr[50];
int res[50];

int main()
{
    freopen("input.txt", "rt", stdin);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
            {
                res[i]++;
            }
            else if (arr[i].first > arr[j].first && arr[i].second > arr[j].second)
            {
                res[j]++;
            }
        }

    for (int i = 0; i < n; i++)
        cout << res[i] + 1 << ' ';

    return 0;
}