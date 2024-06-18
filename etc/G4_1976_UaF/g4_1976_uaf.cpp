// 문제 : 1976
//       https://www.acmicpc.net/problem/1976
// 시간 복잡도 : ??
// 알고리즘 : union and find
// 풀이 방향 : union and find 알고리즘 이해 필수
//

#include <iostream>
using namespace std;

int unf[201];

int Find(int v)
{
    if (unf[v] == v)
        return v;
    else
        return unf[v] = Find(unf[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
        unf[a] = b;
}

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        unf[i] = i; // union and find 배열 초기화
    }

    int a, b;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> a;
            if (a == 1)
            {
                Union(i, j); // Disjoint-set 생성
            }
        }

    cin >> a;
    a = Find(a);
    for (int i = 1; i < M; i++)
    {
        cin >> b;
        b = Find(b);
        if (a != b)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}