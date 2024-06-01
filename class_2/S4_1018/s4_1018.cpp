// 문제 : 1018 체스판 다시 칠하기
//       https://www.acmicpc.net/problem/1018
// 시간 복잡도 : O(NM)
// 알고리즘 : 브루트포스
// 풀이 방향 : 8X8 슬라이딩 윈도우, 좌측 상단이 W, B로 시작하는 경우 고려

#include <iostream>
using namespace std;

string arr[51];

int main()
{
    freopen("input.txt", "rt", stdin);

    int m, n;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt_w, cnt_b, res_tmp;
    int res = 1000;
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            cnt_w = 0;
            cnt_b = 0;
            for (int ln = 0; ln < 8; ln++)
                for (int lm = 0; lm < 8; lm++)
                {
                    if ((ln + lm) % 2 == 0 && arr[i + ln][j + lm] != 'W')
                    {
                        cnt_w++;
                    }
                    else if ((ln + lm) % 2 == 1 && arr[i + ln][j + lm] != 'B')
                    {
                        cnt_w++;
                    }
                    else if ((ln + lm) % 2 == 0 && arr[i + ln][j + lm] != 'B')
                    {
                        cnt_b++;
                    }
                    else if ((ln + lm) % 2 == 1 && arr[i + ln][j + lm] != 'W')
                    {
                        cnt_b++;
                    }
                }

            res_tmp = min(cnt_w, cnt_b);
            res = min(res, res_tmp);
        }
    }

    cout << res;

    return 0;
}
