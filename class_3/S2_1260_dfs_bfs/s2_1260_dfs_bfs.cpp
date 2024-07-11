// 문제 : 1260 DFS와 BFS
//       https://www.acmicpc.net/problem/1260
// 시간 복잡도 : O()
// 알고리즘 : DFS BFS
// 풀이 방향 :
//     방문할수 있는 정점이 여러개인 경우 작은것을 먼저 방문하고 -> 인접행렬로 구현
//     간선은 양방향이다 -> a b에 간선이 있으면 a -> b로 갈수 있고 b -> a로 갈수 있음을 입력

#include <iostream>
#include <queue>
using namespace std;

int N, M, V;

int map[1001][1001];
int ch[1001];

void DFS(int v)
{

    for (int i = 1; i <= N; i++)
    {
        if (map[v][i] == 1 && ch[i] == 0)
        {
            cout << i << " ";
            ch[i] = 1;
            DFS(i);
        }
    }
}

void init()
{
    for (int i = 1; i <= 1000; i++)
    {
        ch[i] = 0;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);

    cin >> N >> M >> V;

    int a, b;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    ch[V] = 1;
    cout << V << " ";
    DFS(V);
    cout << '\n';

    init();

    queue<int> Q;
    Q.push(V);
    ch[V] = 1;
    cout << V << " ";

    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int i = 1; i <= N; i++)
        {
            if (map[v][i] == 1 && ch[i] == 0)
            {
                cout << i << " ";
                ch[i] = 1;
                Q.push(i);
            }
        }
    }

    return 0;
}