// 문제 : 2630 색종이 만들기
//        https://www.acmicpc.net/problem/2630
// 시간 복잡도 :
// 알고리즘 : 분할정복, 재귀
// 풀이 방향 : n * n 을 순회 하며 첫번째 컬러와 같지 않은 값이 나오면 n/2 로 줄여 재귀 호출

#include <iostream>

using namespace std;

int N;
int map[129][129];
int w_cnt = 0;
int b_cnt = 0;

void dq(int x, int y, int n)
{
    int firstColor = map[y][x];
    bool isDivide = false;

    for (int i = y; i < y + n; i++)
        for (int j = x; j < x + n; j++)
        {
            if (map[i][j] != firstColor)
            {
                isDivide = true;
                break;
            }
        }

    if (isDivide == true)
    {
        dq(x, y, n / 2);
        dq(x + (n / 2), y, n / 2);
        dq(x, y + (n / 2), n / 2);
        dq(x + (n / 2), y + (n / 2), n / 2);
    }
    else
    {
        if (firstColor == 1)
        {
            b_cnt++;
        }
        else
        {
            w_cnt++;
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }

    dq(0, 0, N);

    cout << w_cnt << '\n';
    cout << b_cnt << '\n';

    return 0;
}