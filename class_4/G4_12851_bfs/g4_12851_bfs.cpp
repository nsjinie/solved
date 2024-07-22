// 문제 : 12851 숨바꼭질 2
//       https://www.acmicpc.net/problem/12851
// 시간 복잡도 : O()
// 알고리즘 : BFS
// 풀이 방향
//              Q에 push 하는 조건을 잘 생각해 봐야 함
//              time이 오름차순으로 Q에 push 되기에 결과값을 찾은 시간보다 큰 시간일 때는 loop를 빠져나온다

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

queue<pair<int, int>> Q;

int N, K;
int result = INT_MAX;
int cnt = 0;
int visited[100001];

int main()
{
    freopen("input.txt", "rt", stdin);

    cin >> N >> K;

    Q.push(make_pair(N, 0));

    while (!Q.empty())
    {
        int pos = Q.front().first;
        int time = Q.front().second;
        visited[pos] = 1;
        Q.pop();

        if (result < time)
            break;

        if (pos == K)
        {
            result = time;
            cnt++;
            continue;
        }

        if (pos - 1 >= 0 && !visited[pos - 1])
        {
            Q.push(make_pair(pos - 1, time + 1));
        }
        if (pos + 1 <= 100000 && !visited[pos + 1])
        {
            Q.push(make_pair(pos + 1, time + 1));
        }
        if (pos * 2 <= 100000 && !visited[pos * 2])
        {
            Q.push(make_pair(pos * 2, time + 1));
        }
    }

    cout << result << '\n';
    cout << cnt << '\n';

    return 0;
}
