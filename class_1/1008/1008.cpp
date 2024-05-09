#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    double a, b;
    cin >> a >> b;
    cout.precision(10);
    cout << a / b;
    return 0;
}
