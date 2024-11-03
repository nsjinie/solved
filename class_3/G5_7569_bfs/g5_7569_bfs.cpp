// 문제 : 7569 토마토
//       https://www.acmicpc.net/problem/7569
// 풀이 결과 : [1]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//
// 시간 복잡도 : O(??)
// 알고리즘 : bfs (3차원)
// 풀이 방향 :
//    1. 3차원 BFS 구현

#include <iostream>
#include <queue>

using namespace std;

struct Box
{
    int m;
    int n;
    int h;
    Box(int a, int b, int c)
    {
        h = a;
        n = b;
        m = c;
    }
};

int arr[101][101][101];

int dh[6] = {0, 0, 0, 0, 1, -1};
int dn[6] = {0, 1, 0, -1, 0, 0};
int dm[6] = {1, 0, -1, 0, 0, 0};

int main()
{
    freopen("input.txt", "rt", stdin);

    int M, N, H;
    cin >> M >> N >> H;

    queue<Box> Q;

    for (int h = 0; h < H; h++)
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++)
            {
                cin >> arr[h][n][m];
                if (arr[h][n][m] == 1)
                {
                    Q.push(Box(h, n, m));
                }
            }

    int day = 0;
    while (!Q.empty())
    {
        int qSize = Q.size();
        for (int i = 0; i < qSize; i++)
        {
            Box tmp = Q.front();
            Q.pop();
            for (int j = 0; j < 6; j++)
            {
                int hh = tmp.h + dh[j];
                int nn = tmp.n + dn[j];
                int mm = tmp.m + dm[j];
                if (mm >= 0 && mm < M && nn >= 0 && nn < N && hh >= 0 && hh < H && arr[hh][nn][mm] == 0)
                {
                    arr[hh][nn][mm] = 1;
                    Q.push(Box(hh, nn, mm));
                }
            }
        }
        if (!Q.empty())
        {
            day++;
        }
    }

    for (int h = 0; h < H; h++)
        for (int n = 0; n < N; n++)
            for (int m = 0; m < M; m++)
            {
                if (arr[h][n][m] == 0)
                {
                    cout << "-1";
                    return 0;
                }
            }

    cout << day;

    return 0;
}