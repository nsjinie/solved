// 문제 : 17626 Four Squares
//       https://www.acmicpc.net/problem/17626
// 시간 복잡도 : O(n2)
// 알고리즘 : DP
// 풀이 방향 : dp[i-j^2] 이 최소가 되는 값을 찾는다

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dp[50001];

int main()
{
    int n;
    freopen("input.txt", "rt", stdin);
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int minn = INT_MAX;
        for (int j = 1; j * j <= i; j++)
        {
            int tmp = i - (j * j);
            minn = min(minn, dp[tmp]);
        }
        dp[i] = minn + 1;
    }
    cout << dp[n];

    return 0;
}