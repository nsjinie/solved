// 문제 : 1463 1로 만들기
// 시간 복잡도 : O(n)
// 알고리즘 : DP
// 초기조건 : dp[1] = 0
// 점화식 : min(dp[i-1], dp[i/2], i[i/3])+1  단 i%2 == 0, i%3 == 0 일때

#include <iostream>
using namespace std;

int dp[1000001];

int main()
{
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;

    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[n];

    return 0;
}