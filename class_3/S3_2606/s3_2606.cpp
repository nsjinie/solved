// 문제 : 2606
//       https://www.acmicpc.net/problem/2606
// 시간 복잡도 :
// 알고리즘 : Union & Find
// 풀이 방향 : Disjoint set 찾는 문제

#include <iostream>
using namespace std;

int unf[101];

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

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        unf[i] = i;
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Union(a, b);
    }

    int v = Find(1);
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (Find(i) == v)
            cnt++;
    }

    cout << cnt;

    return 0;
}