// 문제 : 2108
//       https://www.acmicpc.net/problem/2108
// 시간 복잡도 : 정렬 O(NlogN), map O(NlogN)
// 알고리즘 : 정렬, 자료구조(hash)
// 풀이 방향 : map 자료구조는 key 값을 오름차순 정렬을 해줌. 최빈값 중 두번째로 작은 값 찾을 때 이용.
//            평균 최종 출력 시 정수형으로 변환

#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{

    freopen("input.txt", "rt", stdin);
    int N, sum = 0;
    int arr[500001];

    map<int, int> H;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        H[arr[i]]++;
    }

    cout << (int)round((double)sum / N) << '\n'; // 평균

    sort(arr, arr + N);

    cout << arr[N / 2] << '\n'; // 중앙값

    bool isSecond = false;
    int max = 0;
    int maxKey = -5000;
    for (auto item : H)
    {
        if (max < item.second)
        {
            max = item.second;
            maxKey = item.first;
            isSecond = false;
        }
        else if (isSecond == false && max == item.second)
        {
            isSecond = true;
            maxKey = item.first;
        }
    }
    cout << maxKey << '\n';

    cout << arr[N - 1] - arr[0] << '\n';

    return 0;
}