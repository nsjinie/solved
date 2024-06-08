// 문제 : 10828
//       https://www.acmicpc.net/problem/10828
// 시간 복잡도 : O(N)
// 알고리즘 : 스택
// 풀이 방향 : 스택 사용법 연습, atoi()를 사용하여 string을 int로 바꾸는 기법

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    stack<int> S;
    string str;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;

        if (str == "push")
        {
            cin >> str;
            S.push(atoi(str.c_str()));
        }
        else if (str == "pop")
        {
            if (S.empty())
                cout << "-1" << '\n';
            else
            {
                cout << S.top() << '\n';
                S.pop();
            }
        }
        else if (str == "size")
        {
            cout << S.size() << '\n';
        }
        else if (str == "empty")
        {
            if (S.empty())
                cout << "1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (str == "top")
        {
            if (S.empty())
                cout << "-1" << '\n';
            else
                cout << S.top() << '\n';
        }
    }

    return 0;
}