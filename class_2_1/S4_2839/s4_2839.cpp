// 문제 : 2839 설탕 배달
// 시간 복잡도 : O(N)
// 알고리즘 : DP
// 초기조건 : dp[3] = dp[5] = 1;
// 점화식 : min(dp[i-3]+1, dp[i-5]+1)

#include <iostream>
using namespace std;

int dp[5001];

int main()
{
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    dp[3] = dp[5] = 1;
    for (int i = 6; i <= n; i++)
    {
        if (dp[i - 3])
        {
            dp[i] = dp[i - 3] + 1;
        }

        if (dp[i - 5])
        {
            dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
        }
    }
    cout << (dp[n] == 0 ? -1 : dp[n]);

    return 0;
}