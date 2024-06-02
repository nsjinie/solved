// 문제 : 4949 균형잡힌 세상
//       https://www.acmicpc.net/problem/4949
// 시간 복잡도 : O(??)
// 알고리즘 : 스택
// 풀이 방향 : 문제에서 주어진 로직 구현, Stack 값 조사 전 empty인지 확인하기
//             getline() 함수로 라인단위로 읽어들이기

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    while (true)
    {
        string str;
        getline(cin, str);

        if (str == ".")
            return 0;

        stack<char> S;
        char c;
        bool isYes = true;

        for (int i = 0; i < str.size(); i++)
        {
            c = str[i];
            if (c == '(' || c == '[')
                S.push(c);
            else if (c == ')')
            {
                if (!S.empty() && S.top() == '(')
                    S.pop();
                else
                {
                    isYes = false;
                    break;
                }
            }
            else if (c == ']')
            {
                if (!S.empty() && S.top() == '[')
                    S.pop();
                else
                {
                    isYes = false;
                    break;
                }
            }
        }
        if (isYes && S.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}