// 시간복잡도 : O(1)

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    double a, b, v;
    cin >> a >> b >> v;

    /*
    int result = 1, tmp = 0;
    while (true)
    {
        tmp += a;
        if (tmp >= v)
            break;

        tmp -= b;
        result++;
    }*/

    int result = ceil((v - b) / (a - b));

    cout << result;
    return 0;
}