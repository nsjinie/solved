// 문제 : 1966
//       https://www.acmicpc.net/problem/1966
// 시간 복잡도 : O()
// 알고리즘 : queue
// 풀이 방향 : priority_queue를 사용 우선순위가 가장 높은 값을 쉽게 찾는다.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int T, N, M;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;

        queue<pair<int, int>> Q; // 가중치, Q에서의 위치
        priority_queue<int> pQ;
        int a;
        for (int j = 0; j < N; j++)
        {
            cin >> a;
            Q.push(make_pair(a, j));
            pQ.push(a);
        }

        int res = 0;
        while (!Q.empty())
        {
            int value = Q.front().first;
            int idx = Q.front().second;
            Q.pop();

            if (value == pQ.top())
            {
                pQ.pop();
                res++;
                if (idx == M)
                {
                    cout << res << '\n';
                    break;
                }
            }
            else
            {
                Q.push(make_pair(value, idx));
            }
        }
    }

    return 0;
}