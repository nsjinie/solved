// 문제 : 2805 나무 자르기
//        https://www.acmicpc.net/problem/2805
// 시간 복잡도 : O(LogN)
// 알고리즘 : 이분 검색
// 풀이 방향 :
//      1. 자료형 범위 확인
//      2. 이분 탐색 구현 실수 줄이기

#include <iostream>
using namespace std;

int N, M;
int arr[1000001];

long long cut(int mid)
{
    long long ret = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > mid)
            ret += (arr[i] - mid);
    }
    return ret;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    long long start = 0, end = 2000000000;
    long long mid;
    long long ans = 0;
    long long sum;

    while (start <= end)
    {
        mid = (start + end) / 2;
        sum = cut(mid);

        if (sum >= M)
        {
            if (ans < mid) // 나무를 최대한 자르지 않는 조건
            {
                ans = mid;
            }
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << ans;

    return 0;
}