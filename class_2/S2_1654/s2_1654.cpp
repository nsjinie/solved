// 문제 : 1654
//       https://www.acmicpc.net/problem/1654
// 시간 복잡도 :
// 알고리즘 : 이분탐색
// 풀이 방향 : lt = 0으로 초기조건을 잡으면 에러 발생.
//            lt, rt, mid 자료형 주의

#include <iostream>
using namespace std;

int arr[10001];

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, K;
    cin >> K >> N;

    long long lt = 1, rt = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> arr[i];

        if (rt < arr[i])
            rt = arr[i];
    }

    long long mid;
    int cnt, res = 0;
    while (lt <= rt)
    {
        mid = (lt + rt) / 2;
        cnt = 0;
        for (int i = 0; i < K; i++)
        {
            cnt += arr[i] / mid;
        }

        if (cnt >= N)
        {
            lt = mid + 1;
            res = mid;
        }
        else
        {
            rt = mid - 1;
        }
    }

    cout << res;

    return 0;
}
