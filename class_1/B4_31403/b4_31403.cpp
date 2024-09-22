// 문제 : 31403 A + B - C
//        https://www.acmicpc.net/problem/31403
// 시간 복잡도 :
// 알고리즘 :
// 풀이 방향 : stoi stl 사용

#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    string a, b, c;

    cin >> a >> b >> c;

    string ab = a + b;

    cout << stoi(a) + stoi(b) - stoi(c) << '\n';
    cout << stoi(ab) - stoi(c) << '\n';

    return 0;
}