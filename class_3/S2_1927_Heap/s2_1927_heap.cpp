// 문제 : 1927
//       https://www.acmicpc.net/problem/1927
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
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;
    priority_queue<int> pQ;

    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a == 0)
        {
            if (pQ.size() == 0)
            {
                cout << "0" << '\n';
            }
            else
            {
                cout << -(pQ.top()) << '\n';
                pQ.pop();
            }
        }
        else
        {
            pQ.push(-a);
        }
    }

    return 0;
}