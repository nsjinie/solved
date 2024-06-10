// 문제 : 1620
//       https://www.acmicpc.net/problem/1620
// 시간 복잡도 : O(M)
// 알고리즘 : 자료구조(해시)
// 풀이 방향 : 해시를 이용하여 데이터 관리

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

    unordered_map<int, string> Hno;
    unordered_map<string, int> Hname;

    string name;
    for (int i = 1; i <= N; i++)
    {
        cin >> name;
        Hno[i] = name;
        Hname[name] = i;
    }

    int no;
    for (int i = 0; i < M; i++)
    {
        cin >> name;
        no = atoi(name.c_str());
        if (no != 0)
            cout << Hno[no] << '\n';
        else
            cout << Hname[name] << '\n';
    }

    return 0;
}