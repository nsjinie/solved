// 문제 : 1003 피보나치 함수
// 시간 복잡도 : O(N)
// 알고리즘 : DP
// 초기조건 :dp[0] = pair(1, 0) / dp[1] = pair(0, 1);
// 점화식 : dp[n] = dp[n-1] + dp[n-2]

#include <iostream>
using namespace std;

pair<int, int> dp[41];

int main()
{
    freopen("input.txt", "rt", stdin);

    dp[0] = pair(1, 0);
    dp[1] = pair(0, 1);

    for (int i = 2; i <= 40; i++)
    {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }

    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp[n].first << ' ' << dp[n].second << '\n';
    }

    return 0;
}
