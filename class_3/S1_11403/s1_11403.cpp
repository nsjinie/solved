// 문제 : 11403 경로 찾기
//       https://www.acmicpc.net/problem/11403
// 풀이 결과 : [1]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)

// 시간 복잡도 : O(N^3)
// 알고리즘 : 플로이드워셜
// 풀이 방향 :
//    1. 플로이드워셜 알고리즘으로 연결 여부를 알 수 있다.

#include <iostream>

int arr[101][101];

using namespace std;
int main()
{
    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (arr[i][j] == 1 || (arr[i][k] + arr[k][j] == 2))
                {
                    arr[i][j] = 1;
                }
            }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
