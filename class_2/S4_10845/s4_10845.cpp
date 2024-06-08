// 문제 : 10845
//       https://www.acmicpc.net/problem/10845
// 시간 복잡도 : O(N)
// 알고리즘 : 큐
// 풀이 방향 : 큐 사용법 연습, atoi()를 사용하여 string을 int로 바꾸는 기법

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int n;
    string str;

    queue<int> Q;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push")
        {
            cin >> str;
            Q.push(atoi(str.c_str()));
        }
        else if (str == "pop")
        {
            if (Q.empty())
                cout << "-1" << '\n';
            else
            {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if (str == "size")
        {
            cout << Q.size() << '\n';
        }
        else if (str == "empty")
        {
            if (Q.empty())
                cout << "1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (str == "front")
        {
            if (Q.empty())
                cout << "-1" << '\n';
            else
                cout << Q.front() << '\n';
        }
        else if (str == "back")
        {
            if (Q.empty())
                cout << "-1" << '\n';
            else
                cout << Q.back() << '\n';
        }
    }

    return 0;
}