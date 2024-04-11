#include <iostream>
using namespace std;

int cnt[10];
int main()
{
    // freopen("input.txt", "rt", stdin);
    int a, b, c, pos;
    long int d;
    cin >> a >> b >> c;
    d = a * b * c;
    do
    {
        pos = d % 10;
        cnt[pos]++;
        d = d / 10;
    } while (d != 0);

    for (int i = 0; i < 10; i++)
    {
        cout << cnt[i] << endl;
    }
    return 0;
}