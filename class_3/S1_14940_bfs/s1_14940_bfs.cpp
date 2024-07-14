// 문제 : 14940 쉬운 최단거리
//       https://www.acmicpc.net/problem/14940
// 시간 복잡도 : O()
// 알고리즘 : BFS
// 풀이 방향 :
//             데이터 입력시 출발점을 찾는다
//             Q에 push 할때 visited 체크
//             출력시 원데이터는 1이지만 결과가 0인 조건을 찾아 -1 출력

#include <iostream>
#include <queue>
using namespace std;

int map[1002][1002];
int result[1002][1002];
int visited[1002][1002];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

queue<pair<int, int>> Q;

void BFS(int x, int y)
{
    Q.push(make_pair(x, y));
    visited[y][x] = 1;

    while (!Q.empty())
    {
        int _x = Q.front().first;
        int _y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = _x + dx[i];
            int yy = _y + dy[i];
            if (map[yy][xx] == 1 && visited[yy][xx] == 0)
            {
                result[yy][xx] = result[_y][_x] + 1;
                Q.push(make_pair(xx, yy));
                visited[yy][xx] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                x = j;
                y = i;
            }
        }

    BFS(x, y);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (result[i][j] == 0 && map[i][j] == 1)
            {
                cout << "-1" << " ";
            }
            else
            {
                cout << result[i][j] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
