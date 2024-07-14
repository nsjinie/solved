// 문제 : 11724 연결 요소의 개수
//       https://www.acmicpc.net/problem/11724
// 시간 복잡도 : O()
// 알고리즘 : DFS
// 풀이 방향 :
//             DFS로 방문한 node를 check하고
//             main 문에서 방문하지 않은 node가 없는지 확인한다

#include <iostream>
#include <vector>

using namespace std;

int N, M, u, v;

vector<int> map[1001];
int check[1001];

void DFS(int v)
{
    check[v] = 1;
    for (int i = 0; i < map[v].size(); i++)
    {
        if (check[map[v][i]] == 0)
        {
            DFS(map[v][i]);
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (check[i] == 0)
        {
            cnt++;
            DFS(i);
        }
    }

    cout << cnt;

    return 0;
}