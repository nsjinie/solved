// 문제 : 7576 토마토
//       https://www.acmicpc.net/problem/7576
// 풀이 결과 : [1]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//
// 시간 복잡도 : O(4NM)
// 알고리즘 : BFS
// 풀이 방향 :
//    1. BFS 기본문제

#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
int dm[4] = {0, 1, 0, -1};
int dn[4] = {-1, 0, 1, 0};

struct Pos
{
    int m;
    int n;
    Pos(int a, int b)
    {
        m = a;
        n = b;
    }
};

int main()
{
    freopen("input.txt", "rt", stdin);

    int M, N;
    cin >> M >> N;
    queue<Pos> Q;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                Q.push(Pos(j, i));
            }
        }

    int day = 0;
    while (!Q.empty())
    {
        int size = Q.size();
        for (int i = 0; i < size; i++)
        {
            Pos tmp = Q.front();
            Q.pop();
            for (int j = 0; j < 4; j++)
            {
                int mm = tmp.m + dm[j];
                int nn = tmp.n + dn[j];
                if (mm >= 0 && mm < M && nn >= 0 && nn < N && arr[nn][mm] == 0)
                {
                    Q.push(Pos(mm, nn));
                    arr[nn][mm] = 1;
                }
            }
        }

        if (!Q.empty())
        {
            day++;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }
        }

    cout << day;

    return 0;
}