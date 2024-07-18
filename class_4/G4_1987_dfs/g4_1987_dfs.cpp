// 문제 : 1987 알파벳
//       https://www.acmicpc.net/problem/1987
// 시간 복잡도 : O()
// 알고리즘 : DFS
// 풀이 방향 : visited 배열 check 하는 부분 주의

char arr[22][22];
int visited[27];

int R, C;
int result = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

#include <iostream>
#include <string>
using namespace std;

void DFS(int x, int y, int cnt)
{

    cnt++;

    if (result < cnt)
    {
        result = cnt;
    }

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (arr[yy][xx] != 0 && visited[arr[yy][xx] - 'A'] != 1)
        {
            visited[arr[yy][xx] - 'A'] = 1;
            DFS(xx, yy, cnt);
            visited[arr[yy][xx] - 'A'] = 0;
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);

    cin >> R >> C;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            cin >> arr[i][j];
        }

    visited[arr[1][1] - 'A'] = 1;
    DFS(1, 1, 0);

    cout << result;

    return 0;
}