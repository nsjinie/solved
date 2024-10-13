// 문제 : 1697 숨바꼭질
//       https://www.acmicpc.net/problem/1697
// 풀이 결과 : [1]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//
// 시간 복잡도 : O(N)
// 알고리즘 : BFS
// 풀이 방향 :
//    1. X == K 가 같아 질때까지 루프문 순회
//    2. 각 노드에서 3가지 경우의 수를 비교 & K와 일치하지 않으면 Q에 push
//    3. 노드 방문 여부를 관리하는 배열 필요

#include <iostream>
#include <queue>

using namespace std;

int visit[1000001];

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> Q;

    Q.push(make_pair(N, 0));

    int X = N;
    while (!Q.empty())
    {
        X = Q.front().first;
        int sec = Q.front().second;
        Q.pop();

        if (X == K)
        {
            cout << sec;
            break;
        }

        if (visit[X - 1] == 0 && X - 1 >= 0)
        {
            visit[X - 1] = 1;
            Q.push(make_pair(X - 1, sec + 1));
        }
        if (visit[X + 1] == 0 && X + 1 <= 100000)
        {
            visit[X + 1] = 1;
            Q.push(make_pair(X + 1, sec + 1));
        }
        if (visit[X * 2] == 0 && X * 2 <= 100000)
        {
            Q.push(make_pair(X * 2, sec + 1));
        }
    }

    return 0;
}
