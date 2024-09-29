// 문제 : 18111
//       https://www.acmicpc.net/problem/18111
// 시간 복잡도 :
// 알고리즘 : 브루트포스
// 풀이 방향 :
// 1 <= i, j <= 500, 높이가 256을 초과할 수 없음
// 전수조사 연산 수 500*500*257 = 64,250,000  <- 연산이 10억회 이하면 1초 이내 풀이 가능
// 시간이 같다면 땅이 높이가 가장 높은 것을 출력 <-- 실수한 부분

#include <iostream>
#include <climits>

using namespace std;

int arr[501][501];

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, M, B;

    cin >> N >> M >> B;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }

    int ans_t = INT_MAX;
    int ans_h;
    for (int h = 0; h <= 256; h++)
    {
        int build = 0;
        int remove = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                int height = arr[i][j] - h;
                if (height > 0)
                {
                    remove += height;
                }
                else
                {
                    build -= height;
                }
            }

        if (remove + B >= build) // 쌓아야 하는 블록 수가 확보할 수 있는 블록 수보다 작을때만 유효함
        {
            int t = (remove * 2) + build;
            if (t <= ans_t)
            {
                ans_t = t;
                ans_h = h;
            }
        }
    }
    cout << ans_t << " " << ans_h;
    return 0;
}