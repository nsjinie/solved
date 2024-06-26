// 문제 : 17219
//       https://www.acmicpc.net/problem/17219
// 시간 복잡도 :
// 알고리즘 : hash
// 풀이 방향 : -

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> H;

    string a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        H[a] = b;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a;

        cout << H[a] << '\n';
    }

    return 0;
}