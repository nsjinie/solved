// 문제 : 2667 단지번호붙이기
//       https://www.acmicpc.net/problem/2667
// 풀이 결과 : [1]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       참조 url :
// 시간 복잡도 : O(N^3)
// 알고리즘 : BFS
// 풀이 방향 :
//    1. NxN 을 순회하며 1을 만나면 BFS를 통해 연결된 집들을 모두 방문.
//    2. 집들을 방문할때는 '연결된 집 수 + 1'을 배열 값으로 입력함 (visit 배열을 따로 관리하지 않아도 됨)

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int arr[25][25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{

    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;
    string a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = a[j] - '0';
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] != 1)
                continue;

            cnt++;
            queue<pair<int, int>> Q;
            Q.push(make_pair(i, j));
            arr[i][j] = cnt + 1;

            while (!Q.empty())
            {
                pair pos = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int ii = pos.first + dy[k];
                    int jj = pos.second + dx[k];
                    if (ii >= 0 && ii < N && jj >= 0 && jj < N && arr[ii][jj] == 1)
                    {
                        arr[ii][jj] = cnt + 1;
                        Q.push(make_pair(ii, jj));
                    }
                }
            }
        }

    cout << cnt << '\n';

    vector<int> house(cnt);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] != 0)
            {
                house[arr[i][j] - 2]++;
            }
        }

    sort(house.begin(), house.end());

    for (int i = 0; i < house.size(); i++)
    {
        cout << house[i] << '\n';
    }

    return 0;
}
