// 문제 : 1764
//       https://www.acmicpc.net/problem/1764
// 시간 복잡도 : O(nlogn)
// 알고리즘 : Map
// 풀이 방향 : 사람이름을 key, 듣거나 보거나 1씩 증가, Map은 자동 정렬됨.

#include <iostream>
#include <map>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    map<string, int> Map;
    int N, M;
    cin >> N >> M;

    string a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        Map[a]++;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> a;
        Map[a]++;
    }

    int cnt = 0;

    for (auto name : Map)
    {
        if (name.second > 1)
            cnt++;
    }
    cout << cnt << '\n';

    for (auto name : Map)
    {
        if (name.second > 1)
            cout << name.first << '\n';
    }

    return 0;
}