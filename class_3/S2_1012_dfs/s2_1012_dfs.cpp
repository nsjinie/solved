// 문제 : 1012 유기농 배추
//        https://www.acmicpc.net/problem/1012
// 시간 복잡도 :
// 알고리즘 : DFS
// 풀이 방향 :
// 2차원 배열 초기화 문법 숙지
// DFS로 상하좌우에 1로 표시된 배열 값을 0으로 만들기

#include <iostream>

using namespace std;

int M, N, K;

int arr[51][51];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void DFS(int y, int x)
{
    arr[y][x] = 0;
    int xx, yy;
    for (int i = 0; i < 4; i++)
    {
        xx = x + dx[i];
        yy = y + dy[i];
        if (arr[yy][xx] == 1 && xx >= 0 && xx < M && yy >= 0 && yy < N)
            DFS(yy, xx);
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        cin >> M >> N >> K;
        // fill(&arr[0][0], &arr[51][51], 0);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                arr[i][j] = 0;
            }

        int x, y;
        for (int i = 0; i < K; i++)
        {
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int res = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] == 1)
                {
                    DFS(i, j);
                    res++;
                }
            }

        cout << res << '\n';
    }

    return 0;
}