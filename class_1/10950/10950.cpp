#include <iostream>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}