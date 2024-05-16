// 문제 : 9095 1,2,3 더하기
//       https://www.acmicpc.net/problem/9095
// 시간 복잡도 : O(1)
// 알고리즘 : DP
// 초기조건 : dp[1] = 1;
//           dp[2] = 2;
//           dp[3] = 4;
// 점화식 : dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]

#include <iostream>
using namespace std;

int dp[12];
int main()
{
    freopen("input.txt", "rt", stdin);

    int t, n;
    cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}