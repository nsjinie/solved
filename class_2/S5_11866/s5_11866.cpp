// 문제 : 11651 좌표 정렬하기2
//       https://www.acmicpc.net/problem/11866
// 시간 복잡도 : O(N)
// 알고리즘 : 자료구조, Q
// 풀이 방향 : Q 사용법 숙지

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    for (int i = 1; i <= n; i++)
    {
        Q.push(i);
    }

    cout << '<';
    while (!Q.empty())
    {
        int tmp;
        for (int i = 0; i < k - 1; i++)
        {
            tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }
        tmp = Q.front();
        Q.pop();
        if (Q.empty())
            cout << tmp << '>';
        else
            cout << tmp << ", ";
    }
    return 0;
}