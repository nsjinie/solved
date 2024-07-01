// 문제 : 9375
//       https://www.acmicpc.net/problem/9375
// 시간 복잡도 :
// 알고리즘 : map, 경우의수(조합)
// 풀이 방향 : map loop 돌리는 문법 숙지

#include <iostream>
#include <map>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        map<string, int> M;
        cin >> N;

        string a, b;
        for (int j = 0; j < N; j++)
        {
            cin >> a >> b;
            M[b]++;
        }

        int res = 1;
        for (auto itr = M.begin(); itr != M.end(); itr++)
        {
            res *= itr->second + 1;
        }
        res -= 1;
        cout << res << '\n';
    }

    return 0;
}
