// 문제 : 1929
//       https://www.acmicpc.net/problem/1929
// 시간 복잡도 : O()
// 알고리즘 : 그리디
// 풀이 방향 : 2부터 배수 제거

#include <iostream>
using namespace std;

int arr[1000001];
int main()
{
    freopen("input.txt", "rt", stdin);

    int start, end;
    cin >> start >> end;

    for (int i = 2; i <= end; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i <= end; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        for (int j = i + i; j <= end; j += i)
        {
            arr[j] = 0;
        }
    }

    for (int i = start; i <= end; i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << '\n';
    }

    return 0;
}