// 문제 : 10026 적록색약
//       https://www.acmicpc.net/problem/10026
// 풀이 결과 : [1]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//
// 시간 복잡도 : O(??)
// 알고리즘 : BFS
// 풀이 방향 :
//    1. BFS 기본문제

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int arr[101][101];
int visit[101][101];

int dj[4] = {0, 1, 0, -1};
int di[4] = {-1, 0, 1, 0};

int N;

int BFS(int type)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            visit[i][j] = 0;
        }

    queue<pair<int, int>> Q;
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j] == 0)
            {
                Q.push(make_pair(i, j));
                visit[i][j] = 1;
                int color = arr[i][j];
                while (!Q.empty())
                {
                    pair tmp = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int ii = tmp.first + di[k];
                        int jj = tmp.second + dj[k];
                        if (ii >= 0 && ii < N && jj >= 0 && jj < N && visit[ii][jj] == 0)
                        {
                            if (type == 1) // 정상
                            {
                                if (arr[ii][jj] == color)
                                {
                                    Q.push(make_pair(ii, jj));
                                    visit[ii][jj] = 1;
                                }
                            }
                            else if (type == 2) // 색약
                            {
                                if (color == 'B' && arr[ii][jj] == color)
                                {
                                    Q.push(make_pair(ii, jj));
                                    visit[ii][jj] = 1;
                                }
                                else if (color != 'B' && (arr[ii][jj] == 'R' || arr[ii][jj] == 'G'))
                                {
                                    Q.push(make_pair(ii, jj));
                                    visit[ii][jj] = 1;
                                }
                            }
                        }
                    }
                }
                cnt++;
            }
        }

    return cnt;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> N;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            arr[i][j] = str[j];
        }
    }

    cout << BFS(1) << '\n';
    cout << BFS(2);

    return 0;
}
