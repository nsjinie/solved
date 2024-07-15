// 문제 : 9019 DSLR
//       https://www.acmicpc.net/problem/9019
// 시간 복잡도 : O()
// 알고리즘 : BFS
// 풀이 방향 : 최종값과 일치할때까지 DSLR 명령을 BFS로 순회한다.

#include <iostream>
#include <queue>
using namespace std;

int T, A, B;

char cmd[4] = {'D', 'S', 'L', 'R'};
int result;
int check[10001];

void checkClear()
{
    for (int i = 0; i < 10001; i++)
    {
        check[i] = 0;
    }
}

int calc(int num, char c)
{
    int rtn;
    switch (c)
    {
    case 'D':
        rtn = (2 * num) % 10000;
        break;
    case 'S':
        if (num == 0)
            rtn = 9999;
        else
            rtn = num - 1;
        break;
    case 'L':
        rtn = ((num % 1000) * 10) + (num / 1000);
        break;
    case 'R':
        rtn = ((num % 10) * 1000) + (num / 10);
        break;
    }

    return rtn;
}

void BFS(int num)
{
    result = 0;
    queue<pair<int, string>> Q;
    Q.push({num, ""});
    check[num] = 1;

    while (!Q.empty())
    {
        int nowNum = Q.front().first;
        string nowCmd = Q.front().second;

        Q.pop();

        if (nowNum == B)
        {
            cout << nowCmd << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextnum = calc(nowNum, cmd[i]);
            if (check[nextnum] != 1)
            {
                check[nextnum] = 1;
                Q.push({nextnum, nowCmd + cmd[i]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        BFS(A);
        checkClear();
    }

    return 0;
}