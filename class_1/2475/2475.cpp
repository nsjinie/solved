#include <iostream>

using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int n;
    int squareSum = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        squareSum += n * n;
    }
    cout << squareSum % 10;
    return 0;
}
