// 문제 : 5430 AC
//       https://www.acmicpc.net/problem/5430
// 풀이 결과 : [2]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       https://ohsol.tistory.com/entry/%EB%B0%B1%EC%A4%80-5430%EB%B2%88-AC-C-%ED%92%80%EC%9D%B4
// 시간 복잡도 : O(??)
// 알고리즘 : 자료구조(Deque)
// 풀이 방향 :
//    1. 문자열 파싱 후 숫자들을 Deque에 넣고 dir flag 변수 기준으로 deque 앞or뒤에서 값을 pop

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int T, n;
    string p, nStr;

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> p >> n >> nStr;

        deque<int> dq;
        string tmp = "";
        for (int i = 1; i < nStr.size(); i++)
        {
            if (nStr[i] == ',' || nStr[i] == ']')
            {
                if (tmp != "")
                {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
            else
            {
                tmp += nStr[i];
            }
        }

        bool forward = true;
        bool err = false;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R')
            {
                forward = !forward;
            }
            else if (p[i] == 'D')
            {
                if (dq.empty())
                {
                    err = true;
                    break;
                }
                else if (forward == true)
                {
                    dq.pop_front();
                }
                else if (forward == false)
                {
                    dq.pop_back();
                }
            }
        }

        if (err)
        {
            cout << "error" << '\n';
        }
        else
        {
            cout << "[";
            if (forward == true)
            {
                for (int i = 0; i < dq.size(); i++)
                {
                    if (i == dq.size() - 1)
                        cout << dq[i];
                    else
                        cout << dq[i] << ",";
                }
            }
            else
            {
                for (int i = dq.size() - 1; i >= 0; i--)
                {
                    if (i == 0)
                        cout << dq[i];
                    else
                        cout << dq[i] << ",";
                }
            }
            cout << "]" << '\n';
        }
    }

    return 0;
}