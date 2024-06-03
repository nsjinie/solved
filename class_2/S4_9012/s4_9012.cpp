// 문제 : 9012 괄호
//       https://www.acmicpc.net/problem/9012
// 시간 복잡도 : O()
// 알고리즘 : 자료구조, Stack
// 풀이 방향 :

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        stack<char> S;
        string str;

        cin >> str;
        char c;
        bool isYes = true;

        for (int j = 0; j < str.size(); j++)
        {
            c = str[j];
            if (c == '(')
            {
                S.push(c);
            }
            else if (c == ')')
            {
                if (!S.empty() && S.top() == '(')
                {
                    S.pop();
                }
                else
                {
                    isYes = false;
                    break;
                }
            }
        }
        if (S.empty() && isYes == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}