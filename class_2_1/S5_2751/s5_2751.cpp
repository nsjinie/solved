// 시간 복잡도 : O(NlogN)
// 알고리즘 : 정렬

#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }

    return 0;
}