// 문제 : 2178 미로 탐색
//       https://www.acmicpc.net/problem/2178
// 풀이 결과 : [1]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       참조 url :
// 시간 복잡도 : O(NxM)
// 알고리즘 : BFS
// 풀이 방향 :
//        1. 현재 위치와 지나온 거리를 갖는 구조체 선언
//        2. 지나온 길은 갈수 없는 길(0)로 설정
//        3. BFS로 모든 경로를 탐색하며 목적지에 도착하면 최소 경로를 비교

#include <iostream>
#include <string>
#include <queue>
#include <climits>
using namespace std;

struct Path
{
    int x;
    int y;
    int m_cnt;

    Path(int a, int b, int c)
    {
        x = a;
        y = b;
        m_cnt = c;
    }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int arr[101][101];

main()
{
    freopen("input.txt", "rt", stdin);

    queue<Path> Q;

    int N, M;
    cin >> N >> M;

    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    Q.push(Path(0, 0, 1));
    arr[0][0] = 0;

    int res = INT_MAX;

    while (!Q.empty())
    {
        Path tmp = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = tmp.x + dx[i];
            int yy = tmp.y + dy[i];
            int cnt = tmp.m_cnt + 1;

            if (xx >= 0 && yy >= 0 && xx < M && yy < N && arr[yy][xx] == 1)
            {
                arr[yy][xx] = 0;
                if (xx == M - 1 && yy == N - 1 && cnt < res)
                {
                    res = cnt;
                }
                else
                {
                    Q.push(Path(xx, yy, cnt));
                }
            }
        }
    }

    cout << res;

    return 0;
}