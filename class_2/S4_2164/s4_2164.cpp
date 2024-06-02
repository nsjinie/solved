// 문제 : 2164 카드2
//       https://www.acmicpc.net/problem/2164
// 시간 복잡도 : O(n)
// 알고리즘 : 큐
// 풀이 방향 : 문제에서 주어진 로직 구현

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;

    queue<int> Q;

    for (int i = 1; i <= n; i++)
    {
        Q.push(i);
    }

    int tmp;
    while (Q.size() != 1)
    {
        Q.pop();

        tmp = Q.front();
        Q.push(tmp);
        Q.pop();
    }

    cout << Q.front();

    return 0;
}