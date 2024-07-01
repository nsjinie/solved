// 문제 : 9461 파도반 수열
//       https://www.acmicpc.net/problem/9461
// 시간 복잡도 : O(1)
// 알고리즘 : DP
// 풀이 방향 :
//     1. 수열을 나열하고 규칙(점화식)을 찾는다.
//     2. overflow가 없도록 적절한 자료형을 선언한다.
// 초기조건 : dp[1]=dp[2]=dp[3]=1
// 점화식 : dp[i] = dp[i - 2] + dp[i - 3] (i>=4)

#include <iostream>
using namespace std;

long long dp[101];

int main()
{
    freopen("input.txt", "rt", stdin);

    dp[1] = dp[2] = dp[3] = 1;

    for (int i = 4; i <= 100; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
        // cout << dp[i] << '\n';
    }

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}