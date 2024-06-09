// 문제 : 1874
//       https://www.acmicpc.net/problem/1874
// 시간 복잡도 :
// 알고리즘 : 자료구조 (stack)
// 풀이 방향 : 문제 이해 필요

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int n;
    stack<int> S;
    vector<char> res;
    cin >> n;

    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        int num;

        cin >> num;
        while (cnt <= num)
        {
            S.push(cnt);
            cnt++;
            res.push_back('+');
        }

        if (S.top() == num)
        {
            res.push_back('-');
            S.pop();
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}