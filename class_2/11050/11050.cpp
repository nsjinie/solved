// 이항계수 nCk = n-1Ck + n-1Ck-1
// 메모이제이션 처리
// 시간복잡도 : ??

#include <iostream>
using namespace std;

int dy[11][11];

int DFS(int n, int k)
{
    if (dy[n][k] != 0)
        return dy[n][k];
    if (k == 0 || n == k)
        return 1;

    return dy[n][k] = DFS(n - 1, k) + DFS(n - 1, k - 1);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    int n, k;
    cin >> n >> k;

    int res = DFS(n, k);
    cout << res;

    return 0;
}