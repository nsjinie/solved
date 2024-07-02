// 문제 : 11659
//       https://www.acmicpc.net/problem/11659
// 시간 복잡도 :
// 알고리즘 : 슬라이딩 윈도우
// 풀이 방향 : 데이터 입력시 누적합을 구한다

#include <iostream>
using namespace std;

int arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);
    int N, M;

    cin >> N >> M;

    int tmp;
    arr[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        arr[i] = tmp + arr[i - 1];
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << arr[b] - arr[a - 1] << '\n';
    }

    return 0;
}