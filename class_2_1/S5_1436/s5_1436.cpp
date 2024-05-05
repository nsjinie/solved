// 시간 복잡도 : O(N^2) ??
// 브루트포스 알고리즘

#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;

    int title = 666;
    int result = 1;

    while (result != n)
    {
        title++;
        int tmp = title;
        while (tmp >= 666)
        {
            if (tmp % 1000 == 666)
            {
                result++;
                break;
            }
            tmp /= 10;
        }
    }
    cout << title;

    return 0;
}