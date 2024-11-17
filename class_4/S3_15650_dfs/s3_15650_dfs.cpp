// 문제 : 15650 N과 M(2)
//       https://www.acmicpc.net/problem/15650
// 풀이 결과 : [2]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//
// 시간 복잡도 : O()
// 알고리즘 : dfs (백트래킹), 조합
// 풀이 방향 :
//    1.

#include <iostream>

using namespace std;

int arr[9];
bool check[9];

int N, M;

void dfs(int num, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = num; i <= N; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
            check[i] = false;
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;

    dfs(1, 0);

    return 0;
}