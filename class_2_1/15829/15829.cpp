#include <iostream>
#define M 1234567891
#define r 31
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    string str;
    int n;
    cin >> n >> str;

    long long hash = 0, R = 1;

    for (int i = 0; i < n; i++)
    {
        hash += ((str[i] - 'a' + 1) * R) % M;
        hash %= M;
        R = (R * r) % M;
    }
    cout << hash;

    return 0;
}