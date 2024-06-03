// 문제 : 10773 제로
//       https://www.acmicpc.net/problem/10773
// 시간 복잡도 : O(K)
// 알고리즘 : 자료구조, Stack
// 풀이 방향 :

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int k, tmp;
    stack<int> S;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        if (tmp == 0)
            S.pop();
        else
            S.push(tmp);
    }

    int res = 0;
    while (!S.empty())
    {
        res += S.top();
        S.pop();
    }

    cout << res;

    return 0;
}