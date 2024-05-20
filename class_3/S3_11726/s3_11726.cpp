// 문제 : 11726 2xn 타일링
//       https://www.acmicpc.net/problem/11726
// 시간 복잡도 : O()
// 알고리즘 : DP
// 풀이 방향 :
//   1. 2xn 크기의 직사각형이라는 조건이 있어 아래의 점화식을 세울 수 있다.
//   2. 1x2 막대와 2x1 타일로 2xn 의 직사각형을 채우는 초기 조건은 dp[1]=1, dp[2]=2이다
//   3.1 dp[3]을 구할때는 타일 1개를 고정시켜 놓고 나머지 2개로 만들수 있는 경우의 수 dp[2]와
//   3.2 타일 2개를 고정시켜 놓고 나머지 1개로 만들수 있는 경우의 수는 dp[1]의 합과  같다
//   4. 이를 일반화 시키면 dp[n] = dp[n-1] + dp[n-2]

#include <iostream>
using namespace std;

int dp[1001];

int main()
{
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n];

    return 0;
}
