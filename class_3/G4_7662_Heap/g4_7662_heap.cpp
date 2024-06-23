// 문제 : 7662
//       https://www.acmicpc.net/problem/7662
// 시간 복잡도 : 삽입 O(log n) 제거 O(log n) 최상위 요소 확인 O(1)
// 알고리즘 : heap
// 풀이 방향 :
//              최대 최소 priority_queue 각각 사용
//              삭제된 값인지 판단하기 위해 연산의 개수 순서값을 인덱스로 사용하는 check배열 사용

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int T, k;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> k;

        priority_queue<pair<int, int>> pQmax;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQmin;
        vector<int> check(k);

        char cmd;
        int n, a;

        for (int j = 0; j < k; j++)
        {
            cin >> cmd >> n;

            if (cmd == 'I')
            {
                pQmax.push(make_pair(n, j));
                pQmin.push(make_pair(n, j));
                check[j] = 1;
            }
            else if (cmd == 'D')
            {
                if (n == 1)
                {
                    while (!pQmax.empty())
                    {
                        a = pQmax.top().second;

                        if (check[a] == 1)
                        {
                            check[a] = 0;
                            pQmax.pop();
                            break;
                        }
                        pQmax.pop();
                    }
                }

                else if (n == -1)
                {
                    while (!pQmin.empty())
                    {
                        a = pQmin.top().second;
                        if (check[a] == 1)
                        {
                            check[a] = 0;
                            pQmin.pop();
                            break;
                        }
                        pQmin.pop();
                    }
                }
            }
        }

        while (!pQmax.empty())
        {
            a = pQmax.top().second;
            if (check[a] == 1)
                break;
            pQmax.pop();
        }

        while (!pQmin.empty())
        {
            a = pQmin.top().second;
            if (check[a] == 1)
                break;
            pQmin.pop();
        }

        if (pQmax.empty() && pQmin.empty())
            cout << "EMPTY" << '\n';
        else
            cout << pQmax.top().first << " " << pQmin.top().first << '\n';
    }

    return 0;
}