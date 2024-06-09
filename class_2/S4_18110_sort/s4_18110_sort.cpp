// 문제 : 18110
//       https://www.acmicpc.net/problem/18110
// 시간 복잡도 : O(N)
// 알고리즘 : sort
// 풀이 방향 : sorting 후 절사평균 구현, 반올림 함수 사용, 암묵적 형변환 주의, n==0일때 예외처리

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int arr[300005];

    int n;

    cin >> n;

    if (n == 0)
    {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int a = round(n * 0.15);

    float sum = 0;
    for (int i = a; i < n - a; i++)
    {
        sum += arr[i];
    }

    cout << round(sum / (n - 2 * a));

    return 0;
}