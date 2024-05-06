// 시간복잡도 : O(NlogN)??
// 알고리즘 : 수학

#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;

    int two = 0, five = 0;

    int tmp;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0 || i % 5 == 0)
        {
            tmp = i;

            while (tmp % 2 == 0)
            {
                tmp = tmp / 2;
                two++;
            }
            while (tmp % 5 == 0)
            {
                tmp = tmp / 5;
                five++;
            }
        }
    }
    int result = min(two, five);
    cout << result;

    return 0;
}
