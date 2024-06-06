// 문제 : 30802 웰컴 키트
//       https://www.acmicpc.net/problem/30802
// 시간 복잡도 :
// 알고리즘 : 사착연산
// 풀이 방향 : 문제 내용을 이해하고 사칙연산 구현

#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, T, P;
    int arr[6];
    cin >> N;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    cin >> T >> P;

    int ansT = 0, ansP1 = 0, ansP2 = 0;

    for (int i = 0; i < 6; i++)
    {
        ansT += (arr[i] / T);
        if (arr[i] % T != 0)
            ansT += 1;
    }
    cout << ansT << '\n';

    ansP1 = N / P;
    ansP2 = N % P;

    cout << ansP1 << " " << ansP2;

    return 0;
}