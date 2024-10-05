// 문제 : 21736
//       https://www.acmicpc.net/problem/21736
// 시간 복잡도 : O (NlogN)
// 알고리즘 :
// 풀이 방향 :

#include <iostream>

using namespace std;

int N, M;

char arr[601][601];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int ans = 0;

void DFS(int x, int y)
{
    arr[y][x] = 'X';

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < M && yy >= 0 && yy < N && arr[yy][xx] != 'X')
        {
            if (arr[yy][xx] == 'P')
            {
                ans++;
            }
            DFS(xx, yy);
        }
    }
}

int main()
{

    freopen("input.txt", "rt", stdin);

    cin >> N >> M;

    int xx, yy;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
        {
            cin >> arr[y][x];
            if (arr[y][x] == 'I')
            {
                yy = y;
                xx = x;
            }
        }

    DFS(xx, yy);

    if (ans == 0)
        cout << "TT";
    else
        cout << ans;

    return 0;
}