// 문제 : 11651 좌표 정렬하기2
//       https://www.acmicpc.net/problem/11651
// 시간 복잡도 : O(nlogn)   -> sort 함수 시간 복잡도
// 알고리즘 : 정렬
// 풀이 방향 : 구조체 정렬 구현

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos
{
    int x;
    int y;
    Pos(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    bool operator<(const Pos &b) const
    {
        if (y == b.y)
        {
            return x < b.x;
        }
        return y < b.y;
    }
};

int main()
{
    freopen("input.txt", "rt", stdin);

    int n, x, y;
    vector<Pos> arr;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        arr.push_back(Pos(x, y));
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].x << " " << arr[i].y << '\n';
    }

    return 0;
}