// 문제 : 11723
//       https://www.acmicpc.net/problem/11723
// 시간 복잡도 : O(M)
// 알고리즘 : 구현
// 풀이 방향 : 문제를 읽고 단순 구현

#include <iostream>
using namespace std;

int arr[21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);
    int M;
    cin >> M;

    string op;
    int a;

    for (int i = 0; i < M; i++)
    {
        cin >> op;
        if (op != "all" && op != "empty")
            cin >> a;

        if (op == "add")
        {
            arr[a] = 1;
        }
        else if (op == "remove")
        {
            arr[a] = 0;
        }
        else if (op == "check")
        {
            if (arr[a] == 1)
                cout << "1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (op == "toggle")
        {
            if (arr[a] == 1)
                arr[a] = 0;
            else
                arr[a] = 1;
        }
        else if (op == "all")
        {
            for (int j = 1; j <= 20; j++)
                arr[j] = 1;
        }
        else if (op == "empty")
        {
            for (int j = 1; j <= 20; j++)
                arr[j] = 0;
        }
    }

    return 0;
}