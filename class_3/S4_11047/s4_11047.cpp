// 문제 : 11047
//       https://www.acmicpc.net/problem/7662
// 시간 복잡도 :
// 알고리즘 : 그리디
// 풀이 방향 : 큰 동전 부터 빼나가며 동전 수 카운트

#include <iostream>
using namespace std;

int arr[11];

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;
    for (int i = N; i >= 1; i--)
    {
        if (arr[i] > K)
            continue;

        while (K >= arr[i])
        {
            K -= arr[i];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}