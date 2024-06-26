// 문제 : 11399
//       https://www.acmicpc.net/problem/11399
// 시간 복잡도 :
// 알고리즘 : 정렬, 그리디
// 풀이 방향 : -

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int a = 0;
        for (int j = 0; j <= i; j++)
        {
            a += arr[j];
        }
        sum += a;
    }
    cout << sum;

    return 0;
}