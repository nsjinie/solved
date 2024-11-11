// 문제 : 16928 뱀과 사다리 게임
//       https://www.acmicpc.net/problem/10026
// 풀이 결과 : [2]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//            https://hagisilecoding.tistory.com/85
// 시간 복잡도 : O(??)
// 알고리즘 : BFS
// 풀이 방향 :
//    1. BFS로 최단거리 탐색
//    2. Map으로 사다리와 뱀 이동 경로 탐색 (문제 핵심)

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int check[101];

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, M;
    cin >> N >> M;

    queue<pair<int, int>> Q;
    unordered_map<int, int> Map;

    int a, b;
    for (int i = 0; i < N + M; i++)
    {
        cin >> a >> b;
        Map[a] = b;
    }

    Q.push({1, 0});
    while (!Q.empty())
    {
        pair tmp = Q.front();
        Q.pop();
        int pos = tmp.first;
        int cnt = tmp.second;
        for (int i = 1; i <= 6; i++)
        {
            int nPos = pos + i;

            if (nPos == 100)
            {
                cout << cnt + 1;
                return 0;
            }
            else if (nPos < 100)
            {
                while (Map[nPos] != 0) // 사다리,뱀 경로 탐색
                {
                    nPos = Map[nPos];
                }

                if (!check[nPos])
                {

                    Q.push({nPos, cnt + 1});
                    check[nPos] = 1;
                }
            }
        }
    }

    return 0;
}