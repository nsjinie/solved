// 문제 : 6064 카잉 달력
//       https://www.acmicpc.net/problem/6064
// 풀이 결과 : [2]    (1 : 직접 풀이,  2 : 풀이 방향 참조, 3 : 풀이 방향/구현 모두 참조)
//       https://hagisilecoding.tistory.com/115
// 시간 복잡도 : O(lcm(N,M)/M)
// 알고리즘 : 수학
// 풀이 방향 :
//    1. 문제를 이해하는데 시간이 걸렸음 (달력의 증가 규칙이 쉽게 이해가지 않았음)
//    2. 마지막 해 : 최소 공배수
//    3. 최대공약수, 최소공배수 구현 필요
//    4. x 값의 경우의 수를 구하고 각각에 대해 y값이 일치하는 값이 있는지 확인하는 로직 구현

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    // cout << a << " / " << b << '\n';
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;

    int N, M, x, y;

    for (int i = 0; i < T; i++)
    {

        cin >> M >> N >> x >> y;

        int lastDay = lcm(M, N);

        int x1 = x;
        int res = -1;
        while (x1 <= lastDay)
        {
            // cout << x1 << '\n';
            int y1 = x1 % N;
            if (y1 == 0)
            {
                y1 = N;
            }

            if (y1 == y)
            {
                res = x1;
                break;
            }
            // cout << x1 << " / " << y1 << '\n';
            x1 = x1 + M;
        }

        cout << res << '\n';
    }

    return 0;
}