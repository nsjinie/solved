// 문제 : 11727 2×n 타일링 2
//       https://www.acmicpc.net/problem/11727
// 풀이 결과 : [2]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       https://ongveloper.tistory.com/247
// 시간 복잡도 : O(N)
// 알고리즘 : dp
// 풀이 방향 :
//    1. dp[3] 은
//       dp[2]에 2x1 하나 더하는 것과
//       dp[1]에 2x2를 더하는 것, 그리고 1x2 2개 더하는 방법 총 3가지가 있다
//    2. 점화식 : dp[n] = dp[n-1]+dp[n-2]+dp[n-2]

#include <iostream>

using namespace std;

int dp[10001];

int main()
{
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }

    cout << dp[n];

    return 0;
}
