// 문제 : 18870
//       https://www.acmicpc.net/problem/18870
// 시간 복잡도 : O (NlogN)
// 알고리즘 :
// 풀이 방향 : lower_bound(), unique(), erase() stl 사용하여 문제 풀이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;
    vector<int> v;

    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    vector<int> v_origin(v);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); // 원소 중복 제거

    vector<int> result;

    for (int i = 0; i < v_origin.size(); i++)
    {
        result.push_back(lower_bound(v.begin(), v.end(), v_origin[i]) - v.begin());
    }

    for (auto x : result)
    {
        cout << x << ' ';
    }

    return 0;
}