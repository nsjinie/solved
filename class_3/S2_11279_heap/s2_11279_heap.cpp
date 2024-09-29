// 문제 : 11279
//       https://www.acmicpc.net/problem/11279
// 시간 복잡도 : 삽입 O(log n) 제거 O(log n) 최상위 요소 확인 O(1)
// 알고리즘 : heap
// 풀이 방향 : priority_queue 사용
//

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    priority_queue<int> pQ;

    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            if (pQ.empty())
                cout << '0' << '\n';
            else
            {
                cout << pQ.top() << '\n';
                pQ.pop();
            }
        }
        else
        {
            pQ.push(tmp);
        }
    }

    return 0;
}
