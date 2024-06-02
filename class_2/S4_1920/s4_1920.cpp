// 문제 : 1920 수 찾기
//       https://www.acmicpc.net/problem/1920
// 시간 복잡도 : O(nlogn logn)
// 알고리즘 :
// 풀이 방향 : 정렬(nlogn) 후 이분검색(logn)
//             ios_base 추가 잊지 말것

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int N, M;

int findNumber(int num)
{
    int lt = 0, rt = N - 1;
    int mid;
    while (lt <= rt)
    {
        mid = (lt + rt) / 2;
        if (arr[mid] == num)
        {
            return 1;
        }
        else if (arr[mid] > num)
        {
            rt = mid - 1;
        }
        else if (arr[mid] < num)
        {
            lt = mid + 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);
    int tmp;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        cout << findNumber(tmp) << '\n';
    }

    return 0;
}