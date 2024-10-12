// 문제 : 1389 케빈 베이컨의 6단계 법칙
//       https://www.acmicpc.net/problem/1389
// 풀이 결과 : [2]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//
// 시간 복잡도 : O(N^3)
// 알고리즘 : 플로이드워셜
// 풀이 방향 :
//    1. 모든 노드에서 모든 노드로 가는 최단거리를 구하는 플로이디워셜 알고리즘으로 구현
//    2. 인접배열 초기값 셋팅시 최대 인원수를 모두 거쳐 가는 값보다 큰값으로 설정

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dis(N + 1, vector<int>(N + 1, 200));

    for (int i = 1; i <= N; i++)
    {
        dis[i][i] = 0;
    }

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        dis[a][b] = 1;
        dis[b][a] = 1;
    }

    // 플로이드워셜
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }

    int res = 0, minValue = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            sum += dis[i][j];
        }
        if (sum < minValue)
        {
            res = i;
            minValue = sum;
        }
    }

    cout << res;

    return 0;
}
